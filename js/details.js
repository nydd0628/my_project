const details = document.querySelectorAll('.passages ul li .paper .details')
const pp = document.querySelectorAll('.passages ul li .paper .pp img')
let control4 = 0;
let control5 = 0;
for(let i = 0 ; i < details.length ; i++)
{
  details[i].addEventListener('mouseleave',()=>{
    if(control5 === 1 && control4 === 1)
    {
      console.log(3)
      details[i].style.opacity = '0'
      control4 = 0;
      control5 = 0;
    }
  })
}
for(let i = 0 ; i < pp.length ; i ++)
{
  pp[i].addEventListener('mouseenter',()=>{
    details[i].style.opacity = '1'
    control5 = 1;
    console.log(1)
  })
  pp[i].addEventListener('mouseleave',()=>{
    if(control5 === 1)
    {
      console.log(2)
      control4 = 1
    }
  })
}
