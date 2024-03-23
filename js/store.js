const store = document.querySelector('#store')
const content = document.querySelector('.storeextent div')
const storeextent = document.querySelector('.storeextent')
let control1 = 0;
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
