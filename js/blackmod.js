const whitemode = document.querySelector('.sidebar .dark .white')
const body = document.querySelector('body')
const blackmode = document.querySelector('.sidebar .dark .black')
let control3 = 0
whitemode.addEventListener(
  'click',()=>{
    if(control3 === 0)
    {
      body.style.background = 'rgba(0,0,0,0.9)'
      whitemode.style.opacity = '0'
      blackmode.style.opacity = '1'
      control3 = 1;
    }
  }
)

blackmode.addEventListener(
  'click',()=>{
    if(control3 === 1)
    {
      body.style.background = 'white'
      whitemode.style.opacity = '1'
      blackmode.style.opacity = '0'
      control3 = 0;
    }
  }
)

