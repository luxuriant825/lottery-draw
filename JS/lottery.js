var flag=0;
	window.onload=function(){
		var move=document.getElementById('move');
		var alis=move.getElementsByTagName('a');
		for (var i=0;i<alis.length;i++)
		{
			alis[i].onmouseover=function()
			{
				var ths=this.getElementsByTagName('i')[0];
				start(ths,{top:-25,opacity:0},function(){
					ths.style.top=40+'px';
					start(ths,{top:20,opacity:100});
				});
			}
		}
		
		var start1=document.getElementById('start');
		var stop1=document.getElementById('stop');
		start1.onclick=sgame;
		stop1.onclick=egame;
		
		document.onkeyup=function(event){
			event=event||window.event;
			if (event.keyCode==13)
			{
				if (flag==0){sgame();flag=1;}
				else{egame();flag=0;}
			}
		
		}
		
	}
	var timer=null;
	
	function sgame(){
		var pics=document.getElementsByTagName('a');
		var start1=document.getElementById('start');
		var stop1=document.getElementById('stop');
		clearInterval(timer);
		start1.style.background='#999';
		var j=Math.floor(Math.random()*pics.length);
		var num=Math.floor(Math.random()*pics.length)+20;
		if (j<num){
		timer=setInterval(function(){
			for (var i=0;i<pics.length;i++)
			{
				pics[i].className='';
			}
			pics[j%pics.length].className='active';
			j=Math.floor(Math.random()*pics.length);
			
		},100);
		}
	
	}
	
	function egame(){
		var pics=document.getElementsByTagName('a');
		var start1=document.getElementById('start');
		var stop1=document.getElementById('stop');
		clearInterval(timer);
		start1.style.background='#c63';
	}
	
	
