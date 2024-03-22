const img = document.querySelector('.sidebar .box-img img')
const carousel = document.querySelector('.sidebar .carousel')
const left = document.querySelector('.sidebar .left')
const right = document.querySelector('.sidebar .right')      
const one = document.querySelector('.sidebar .change li:nth-child(1)')
const two = document.querySelector('.sidebar .change li:nth-child(2)')
const three = document.querySelector('.sidebar .change li:nth-child(3)')
const data = ["./image/卡芙卡.jpg","./image/杨.jpg","./image/黄泉.jpg"]
let index = 0;
left.addEventListener('click',()=>{
  index--
  if(index < 0) index = index + 3;
  img.src = data[index];
  document.querySelector('.sidebar .change .active').classList.remove('active')
  document.querySelector(`.sidebar .change li:nth-child(${index + 1})`).classList.add('active')
})
right.addEventListener('click',()=>{
  index++
  if(index > 2) index = index - 3;
  img.src = data[index];
  document.querySelector('.sidebar .change .active').classList.remove('active')
  document.querySelector(`.sidebar .change li:nth-child(${index + 1})`).classList.add('active')
})
one.addEventListener('click',()=>{
  index = 0
  img.src = data[index];
  document.querySelector('.sidebar .change .active').classList.remove('active')
  document.querySelector(`.sidebar .change li:nth-child(${index + 1})`).classList.add('active')
})
two.addEventListener('click',()=>{
  index = 1
  img.src = data[index];
  document.querySelector('.sidebar .change .active').classList.remove('active')
  document.querySelector(`.sidebar .change li:nth-child(${index + 1})`).classList.add('active')
})
three.addEventListener('click',()=>{
  index = 2
  img.src = data[index];
  document.querySelector('.sidebar .change .active').classList.remove('active')
  document.querySelector(`.sidebar .change li:nth-child(${index + 1})`).classList.add('active')
})
setInterval(()=>{
  index++
  if(index > 2) index = index - 3;
  img.src = data[index];
  document.querySelector('.sidebar .change .active').classList.remove('active')
  document.querySelector(`.sidebar .change li:nth-child(${index + 1})`).classList.add('active')
},5000)

carousel.addEventListener('mouseenter',()=>{
  one.style.width = '15px'
  one.style.height = '15px'
  two.style.width = '15px'
  two.style.height = '15px'
  three.style.width = '15px'
  three.style.height = '15px'
})
carousel.addEventListener('mouseleave',()=>{
  one.style.width = '10px'
  one.style.height = '10px'
  two.style.width = '10px'
  two.style.height = '10px'
  three.style.width = '10px'
  three.style.height = '10px'
})