let s = 1;
const idimg = document.querySelector('.idimg')
const sign = document.querySelector('.sign')
const callin = document.querySelector('.callin')
const callup = document.querySelector('.callup')
const error1 = document.querySelector('.signin .error')
const inbutton = document.querySelector('.sign .signin #signin')
let show = 0
//3种唤出登录注册栏的方式
idimg.addEventListener('click',()=>{

  signin.style.display = 'flex'
  signup.style.display = 'none'
  if(!show && s)
  {
    sign.style.display = 'flex'
    sign.style.left = '1200px'
    let k = 1;
    let n = setInterval(()=>{
      sign.style.left = `${1200-k*100}px`
      if(k === 6) clearInterval(n)
      k++;
    },1)
    show = 1
  }
  else{
    sign.style.display = 'none'
    show = 0
  }
})
callin.addEventListener('click',()=>{
  signin.style.display = 'flex'
  signup.style.display = 'none'
  if(!show && s)
  {
    sign.style.display = 'flex'
    sign.style.left = '1200px'
    let k = 1;
    let n = setInterval(()=>{
      sign.style.left = `${1200-k*100}px`
      if(k === 6) clearInterval(n)
      k++;
    },1)
    show = 1
  }
  else{
    sign.style.display = 'none'
    show = 0
  }
})
callup.addEventListener('click',()=>{
  signin.style.display = 'none'
  signup.style.display = 'flex'
  if(!show && s)
  {
    sign.style.display = 'flex'
    sign.style.left = '1200px'
    let k = 1;
    let n = setInterval(()=>{
      sign.style.left = `${1200-k*100}px`
      if(k === 6) clearInterval(n)
      k++;
    },1)
    show = 1
  }
  else{
    sign.style.display = 'none'
    show = 0
  }
})
function getInputValue(idnum){
  let key = document.getElementById(idnum).value
  return key
}
let usernumber = 0
const touxiang = document.querySelector('.idimg img')
const exit = document.querySelector('.exit')
//登录
inbutton.addEventListener('click',()=>{
  usernumber = +localStorage.getItem('usernumber')
  const phone1 = getInputValue('phone1');
  const password1 = getInputValue('password1');
  if(phone1 && password1)
  {
    for(let i = 1 ; i <= usernumber ; i ++)
    {
      let phone = localStorage.getItem(`${i}phone`)
      let password = localStorage.getItem(`${i}password`)
      if(phone1 === phone && password1 === password)
      {
        s = 0;
        show = 0;
        touxiang.src = `./image/content${Math.floor(Math.random()*(5-1+1))+1}.jpg`
        error1.innerHTML = ''
        alert('welcome')
        console.log(exit)
        exit.style.display = 'flex'
        sign.style.display = 'none'
        break;
      }
      else{
        error1.innerHTML = '用户名或密码错误'
      }
    }
  }
  else{
    error1.innerHTML = '请输入内容'
  }
})
const error2 = document.querySelector('.signup .error')
const upbutton = document.querySelector('.sign .signup #signup')
//注册
upbutton.addEventListener('click',()=>{
  usernumber = +localStorage.getItem('usernumber')
  const phone2 = getInputValue('phone2');
  const password2 = getInputValue('password2');
  const password3 = getInputValue('password3');
  if(phone2 && password2 && password3)
  {
    let norepeat = 1;
    for(let i = 1 ; i <= usernumber ; i ++)
    {
      let phone = localStorage.getItem(`${i}phone`)
      if(phone2 === phone)
      {
        error2.innerHTML = '该用户已注册'
        norepeat = 0
        break
      }
    }
    if(password2 === password3)
    {
      if(norepeat)
      {
        usernumber++;
        localStorage.setItem(`${usernumber}phone`,phone2)
        localStorage.setItem(`${usernumber}password`,password2)
        alert('注册成功')
        localStorage.setItem(`usernumber`,`${usernumber}`)
      }
    }
    else{
      error2.innerHTML = '密码不一致'
    }
  }
  else{
    error2.innerHTML = '请输入内容'
  }
})
const exitbutton = document.querySelector('.exit button')
//退出登录
exitbutton.addEventListener('click',()=>
{
  s = 1;
  touxiang.src = './image/默认头像.png'
  exit.style.display = 'none'
  alert('成功退出')
})