const contentguide = document.querySelector('.contentguide')
const sidebar = document.querySelector('.sidebar')
const passages = document.querySelector('.passages ul')
let k = 0
window.addEventListener('scroll',()=>{
  let n = document.documentElement.scrollTop
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
    sidebar.style.display = 'block'
  }
  else{
    sidebar.style.display = 'none'
  }
  if(n >= 450 + 150 * k && k <=20)
  {
    const addition = document.createElement('li')
    addition.innerHTML=document.querySelector('.passages ul li:nth-child(1)').innerHTML
    passages.appendChild(addition)
    console.log(k)
    k++
  }
})

