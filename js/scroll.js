const contentguide = document.querySelector('.contentguide')
const sidebar = document.querySelector('.sidebar')
window.addEventListener('scroll',()=>{
  let n = document.documentElement.scrollTop
  console.log(n)
  if(n >= 300)
  {
    contentguide.style.position = 'fixed'
    contentguide.style.top = '0'
  }
  else{
    contentguide.style.position = 'relative'
  }
  if(n >= 200)
  {
    sidebar.style.position = 'fixed'
    sidebar.style.top = '30px'
    sidebar.style.left = '1050px'
    sidebar.style.opacity = '1'
  }
  else{
    sidebar.style.opacity = '0'
  }
})

