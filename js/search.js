const search = document.querySelector('.header .search')
const searchextent = document.querySelector('.header .after .searchextent')
const searchdetitle = document.querySelector('.searchextent .title')
const historylist = document.querySelector('.searchextent .history ul')
let control2 = 0
search.addEventListener('click',()=>{
  if(control2 === 0)
  {search.style.width = '200px'
  search.style.display = 'flex'
  search.innerHTML = '<input type="text" placeholder="输入搜索内容" id="search"><button> 搜索</button>'
  control2 = 1
  const searchinput = document.querySelector("#search")
  function showlist(){
    const inputValue = searchinput.ariaValueMax.trim()
    if(inputValue.length > 0)
    {
      searchdetitle.style.display = 'none'
    }
    else{
      searchdetitle.style.display = 'flex'
    }
  }
  searchinput.addEventListener('focus',showlist)
  }
})

