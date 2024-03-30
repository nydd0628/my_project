const contentguide = document.querySelector('.contentguide')
const sidebar = document.querySelector('.sidebar')
const guidance = document.querySelector('.guidance')
const passages = document.querySelector('.passages ul')
let k = 0
window.addEventListener('scroll',()=>{
  let n = document.documentElement.scrollTop
  //头部固定
  if(n >= 220)
  {
    contentguide.style.position = 'fixed'
    contentguide.style.top = '0'
  }
  else{
    contentguide.style.position = 'relative'
  }
  //导航栏浮现于侧边栏固定
  if(n >= 100)
  {
    sidebar.style.position = 'fixed'
    guidance.style.display = 'flex'
  }
  else{
    sidebar.style.position = 'absolute'
    guidance.style.display = 'none'
  }
  //下拉更新文章
  if(n >= 450 + 150 * k && k <=20)
  {
    const addition = document.createElement('li')
    addition.innerHTML=document.querySelector('.passages ul li:nth-child(1)').innerHTML
    passages.appendChild(addition)
    console.log(k)
    k++
  }
})


