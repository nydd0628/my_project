const toup = document.querySelector('#toup')
const toin = document.querySelector('#toin')
const signin = document.querySelector('.sign .signin')
const signup = document.querySelector('.sign .signup')
toup.addEventListener('click',()=>{
  signin.style.display = 'none'
  signup.style.display = 'flex'
})
toin.addEventListener('click',()=>{
  signup.style.display = 'none'
  signin.style.display = 'flex'
})