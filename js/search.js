const search = document.querySelector('.header .search')
const searchextent = document.querySelector('.header .after .searchextent')
const historylist = document.querySelector('.searchextent .history ul')
let control2 = 0
let control7 = 1
search.addEventListener('click',()=>{
  if(control2 === 0)
  {search.style.width = '200px'
  search.style.display = 'flex'
  search.innerHTML = '<input type="text" placeholder="输入搜索内容"><button> 搜索</button>'
  control2 = 1

  const buttonsearch = document.querySelector('.header .search button')
  const input = document.querySelector('.header .search input')
  input.addEventListener('focus',()=>{
    console.log(1)
    searchextent.style.display = 'block'
  })
  searchextent.addEventListener('mouseenter',()=>{
    if(control2) control7 = 0
    console.log('enter')
  })
  searchextent.addEventListener('mouseleave',()=>{
    if(!control7) 
    {
      control7 = 1
      searchextent.style.display = 'none'
    }
  })
  input.addEventListener('blur',()=>{
    console.log(2)
    if(control7)
    searchextent.style.display = 'none'
  })
  }
})

