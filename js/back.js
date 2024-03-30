const back = document.querySelector('.guidance .button')
back.addEventListener('click',()=>{
  let n = setInterval(()=>{
    if(document.documentElement.scrollTop > 0)
    {
      if(document.documentElement.scrollTop >=100)
      {
        document.documentElement.scrollTop -= 100
      }
      else{
        document.documentElement.scrollTop = 0
      }
    }
    else
    {
      clearInterval(n)
    }
  })
},1000)
// 试图用定时器实现