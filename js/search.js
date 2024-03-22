const search = document.querySelector('.header .search')
let control2 = 0
search.addEventListener('click',()=>{
  if(control2 === 0)
  {search.style.width = '170px'
  search.innerHTML = '<input type="text" placeholder="输入搜索内容">'
  control2 = 1

  const input = document.querySelector('.header .search input')
  input.addEventListener('focus',()=>{
    console.log(1)
  })
  input.addEventListener('blur',()=>{
    console.log(2)
  })
  }
})

