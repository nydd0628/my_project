const whitemode = document.querySelector('.sidebar .dark .white')
const details = document.querySelectorAll('.details')
const body = document.querySelector('body')
const a = document.querySelectorAll('a')
const describe = document.querySelector('.sidebar .dark .describe')
const blackmode = document.querySelector('.sidebar .dark .black')
let control3 = 0
whitemode.addEventListener(
  'click',()=>{
    if(control3 === 0)
    {
      describe.innerHTML = '白天模式'
      for(let i = 0 ; i < a.length ; i++)
      {
        a[i].style.color = 'white'
      }
      for(let i = 0 ; i < details.length ; i++)
      {
        details[i].style.background = 'black'
      }
      body.style.background = 'rgba(0,0,0,0.9)'
      body.style.color = 'white'
      contentguide.style.background = 'rgba(0,0,0,0.9)'
      whitemode.style.opacity = '0'
      blackmode.style.opacity = '1'
      control3 = 1;
      searchextent.style.background = 'black'
    }
  }
)

blackmode.addEventListener(
  'click',()=>{
    if(control3 === 1)
    {
      describe.innerHTML = '黑夜模式'
      for(let i = 0 ; i < a.length ; i++)
      {
        a[i].style.color = 'black'
      }
      for(let i = 0 ; i < details.length ; i++)
      {
        details[i].style.background = 'white'
      }
      contentguide.style.background = 'white'
      body.style.color = 'black'
      body.style.background = 'white'
      whitemode.style.opacity = '1'
      blackmode.style.opacity = '0'
      control3 = 0;
      searchextent.style.background = 'white'
    }
  }
)

