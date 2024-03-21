const store = document.querySelector('#store')
const content = document.querySelector('.storeextent div')
let control = 0;
store.addEventListener('click',() => {
if(control === 0)
{
  content.style.display = 'block';
  control = 1;
}
else{
  content.style.display = 'none';
  control = 0;
}
})