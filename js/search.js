const search = document.querySelector('.header .search')
const searchextent = document.querySelector('.header .after .searchextent')
const searchdetitle = document.querySelector('.searchextent .title')
const historylist = document.querySelector('.searchextent .history ul')
let control2 = 0
const recommendData = [];

function listEmerge(data)
{
  let listItems = "";
  for(let i = 0 ; i < data.length ; i ++)
  {
    if(data[i] === '无')
    {
      listItems +=`<li><div class="brief"><a href="#">${data[i]}</a></div></li>`
    }
    else{
      listItems +=`<li><div class="brief${i+1}"><a href="#">${data[i]}</a></div>
    <div class="imgbox${i+1}"><img src="./image/叉.png" width="10px" height="10px"></div></li>`
    }
  }
  historylist.innerHTML = listItems
  searchextent.style.display = 'block'
}



search.addEventListener('click',()=>{
  if(control2 === 0)
  {search.style.width = '200px'
  search.style.display = 'flex'
  search.innerHTML = '<input type="text" placeholder="输入搜索内容" id="search"><button id = "searchbutton"> 搜索</button>'
  control2 = 1
  const searchinput = document.querySelector("#search")
  function showlist(){
    const inputValue = searchinput.value.trim()
    if(inputValue.length > 0)
    {
      searchdetitle.style.display = 'none'
      const suggestion = recommendData.filter(item => item.includes(inputValue))
      listEmerge(suggestion)
    }
    else{
      searchdetitle.style.display = 'flex'
      historyItems = JSON.parse(localStorage.getItem('history'))
      listEmerge(historyItems)
    }
  }

  function searchrecord(){
    const inputValue = searchinput.value.trim()
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

  searchinput.addEventListener('focus',showlist)
  searchinput.addEventListener('input',showlist)
  // searchinput.addEventListener('blur',(e)=>{
  //   historylist.innerHTML = ''
  //   searchextent.style.display = 'none'
  //   console.log(e)
  // })
  const searchbutton = document.querySelector('#searchbutton')
  searchbutton.addEventListener('click',searchrecord)
  const deletEbutton = document.querySelector('.history li .imgbox')
  const clearbutton = document.querySelector(".header .searchextent .title .imgbox")
  clearbutton.addEventListener('click',()=>{
    localStorage.setItem('history',JSON.stringify([]))
    historylist.innerHTML = ''
  })
  }
})