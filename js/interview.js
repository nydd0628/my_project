const moveleft = document.querySelector('.interview .left')
const moveright = document.querySelector('.interview .right')
const companylist = document.querySelector('.interview .show ul')
let record = 0
console.log(companylist)
moveleft.addEventListener('click',()=>{
  if(record >0)
  {
    console.log(record)
    record--
    companylist.style.transform = `translateX(-${record*180}px)`
  }
})
moveright.addEventListener('click',()=>{
  if(record < 2)
  {
    console.log(record)
    record++
    companylist.style.transform = `translateX(-${record*180}px)`
  }
})