const store = document.querySelector('#store')
const content = document.querySelector('.storeextent')
const storeextent = document.querySelector('.storeextent')
let control1 = 0;
let control6 = 0;
store.addEventListener('click',() => {
if(control1 === 0)
{
  content.style.display = 'block';
  control1 = 1;
}
else{
  content.style.display = 'none';
  control1 = 0;
}
})
//商城的外展部分