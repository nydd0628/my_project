/* 头文件引入 */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
/* 定义常量 */
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
/* 类型定义*/
typedef int status; 
typedef int ElemType; //数据元素类型定义

/* 顺序表定义 */
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct{  //顺序表（顺序结构）的定义
	ElemType * elem;
	int length;
	int listsize;
}SqList;

typedef struct{  //线性表的集合类型定义
     struct { char name[30];
               SqList L;    
     } elem[10];
     int length;
}LISTS;
/* 函数声明 */
status InitList(SqList& L);
status DestroyList(SqList& L);
status ClearList(SqList&L);
status ListEmpty(SqList L);
int ListLength(SqList L);
status GetElem(SqList L,int i,ElemType &e);
status LocateElem(SqList L,ElemType e); 
status PriorElem(SqList L,ElemType e,ElemType &pre);
status NextElem(SqList L,ElemType e,ElemType &next);
status ListInsert(SqList &L,int i,ElemType e);
status ListDelete(SqList &L,int i,ElemType &e);
status ListTraverse(SqList L);
ElemType MaxSubArray(SqList &L);
int SubArrayNum(SqList &L,ElemType k);
int compare(const void *e1 , const void *e2);
status sortList(SqList &L);
status  SaveList(SqList L,char FileName[]);
status  LoadList(SqList &L,char FileName[]);
status AddList(LISTS &Lists,char ListName[]);
status RemoveList(LISTS &Lists,char ListName[]);
int LocateList(LISTS Lists,char ListName[]);
/*--------------------------------------------*/
int main(){ 
    //模式确认 
    int mode;
    printf("请选择模式\n");
    printf("1.多表   2.单表\n");
    scanf("%d",&mode);
    //声明代管理的对象 
    LISTS Lists;
    Lists.length = 0;
    SqList List;
    List.elem = NULL; 
    
    int op=1;
    //可能用到的变量声明 
    int i,b,k;
    int e;
    int index;
    int pre,next,position;
    char listname[30];
    char filename[100];
    if(mode == 1){
while(op){
	//多表操作 
	system("cls");	
    printf("\n\n");
	printf("      Menu for Linear Table On Sequence Structure \n");
	printf("-------------------------------------------------\n");
	printf("      1. AddList       10. LocateElem\n");
	printf("      2. RemoveList    11. PriorElem\n");
	printf("      3. ClearList     12. NextElem \n");
	printf("      4. ListEmpty     13. ListInsert\n");
	printf("      5. ListLength    14. ListDelete\n");
	printf("      6. GetElem       15. ListTrabverse\n");
    printf("      7. MaxSubArray   16. SubArrayNum\n");
    printf("      8. sortList      17. SaveList\n");
    printf("      9. LoadList      18. LocateList\n");
	printf("      0. Exit\n");
	printf("-------------------------------------------------\n");
	printf("    请选择你的操作[0~18]:");
	scanf("%d",&op);
    switch(op){
	   case 1:
         printf("输入列表名\n");
         scanf("%s",listname);
         
		 if(AddList(Lists,listname) == OK) printf("线性表创建成功！\n");
		 else printf("线性表创建失败！\n");
	     getchar();getchar();
		 break;
	   case 2:
         printf("输入列表名\n");
         scanf("%s",listname);
         
		 if(RemoveList(Lists,listname) == OK) printf("移除成功\n");
         else printf("移除失败\n");     
		 getchar();getchar();
		 break;
	   case 3:
         printf("请输入列表名\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
		 if(ClearList(Lists.elem[i].L) == OK) printf("清除成功\n");
         else printf("清除失败\n");       
		 getchar();getchar();
		 break;
	   case 4:
		 printf("输入列表名\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
		 if(ListEmpty(Lists.elem[i].L) == TRUE) printf("是空表\n");
         else if(ListEmpty(Lists.elem[i].L) == FALSE) printf("不是空表\n"); 
		 else printf("无法进行判别\n");         
		 getchar();getchar();
		 break;
	   case 5:
		 printf("输入列表名\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
		 if(ListLength(Lists.elem[i].L)==INFEASIBLE) printf("未初始化\n");
         else printf("表长为：%d\n",ListLength(Lists.elem[i].L));
		 getchar();getchar();
		 break;
	   case 6:
		 printf("输入列表名\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
         printf("请输入索引号\n");
         scanf("%d",&index);
         
		 if(GetElem(Lists.elem[i].L,index,e) == OK) printf("获得元素为：%d\n",e);
         else printf("无法获得该元素\n");     
		 getchar();getchar();
		 break;
	   case 7:
		 printf("输入列表名\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
		 if(MaxSubArray(Lists.elem[i].L) != INFEASIBLE) printf("和最大的子数组的和为：%d\n",MaxSubArray(Lists.elem[i].L));
		 else printf("无法获得目标值\n");     
		 getchar();getchar();
		 break;
	   case 8:
		 printf("输入列表名\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
		 if(sortList(Lists.elem[i].L) == OK) printf("成功排序\n");
         else printf("无法排序\n");     
		 getchar();getchar();
		 break;
	   case 9:
		 printf("输入列表名\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
         printf("请输入文件名\n");
         scanf("%s",filename);
         
		 if(LoadList(Lists.elem[i].L , filename) == OK) printf("成功读取%s中的数据",filename);
         else printf("无法读取\n");    
		 getchar();getchar();
		 break;
	   case 10:
		 printf("输入列表名\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
         printf("请输入待查找的元素\n");
         scanf("%d",&e);
		 b = LocateElem(Lists.elem[i].L , e);
		 if(b == INFEASIBLE) printf("未初始化\n");
         else if(b == ERROR) printf("未找到该值\n");
		 else printf("编号为：%d\n",b);     
		 getchar();getchar();
		 break;
	   case 11:
		 printf("输入列表名\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
         printf("请输入待查找的元素\n");
         scanf("%d",&e);
		 b = PriorElem(Lists.elem[i].L, e, pre);
		 
		 if (b == INFEASIBLE) printf("未初始化\n");
		 else if (b == ERROR) printf("未找到前驱\n");
		 else printf("前驱为%d\n", pre);
		 getchar();getchar();
		 break;
	   case 12:
		 printf("输入列表名\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
         printf("请输入待查找的元素\n");
         scanf("%d",&e);
		 b = NextElem(Lists.elem[i].L, e, next);
		 
		 if (b == INFEASIBLE) printf("未初始化\n");
		 else if (b == ERROR) printf("未找到后继\n");
		 else printf("后继为%d\n", next);
		 getchar();getchar();
		 break;
       case 13:
		 printf("输入列表名\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
         printf("请输入插入位置\n");
         scanf("%d",&position);
         printf("请输入插入元素\n");
         scanf("%d",&e);
         
		 if(ListInsert(Lists.elem[i].L , position , e) == OK) printf("成功插入\n");
         else printf("插入失败\n");
		 getchar();getchar();
		 break;
       case 14:
		 printf("输入列表名\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
         printf("请输入删除位置\n");
         scanf("%d",&position);
         
		 if(ListDelete(Lists.elem[i].L , position , e) == OK) printf("成功删除%d\n",e);
         else printf("删除失败\n");
		 getchar();getchar();
		 break;
       case 15:
		 printf("输入列表名\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
		 if(ListTraverse(Lists.elem[i].L) == OK) printf("成功遍历\n");
         else printf("遍历失败\n");
		 getchar();getchar();
		 break;
       case 16:
		 printf("输入列表名\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
         printf("请输入待查找的和\n");
         scanf("%d",&k);
         
		 if(SubArrayNum(Lists.elem[i].L , k)) printf("查找到符合个数为:%d\n",SubArrayNum(Lists.elem[i].L , k));
         else printf("查找失败\n");
		 getchar();getchar();
		 break;
       case 17:
		 printf("输入列表名\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
         printf("请输入待读入的文件名\n");
         scanf("%s",filename);
         
		 if(SaveList(Lists.elem[i].L , filename) == OK) printf("成功保存\n");
         else printf("保存失败\n");
		 getchar();getchar();
		 break;
       case 18:
		 printf("输入列表名\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname);
         
		 if(i > 0) printf("查找到该表位置为:%d\n",i);
         else printf("查找失败\n");
		 getchar();getchar();
		 break;
	   case 0:
         break;
       default:
       	 printf("wromg order\n");
         break;	
	}//end of switch
  }//end of while
printf("欢迎下次再使用本系统！\n");
    }
else if(mode == 2){
    op = 1;
while(op){
	//单表操作 
	system("cls");	
    printf("\n\n");
	printf("      Menu for Linear Table On Sequence Structure \n");
	printf("-------------------------------------------------\n");
	printf("      1. InitList       10. LocateElem\n");
	printf("      2. DestoryList    11. PriorElem\n");
	printf("      3. ClearList      12. NextElem \n");
	printf("      4. ListEmpty      13. ListInsert\n");
	printf("      5. ListLength     14. ListDelete\n");
	printf("      6. GetElem        15. ListTrabverse\n");
    printf("      7. MaxSubArray    16. SubArrayNum\n");
    printf("      8. sortList       17. SaveList\n");
    printf("      9. LoadList\n");
	printf("      0. Exit\n");
	printf("-------------------------------------------------\n");
	printf("    请选择你的操作[0~17]:");
	scanf("%d",&op);
    switch(op){
	   case 1:
	     if(InitList(List) == OK) printf("线性表创建成功！\n");
	     else printf("线性表创建失败！\n");
	     getchar();getchar();
		 break;
	   case 2:
		 if(DestroyList(List) == OK) printf("销毁成功\n");
         else printf("销毁失败\n");     
		 getchar();getchar();
		 break;
	   case 3:
		 if(ClearList(List) == OK) printf("清除成功\n");
         else printf("清除失败\n");       
		 getchar();getchar();
		 break;
	   case 4:
		 if(ListEmpty(List) == TRUE) printf("是空表\n");
         else if(ListEmpty(List) == FALSE) printf("不是空表\n"); 
		 else printf("无法进行判别\n");           
		 getchar();getchar();
		 break;
	   case 5:
		 if(ListLength(List)==INFEASIBLE) printf("未初始化\n");
         else printf("表长为：%d\n",ListLength(List));
		 getchar();getchar();
		 break;
	   case 6:
         printf("请输入索引号\n");
         scanf("%d",&index);
         
		 if(GetElem(List,index,e) == OK) printf("获得元素为：%d\n",e);
         else printf("无法获得该元素\n");     
		 getchar();getchar();
		 break;
	   case 7:
		 if(MaxSubArray(List) != INFEASIBLE) printf("和最大的子数组的和为：%d\n",MaxSubArray(List));
         else printf("无法获得目标值\n");     
		 getchar();getchar();
		 break;
	   case 8:
		 if(sortList(List) == OK) printf("成功排序\n");
         else printf("无法排序\n");     
		 getchar();getchar();
		 break;
	   case 9:
         printf("请输入文件名\n");
         scanf("%s",filename);
		 if(LoadList(List , filename) == OK) printf("成功读取%s中的数据",filename);
         else printf("无法读取\n");    
		 getchar();getchar();
		 break;
	   case 10:
         printf("请输入待查找的元素\n");
         scanf("%d",&e);
         b = LocateElem(List , e);
         
		 if(b == INFEASIBLE) printf("未初始化\n");
         else if(b == ERROR) printf("未找到该值\n");
		 else printf("编号为：%d\n",b);     
		 getchar();getchar();
		 break;
	   case 11:
         printf("请输入待查找的元素\n");
         scanf("%d",&e);
		 b = PriorElem(List, e, pre);
		 
		 if (b == INFEASIBLE) printf("未初始化\n");
		 else if (b == ERROR) printf("未找到前驱\n");
		 else printf("前驱为%d\n", pre);
		 getchar();getchar();
		 break;
	   case 12:
         printf("请输入待查找的元素\n");
         scanf("%d",&e);
		 b = NextElem(List, e, next);
		 
		 if (b == INFEASIBLE) printf("未初始化\n");
		 else if (b == ERROR) printf("未找到后继\n");
		 else printf("后继为%d\n", next);
		 getchar();getchar();
		 break;
       case 13:
         printf("请输入插入位置\n");
         scanf("%d",&position);
         
         printf("请输入插入元素\n");
         scanf("%d",&e);
         
		 if(ListInsert(List , position , e) == OK) printf("成功插入\n");
         else printf("插入失败\n");
		 getchar();getchar();
		 break;
       case 14:
         printf("请输入删除位置\n");
         scanf("%d",&position);
		 if(ListDelete(List , position , e) == OK) printf("成功删除%d\n",e);
         else printf("删除失败\n");
		 getchar();getchar();
		 break;
       case 15:
		 if(ListTraverse(List) == OK) printf("成功遍历\n");
         else printf("遍历失败\n");
		 getchar();getchar();
		 break;
       case 16:
         printf("请输入待查找的和\n");
         scanf("%d",&k);
		 if(SubArrayNum(List , k)) printf("查找到符合个数为:%d\n",SubArrayNum(List , k));
         else printf("查找失败\n");
		 getchar();getchar();
		 break;
       case 17:
         printf("请输入待读入的文件名\n");
         scanf("%s",filename);
		 if(SaveList(List , filename) == OK) printf("成功保存\n");
         else printf("保存失败\n");
		 getchar();getchar();
		 break;
	   case 0:
         break; 
       default:
       	 printf("wromg order\n");
         break;	
	}//end of switch
  }//end of while
printf("欢迎下次再使用本系统！\n");
    }
else printf("wromg order\n");
}











status InitList(SqList& L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    //判断线性表是否为空，决定初始化是否进行
    if(L.elem)
    {
        printf("there are some elementaries in this list\n");
        return INFEASIBLE;
    }
    //分配空间
    L.elem = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    L.listsize = LIST_INIT_SIZE;
    L.length = 0;
    return OK;
}

status DestroyList(SqList& L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    //判断线性表是否初始化
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    //销毁操作
    ElemType *temp = L.elem;
    L.elem = NULL;
    free(temp);
    
    return OK;
}

status ClearList(SqList& L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    //判断线性表是否初始化
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    //清空操作
    L.length = 0;
    return OK;
}

status ListEmpty(SqList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    //判断线性表是否初始化
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    //判断是否为空表
    if(L.length) return FALSE;
    else return TRUE;

}

status ListLength(SqList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    //判断线性表是否初始化
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    //返回表长
    return L.length;
}

status GetElem(SqList L,int i,ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    //判断线性表是否初始化
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    //保证元素在表的范围内
    if(i < 1 || i > L.length) return ERROR;
    //获取第i个元素并赋值
    e = *(L.elem + i - 1);
    return OK;

}

int LocateElem(SqList L,ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号并返回该序号；如果e不存在，返回0；当线性表L不存在时，返回INFEASIBLE（即-1）。
{
    //判断线性表是否初始化
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    //寻找操作
    int index = 0;
    for(int i = 0 ; i < L.length ; i ++)
    {
        if(*(L.elem + i) == e)
        {
            //获取匹配值并退出
            index = i + 1;
            break;
        }

    }
    if(index) return index;
    else return ERROR;
}

status PriorElem(SqList L,ElemType e,ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    //判断线性表是否初始化
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    //寻找操作
    int index = 0;
    for(int i = 0 ; i < L.length ; i ++)
    {
        if(*(L.elem + i) == e)
        {
            //获取匹配值并退出
            index = i + 1;
            break;
        }
    }
    //返回前驱
    if(index > 1)
    {
        pre = *(L.elem + (index - 2));
        return OK;
    }
    else return ERROR;
}

status NextElem(SqList L,ElemType e,ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    //判断线性表是否初始化
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    //寻找操作
    int index = 0;
    for(int i = 0 ; i < L.length ; i ++)
    {
        if(*(L.elem + i) == e)
        {
            //获取匹配值并退出
            index = i + 1;
            break;
        }
    }
    //返回后继
    if(index > 0 && index < L.length)
    {
        next = *(L.elem + (index));
        return OK;
    }
    else return ERROR;

}

status ListInsert(SqList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    //判断线性表是否初始化
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    //判断i值是否合法
    if(i < 1 || i > L.length + 1)
    {
        printf("wrong i");
        return ERROR;
    }
    //如果超出报错
    if(L.length == L.listsize)
    {
        ElemType * newbase = (ElemType *)realloc(L.elem,sizeof(ElemType) * (L.listsize + LISTINCREMENT));
        if(newbase)
        {
            L.elem = newbase;
            L.listsize += LISTINCREMENT;
        }
        else{
            return OVERFLOW;
        }
    }
    //先移动
    for(int j = L.length - 1; j >= i - 1 ; j--)
    {
        L.elem[j + 1] = L.elem[j];
    }
    //插入元素
    L.elem[i - 1] = e;
    L.length ++;
    return OK;
}

status ListDelete(SqList &L,int i,ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    //判断线性表是否初始化
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    //判断操作合法性
    if(i < 1 || i > L.length)
    {
        return ERROR;
    }
    //弹出i
    e = L.elem[i - 1];
    //删除操作
    for(int j = i ; j <= L.length - 1 ; j ++)
    {
        L.elem[j-1] = L.elem[j];
    }
    L.length --;
    return OK;
}

status ListTraverse(SqList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    //判断线性表是否初始化
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    //空表判断
    if(!L.length)
    {
        printf("空线性表\n");
        return OK;
    }
    //遍历操作
    for(int i = 0 ; i < L.length - 1 ; i ++)
    {
        printf("%d ",L.elem[i]);
    }
    printf("%d\n",L.elem[L.length - 1]);
    return OK;
}

status  SaveList(SqList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    //判断线性表是否初始化
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    //打开文件
    FILE *file = fopen(FileName,"w");
    if (!file) return ERROR;
    //写入
    for(int i = 0; i < L.length ; i ++)
    fprintf(file,"%d ",L.elem[i]); 
    fclose(file);
    return OK;
}
status  LoadList(SqList &L,char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    //判断线性表是否初始化
    if(L.elem)
    {
        return INFEASIBLE;
    }
    //打开文件
    FILE *fp = fopen(FileName,"r");
    if(!fp) return ERROR;
    //计数
    int count = 0 , a;
    while(fscanf(fp,"%d",&a) != EOF) count++;
    fclose(fp);
    //分配线性表
    L.length = count;

    L.listsize = LIST_INIT_SIZE;
    while(L.listsize < count) L.listsize += LISTINCREMENT;

    ElemType* newbase = (ElemType*)malloc(sizeof(ElemType)*L.listsize);
    if(newbase) L.elem = newbase;
    else return ERROR;
    //读入
    fp = fopen(FileName,"r");
    if(!fp) return ERROR;
    
    for(int i = 0 ; i < L.length ; i ++)
    {
        fscanf(fp,"%d",&L.elem[i]);
    }
    fclose(fp);
    return OK;
}

status AddList(LISTS &Lists,char ListName[])
// 只需要在Lists中增加一个名称为ListName的空线性表，线性表数据又后台测试程序插入。
{
    //判断是否已满
    if(Lists.length == 10) return ERROR;
    //命名
    strcpy(Lists.elem[Lists.length].name,ListName);
    //建立线性表
    Lists.elem[Lists.length].L.elem = (ElemType*)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
    //判断新建是否成功
    if(!Lists.elem[Lists.length].L.elem) return ERROR;
    Lists.elem[Lists.length].L.listsize = LIST_INIT_SIZE;
    Lists.elem[Lists.length].L.length = 0;
    //更新表长
    Lists.length++;
    return OK;
}

status RemoveList(LISTS &Lists,char ListName[])
// Lists中删除一个名称为ListName的线性表
{
    //查找
    for(int i = 0 ; i < Lists.length ; i ++)
    {
        if(!strcmp(ListName,Lists.elem[i].name))
        {
            //删除操作
            for(int j = i ; j < Lists.length - 1; j ++)
            Lists.elem[j] = Lists.elem[j + 1];
            Lists.length--;
            return OK;
        }
    }
    //未找到
    printf("no result\n");
    return ERROR;
}

int LocateList(LISTS Lists,char ListName[])
// 在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
{
    //查找
    for(int i = 0 ; i < Lists.length ; i ++)
    {
        if(!strcmp(ListName,Lists.elem[i].name))
        {
            //返回序号
            return i + 1;
        }
    }
    //未找到
    printf("no result\n");
    return ERROR;
}

//最大连续子数组的和
ElemType MaxSubArray(SqList &L){
    //判断线性表是否初始化
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    if(L.length == 0) return ERROR;
    //定义两变量分别存储现在序列值与最大序列值
    ElemType cur_sum = L.elem[0];
    ElemType max_sum = L.elem[0];
    //找到子数组最大值
    for(int i = 1; i < L.length; i++)
    {
      //更新法则
      if(cur_sum < 0)
      {
        cur_sum = L.elem[i];
      }
      else
      {
        cur_sum += L.elem[i];
      }
      //比较最大值
      if(cur_sum > max_sum)
      {
        max_sum = cur_sum;
      }
    }
    return max_sum;
}

//和为K的子数组
int SubArrayNum(SqList &L,ElemType k)
{
  int count = 0;
  //判断线性表是否初始化
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
  //先求出前缀和
  ElemType prior[L.length + 1];
  prior[0] = 0;
  ElemType sum = 0;
  for(int i = 1 ; i <= L.length ; i ++)
  {
    sum += L.elem[i-1];
    prior[i] = sum;
  }
  //遍历寻找符合
  for(int i = 1 ; i <= L.length ; i ++)
  {
    ElemType index = prior[i] - k;
    for(int j = 0 ; j < i ; j ++)
    {
      if(index == prior[j]) count++;
    }
  }
  return count;
}

//顺序表排序
int compare(const void *e1 , const void *e2)
{
  return (*(ElemType*)e1 - *(ElemType*)e2);
}
status sortList(SqList &L)
{
  //判断线性表是否初始化
    if(!L.elem)
    {
        printf("no initiation");
        return INFEASIBLE;
    }
  //排序
  qsort(L.elem , L.length , sizeof(ElemType) , compare);
  return OK;
}

