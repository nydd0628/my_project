const search = document.querySelector('.header .search')
const searchextent = document.querySelector('.header .after .searchextent')
const searchdetitle = document.querySelector('.searchextent .title')
const historylist = document.querySelector('.searchextent .history ul')
const historybrief = document.querySelectorAll('.searchextent .history li .brief a')
let control2 = 0
//建议库
const recommendData = ['建议1'];
//显示内容
function listEmerge(data,mode)
{
  let listItems = "";
  for(let i = 0 ; i < data.length ; i ++)
  {
    if(mode === 1)
    {
      listItems +=`<li><div class="brief"><a href="#">${data[i]}</a></div></li>`
    }
    else{
      listItems +=`<li><div class="brief"><a href="#">${data[i]}</a></div>
    <div class="imgbox"><img src="./image/叉.png" width="10px" height="10px"></div></li>`
    }
  }
  historylist.innerHTML = listItems
  searchextent.style.display = 'flex'
}



search.addEventListener('click',()=>{
  if(control2 === 0)
  {
    //显示搜索窗口
    search.style.width = '200px'
    search.style.display = 'flex'
    search.innerHTML = '<input type="text" placeholder="输入搜索内容" id="search"><button id = "searchbutton"> 搜索</button>'
    control2 = 1
    const searchinput = document.querySelector("#search")
    //根据输入调整显示模式
    function showlist(){
      const inputValue = searchinput.value.trim()
      if(inputValue.length > 0)
      {
        searchdetitle.style.display = 'none'
        const suggestion = recommendData.filter(item => item.includes(inputValue))
        listEmerge(suggestion,1)
      }
      else{
        searchdetitle.style.display = 'flex'
        historyItems = JSON.parse(localStorage.getItem('history'))
        listEmerge(historyItems,0)
        const deleteItems = document.querySelectorAll('.history li .imgbox')
        for(let i = 0 ; i < deleteItems.length ; i ++)
        {
          //对应删除
          deleteItems[i].addEventListener('click',()=>{
            deleteItems[i].parentNode.parentNode.removeChild( deleteItems[i].parentNode)
            const arry= JSON.parse(localStorage.getItem('history'))
            for(let i = 0 ; i < arry.length ; i ++)
            {
              if(arry[i] === deleteItems[i].previousElementSibling.childNodes[0].innerHTML)
              {
                arry.splice(i,1)
                localStorage.setItem('history',JSON.stringify(arry))
                break
              }
            }
        })
      }
  }}
  //按下搜索键，保存历史记录
  function searchrecord(){
    const inputValue = searchinput.value.trim()
    if(inputValue)
    {
      const arry= JSON.parse(localStorage.getItem('history'))
      let c = 0
      for(let i = 0 ; i < arry.length ; i ++)
      {
        if(arry[i] === inputValue)
        {
          c = 1;
          break
        }
      }
      if(!c)
      {
        arry.unshift(inputValue)
      }
      localStorage.setItem('history',JSON.stringify(arry))
    }
    historylist.innerHTML = ''
    searchextent.style.display = 'none'
  }

  searchinput.addEventListener('focus',showlist)
  searchinput.addEventListener('input',showlist)
  const searchbutton = document.querySelector('#searchbutton')
  searchbutton.addEventListener('click',searchrecord)
  const clearbutton = document.querySelector(".header .searchextent .title .imgbox")
  //清除按钮
  clearbutton.addEventListener('click',()=>{
    localStorage.setItem('history',JSON.stringify([]))
    historylist.innerHTML = ''
  })
  }
})