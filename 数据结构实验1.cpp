/* ͷ�ļ����� */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
/* ���峣�� */
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
/* ���Ͷ���*/
typedef int status; 
typedef int ElemType; //����Ԫ�����Ͷ���

/* ˳����� */
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct{  //˳���˳��ṹ���Ķ���
	ElemType * elem;
	int length;
	int listsize;
}SqList;

typedef struct{  //���Ա�ļ������Ͷ���
     struct { char name[30];
               SqList L;    
     } elem[10];
     int length;
}LISTS;
/* �������� */
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
    //ģʽȷ�� 
    int mode;
    printf("��ѡ��ģʽ\n");
    printf("1.���   2.����\n");
    scanf("%d",&mode);
    //����������Ķ��� 
    LISTS Lists;
    Lists.length = 0;
    SqList List;
    List.elem = NULL; 
    
    int op=1;
    //�����õ��ı������� 
    int i,b,k;
    int e;
    int index;
    int pre,next,position;
    char listname[30];
    char filename[100];
    if(mode == 1){
while(op){
	//������ 
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
	printf("    ��ѡ����Ĳ���[0~18]:");
	scanf("%d",&op);
    switch(op){
	   case 1:
         printf("�����б���\n");
         scanf("%s",listname);
         
		 if(AddList(Lists,listname) == OK) printf("���Ա����ɹ���\n");
		 else printf("���Ա���ʧ�ܣ�\n");
	     getchar();getchar();
		 break;
	   case 2:
         printf("�����б���\n");
         scanf("%s",listname);
         
		 if(RemoveList(Lists,listname) == OK) printf("�Ƴ��ɹ�\n");
         else printf("�Ƴ�ʧ��\n");     
		 getchar();getchar();
		 break;
	   case 3:
         printf("�������б���\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
		 if(ClearList(Lists.elem[i].L) == OK) printf("����ɹ�\n");
         else printf("���ʧ��\n");       
		 getchar();getchar();
		 break;
	   case 4:
		 printf("�����б���\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
		 if(ListEmpty(Lists.elem[i].L) == TRUE) printf("�ǿձ�\n");
         else if(ListEmpty(Lists.elem[i].L) == FALSE) printf("���ǿձ�\n"); 
		 else printf("�޷������б�\n");         
		 getchar();getchar();
		 break;
	   case 5:
		 printf("�����б���\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
		 if(ListLength(Lists.elem[i].L)==INFEASIBLE) printf("δ��ʼ��\n");
         else printf("��Ϊ��%d\n",ListLength(Lists.elem[i].L));
		 getchar();getchar();
		 break;
	   case 6:
		 printf("�����б���\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
         printf("������������\n");
         scanf("%d",&index);
         
		 if(GetElem(Lists.elem[i].L,index,e) == OK) printf("���Ԫ��Ϊ��%d\n",e);
         else printf("�޷���ø�Ԫ��\n");     
		 getchar();getchar();
		 break;
	   case 7:
		 printf("�����б���\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
		 if(MaxSubArray(Lists.elem[i].L) != INFEASIBLE) printf("������������ĺ�Ϊ��%d\n",MaxSubArray(Lists.elem[i].L));
		 else printf("�޷����Ŀ��ֵ\n");     
		 getchar();getchar();
		 break;
	   case 8:
		 printf("�����б���\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
		 if(sortList(Lists.elem[i].L) == OK) printf("�ɹ�����\n");
         else printf("�޷�����\n");     
		 getchar();getchar();
		 break;
	   case 9:
		 printf("�����б���\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
         printf("�������ļ���\n");
         scanf("%s",filename);
         
		 if(LoadList(Lists.elem[i].L , filename) == OK) printf("�ɹ���ȡ%s�е�����",filename);
         else printf("�޷���ȡ\n");    
		 getchar();getchar();
		 break;
	   case 10:
		 printf("�����б���\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
         printf("����������ҵ�Ԫ��\n");
         scanf("%d",&e);
		 b = LocateElem(Lists.elem[i].L , e);
		 if(b == INFEASIBLE) printf("δ��ʼ��\n");
         else if(b == ERROR) printf("δ�ҵ���ֵ\n");
		 else printf("���Ϊ��%d\n",b);     
		 getchar();getchar();
		 break;
	   case 11:
		 printf("�����б���\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
         printf("����������ҵ�Ԫ��\n");
         scanf("%d",&e);
		 b = PriorElem(Lists.elem[i].L, e, pre);
		 
		 if (b == INFEASIBLE) printf("δ��ʼ��\n");
		 else if (b == ERROR) printf("δ�ҵ�ǰ��\n");
		 else printf("ǰ��Ϊ%d\n", pre);
		 getchar();getchar();
		 break;
	   case 12:
		 printf("�����б���\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
         printf("����������ҵ�Ԫ��\n");
         scanf("%d",&e);
		 b = NextElem(Lists.elem[i].L, e, next);
		 
		 if (b == INFEASIBLE) printf("δ��ʼ��\n");
		 else if (b == ERROR) printf("δ�ҵ����\n");
		 else printf("���Ϊ%d\n", next);
		 getchar();getchar();
		 break;
       case 13:
		 printf("�����б���\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
         printf("���������λ��\n");
         scanf("%d",&position);
         printf("���������Ԫ��\n");
         scanf("%d",&e);
         
		 if(ListInsert(Lists.elem[i].L , position , e) == OK) printf("�ɹ�����\n");
         else printf("����ʧ��\n");
		 getchar();getchar();
		 break;
       case 14:
		 printf("�����б���\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
         printf("������ɾ��λ��\n");
         scanf("%d",&position);
         
		 if(ListDelete(Lists.elem[i].L , position , e) == OK) printf("�ɹ�ɾ��%d\n",e);
         else printf("ɾ��ʧ��\n");
		 getchar();getchar();
		 break;
       case 15:
		 printf("�����б���\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
		 if(ListTraverse(Lists.elem[i].L) == OK) printf("�ɹ�����\n");
         else printf("����ʧ��\n");
		 getchar();getchar();
		 break;
       case 16:
		 printf("�����б���\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
         printf("����������ҵĺ�\n");
         scanf("%d",&k);
         
		 if(SubArrayNum(Lists.elem[i].L , k)) printf("���ҵ����ϸ���Ϊ:%d\n",SubArrayNum(Lists.elem[i].L , k));
         else printf("����ʧ��\n");
		 getchar();getchar();
		 break;
       case 17:
		 printf("�����б���\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname) - 1;
         if(i + 1 == ERROR) break;
         
         printf("�������������ļ���\n");
         scanf("%s",filename);
         
		 if(SaveList(Lists.elem[i].L , filename) == OK) printf("�ɹ�����\n");
         else printf("����ʧ��\n");
		 getchar();getchar();
		 break;
       case 18:
		 printf("�����б���\n");
         scanf("%s",listname);
         i = LocateList(Lists , listname);
         
		 if(i > 0) printf("���ҵ��ñ�λ��Ϊ:%d\n",i);
         else printf("����ʧ��\n");
		 getchar();getchar();
		 break;
	   case 0:
         break;
       default:
       	 printf("wromg order\n");
         break;	
	}//end of switch
  }//end of while
printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
    }
else if(mode == 2){
    op = 1;
while(op){
	//������� 
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
	printf("    ��ѡ����Ĳ���[0~17]:");
	scanf("%d",&op);
    switch(op){
	   case 1:
	     if(InitList(List) == OK) printf("���Ա����ɹ���\n");
	     else printf("���Ա���ʧ�ܣ�\n");
	     getchar();getchar();
		 break;
	   case 2:
		 if(DestroyList(List) == OK) printf("���ٳɹ�\n");
         else printf("����ʧ��\n");     
		 getchar();getchar();
		 break;
	   case 3:
		 if(ClearList(List) == OK) printf("����ɹ�\n");
         else printf("���ʧ��\n");       
		 getchar();getchar();
		 break;
	   case 4:
		 if(ListEmpty(List) == TRUE) printf("�ǿձ�\n");
         else if(ListEmpty(List) == FALSE) printf("���ǿձ�\n"); 
		 else printf("�޷������б�\n");           
		 getchar();getchar();
		 break;
	   case 5:
		 if(ListLength(List)==INFEASIBLE) printf("δ��ʼ��\n");
         else printf("��Ϊ��%d\n",ListLength(List));
		 getchar();getchar();
		 break;
	   case 6:
         printf("������������\n");
         scanf("%d",&index);
         
		 if(GetElem(List,index,e) == OK) printf("���Ԫ��Ϊ��%d\n",e);
         else printf("�޷���ø�Ԫ��\n");     
		 getchar();getchar();
		 break;
	   case 7:
		 if(MaxSubArray(List) != INFEASIBLE) printf("������������ĺ�Ϊ��%d\n",MaxSubArray(List));
         else printf("�޷����Ŀ��ֵ\n");     
		 getchar();getchar();
		 break;
	   case 8:
		 if(sortList(List) == OK) printf("�ɹ�����\n");
         else printf("�޷�����\n");     
		 getchar();getchar();
		 break;
	   case 9:
         printf("�������ļ���\n");
         scanf("%s",filename);
		 if(LoadList(List , filename) == OK) printf("�ɹ���ȡ%s�е�����",filename);
         else printf("�޷���ȡ\n");    
		 getchar();getchar();
		 break;
	   case 10:
         printf("����������ҵ�Ԫ��\n");
         scanf("%d",&e);
         b = LocateElem(List , e);
         
		 if(b == INFEASIBLE) printf("δ��ʼ��\n");
         else if(b == ERROR) printf("δ�ҵ���ֵ\n");
		 else printf("���Ϊ��%d\n",b);     
		 getchar();getchar();
		 break;
	   case 11:
         printf("����������ҵ�Ԫ��\n");
         scanf("%d",&e);
		 b = PriorElem(List, e, pre);
		 
		 if (b == INFEASIBLE) printf("δ��ʼ��\n");
		 else if (b == ERROR) printf("δ�ҵ�ǰ��\n");
		 else printf("ǰ��Ϊ%d\n", pre);
		 getchar();getchar();
		 break;
	   case 12:
         printf("����������ҵ�Ԫ��\n");
         scanf("%d",&e);
		 b = NextElem(List, e, next);
		 
		 if (b == INFEASIBLE) printf("δ��ʼ��\n");
		 else if (b == ERROR) printf("δ�ҵ����\n");
		 else printf("���Ϊ%d\n", next);
		 getchar();getchar();
		 break;
       case 13:
         printf("���������λ��\n");
         scanf("%d",&position);
         
         printf("���������Ԫ��\n");
         scanf("%d",&e);
         
		 if(ListInsert(List , position , e) == OK) printf("�ɹ�����\n");
         else printf("����ʧ��\n");
		 getchar();getchar();
		 break;
       case 14:
         printf("������ɾ��λ��\n");
         scanf("%d",&position);
		 if(ListDelete(List , position , e) == OK) printf("�ɹ�ɾ��%d\n",e);
         else printf("ɾ��ʧ��\n");
		 getchar();getchar();
		 break;
       case 15:
		 if(ListTraverse(List) == OK) printf("�ɹ�����\n");
         else printf("����ʧ��\n");
		 getchar();getchar();
		 break;
       case 16:
         printf("����������ҵĺ�\n");
         scanf("%d",&k);
		 if(SubArrayNum(List , k)) printf("���ҵ����ϸ���Ϊ:%d\n",SubArrayNum(List , k));
         else printf("����ʧ��\n");
		 getchar();getchar();
		 break;
       case 17:
         printf("�������������ļ���\n");
         scanf("%s",filename);
		 if(SaveList(List , filename) == OK) printf("�ɹ�����\n");
         else printf("����ʧ��\n");
		 getchar();getchar();
		 break;
	   case 0:
         break; 
       default:
       	 printf("wromg order\n");
         break;	
	}//end of switch
  }//end of while
printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
    }
else printf("wromg order\n");
}











status InitList(SqList& L)
// ���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
{
    //�ж����Ա��Ƿ�Ϊ�գ�������ʼ���Ƿ����
    if(L.elem)
    {
        printf("there are some elementaries in this list\n");
        return INFEASIBLE;
    }
    //����ռ�
    L.elem = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    L.listsize = LIST_INIT_SIZE;
    L.length = 0;
    return OK;
}

status DestroyList(SqList& L)
// ������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
{
    //�ж����Ա��Ƿ��ʼ��
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    //���ٲ���
    ElemType *temp = L.elem;
    L.elem = NULL;
    free(temp);
    
    return OK;
}

status ClearList(SqList& L)
// ������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
{
    //�ж����Ա��Ƿ��ʼ��
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    //��ղ���
    L.length = 0;
    return OK;
}

status ListEmpty(SqList L)
// ������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
{
    //�ж����Ա��Ƿ��ʼ��
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    //�ж��Ƿ�Ϊ�ձ�
    if(L.length) return FALSE;
    else return TRUE;

}

status ListLength(SqList L)
// ������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
{
    //�ж����Ա��Ƿ��ʼ��
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    //���ر�
    return L.length;
}

status GetElem(SqList L,int i,ElemType &e)
// ������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    //�ж����Ա��Ƿ��ʼ��
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    //��֤Ԫ���ڱ�ķ�Χ��
    if(i < 1 || i > L.length) return ERROR;
    //��ȡ��i��Ԫ�ز���ֵ
    e = *(L.elem + i - 1);
    return OK;

}

int LocateElem(SqList L,ElemType e)
// ������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����Ų����ظ���ţ����e�����ڣ�����0�������Ա�L������ʱ������INFEASIBLE����-1����
{
    //�ж����Ա��Ƿ��ʼ��
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    //Ѱ�Ҳ���
    int index = 0;
    for(int i = 0 ; i < L.length ; i ++)
    {
        if(*(L.elem + i) == e)
        {
            //��ȡƥ��ֵ���˳�
            index = i + 1;
            break;
        }

    }
    if(index) return index;
    else return ERROR;
}

status PriorElem(SqList L,ElemType e,ElemType &pre)
// ������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    //�ж����Ա��Ƿ��ʼ��
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    //Ѱ�Ҳ���
    int index = 0;
    for(int i = 0 ; i < L.length ; i ++)
    {
        if(*(L.elem + i) == e)
        {
            //��ȡƥ��ֵ���˳�
            index = i + 1;
            break;
        }
    }
    //����ǰ��
    if(index > 1)
    {
        pre = *(L.elem + (index - 2));
        return OK;
    }
    else return ERROR;
}

status NextElem(SqList L,ElemType e,ElemType &next)
// ������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    //�ж����Ա��Ƿ��ʼ��
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    //Ѱ�Ҳ���
    int index = 0;
    for(int i = 0 ; i < L.length ; i ++)
    {
        if(*(L.elem + i) == e)
        {
            //��ȡƥ��ֵ���˳�
            index = i + 1;
            break;
        }
    }
    //���غ��
    if(index > 0 && index < L.length)
    {
        next = *(L.elem + (index));
        return OK;
    }
    else return ERROR;

}

status ListInsert(SqList &L,int i,ElemType e)
// ������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    //�ж����Ա��Ƿ��ʼ��
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    //�ж�iֵ�Ƿ�Ϸ�
    if(i < 1 || i > L.length + 1)
    {
        printf("wrong i");
        return ERROR;
    }
    //�����������
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
    //���ƶ�
    for(int j = L.length - 1; j >= i - 1 ; j--)
    {
        L.elem[j + 1] = L.elem[j];
    }
    //����Ԫ��
    L.elem[i - 1] = e;
    L.length ++;
    return OK;
}

status ListDelete(SqList &L,int i,ElemType &e)
// ������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
{
    //�ж����Ա��Ƿ��ʼ��
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    //�жϲ����Ϸ���
    if(i < 1 || i > L.length)
    {
        return ERROR;
    }
    //����i
    e = L.elem[i - 1];
    //ɾ������
    for(int j = i ; j <= L.length - 1 ; j ++)
    {
        L.elem[j-1] = L.elem[j];
    }
    L.length --;
    return OK;
}

status ListTraverse(SqList L)
// ������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
{
    //�ж����Ա��Ƿ��ʼ��
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    //�ձ��ж�
    if(!L.length)
    {
        printf("�����Ա�\n");
        return OK;
    }
    //��������
    for(int i = 0 ; i < L.length - 1 ; i ++)
    {
        printf("%d ",L.elem[i]);
    }
    printf("%d\n",L.elem[L.length - 1]);
    return OK;
}

status  SaveList(SqList L,char FileName[])
// ������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
{
    //�ж����Ա��Ƿ��ʼ��
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    //���ļ�
    FILE *file = fopen(FileName,"w");
    if (!file) return ERROR;
    //д��
    for(int i = 0; i < L.length ; i ++)
    fprintf(file,"%d ",L.elem[i]); 
    fclose(file);
    return OK;
}
status  LoadList(SqList &L,char FileName[])
// ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
{
    //�ж����Ա��Ƿ��ʼ��
    if(L.elem)
    {
        return INFEASIBLE;
    }
    //���ļ�
    FILE *fp = fopen(FileName,"r");
    if(!fp) return ERROR;
    //����
    int count = 0 , a;
    while(fscanf(fp,"%d",&a) != EOF) count++;
    fclose(fp);
    //�������Ա�
    L.length = count;

    L.listsize = LIST_INIT_SIZE;
    while(L.listsize < count) L.listsize += LISTINCREMENT;

    ElemType* newbase = (ElemType*)malloc(sizeof(ElemType)*L.listsize);
    if(newbase) L.elem = newbase;
    else return ERROR;
    //����
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
// ֻ��Ҫ��Lists������һ������ΪListName�Ŀ����Ա����Ա������ֺ�̨���Գ�����롣
{
    //�ж��Ƿ�����
    if(Lists.length == 10) return ERROR;
    //����
    strcpy(Lists.elem[Lists.length].name,ListName);
    //�������Ա�
    Lists.elem[Lists.length].L.elem = (ElemType*)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
    //�ж��½��Ƿ�ɹ�
    if(!Lists.elem[Lists.length].L.elem) return ERROR;
    Lists.elem[Lists.length].L.listsize = LIST_INIT_SIZE;
    Lists.elem[Lists.length].L.length = 0;
    //���±�
    Lists.length++;
    return OK;
}

status RemoveList(LISTS &Lists,char ListName[])
// Lists��ɾ��һ������ΪListName�����Ա�
{
    //����
    for(int i = 0 ; i < Lists.length ; i ++)
    {
        if(!strcmp(ListName,Lists.elem[i].name))
        {
            //ɾ������
            for(int j = i ; j < Lists.length - 1; j ++)
            Lists.elem[j] = Lists.elem[j + 1];
            Lists.length--;
            return OK;
        }
    }
    //δ�ҵ�
    printf("no result\n");
    return ERROR;
}

int LocateList(LISTS Lists,char ListName[])
// ��Lists�в���һ������ΪListName�����Ա��ɹ������߼���ţ����򷵻�0
{
    //����
    for(int i = 0 ; i < Lists.length ; i ++)
    {
        if(!strcmp(ListName,Lists.elem[i].name))
        {
            //�������
            return i + 1;
        }
    }
    //δ�ҵ�
    printf("no result\n");
    return ERROR;
}

//�������������ĺ�
ElemType MaxSubArray(SqList &L){
    //�ж����Ա��Ƿ��ʼ��
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
    if(L.length == 0) return ERROR;
    //�����������ֱ�洢��������ֵ���������ֵ
    ElemType cur_sum = L.elem[0];
    ElemType max_sum = L.elem[0];
    //�ҵ����������ֵ
    for(int i = 1; i < L.length; i++)
    {
      //���·���
      if(cur_sum < 0)
      {
        cur_sum = L.elem[i];
      }
      else
      {
        cur_sum += L.elem[i];
      }
      //�Ƚ����ֵ
      if(cur_sum > max_sum)
      {
        max_sum = cur_sum;
      }
    }
    return max_sum;
}

//��ΪK��������
int SubArrayNum(SqList &L,ElemType k)
{
  int count = 0;
  //�ж����Ա��Ƿ��ʼ��
    if(!L.elem)
    {
        printf("no initiation\n");
        return INFEASIBLE;
    }
  //�����ǰ׺��
  ElemType prior[L.length + 1];
  prior[0] = 0;
  ElemType sum = 0;
  for(int i = 1 ; i <= L.length ; i ++)
  {
    sum += L.elem[i-1];
    prior[i] = sum;
  }
  //����Ѱ�ҷ���
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

//˳�������
int compare(const void *e1 , const void *e2)
{
  return (*(ElemType*)e1 - *(ElemType*)e2);
}
status sortList(SqList &L)
{
  //�ж����Ա��Ƿ��ʼ��
    if(!L.elem)
    {
        printf("no initiation");
        return INFEASIBLE;
    }
  //����
  qsort(L.elem , L.length , sizeof(ElemType) , compare);
  return OK;
}

