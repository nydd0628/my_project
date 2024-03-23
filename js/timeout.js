function getTime()
    {
      const day = document.querySelector('.sidebar .timeout .day')
      const hour = document.querySelector('.sidebar .timeout .hour')
      const minute = document.querySelector('.sidebar .timeout .minute')
      const second = document.querySelector('.sidebar .timeout .second')
      const now = +new Date();
      const aim = +new Date('2024-4-26 19:30:00');
      const count = (aim - now)/1000;
      let d = parseInt(count / 60 /60 / 24);
      let h = parseInt(count / 60 /60 % 24);
      let m = parseInt(count / 60 % 60);
      let s = parseInt(count % 60);
      console.log();
      h = h < 10 ? '0'+h : h;
      s = s < 10 ? '0'+s : s;
      m = m < 10 ? '0'+m : m;
      day.innerHTML = d;
      hour.innerHTML = h;
      minute.innerHTML = m;
      second.innerHTML = s;
    }
    setInterval(getTime,1000);