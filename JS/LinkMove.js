// JavaScript Document

function getStyle(obj,attr)
{
	if (obj.currentStyle){
		return obj.currentStyle[attr];//IE
	}
	else{return getComputedStyle(obj,false)[attr];}//firefox
}





function start(obj,json,fn){
	
	clearInterval(obj.timer);
	obj.timer=setInterval(function(){
		var flag=true;
		for (var attr in json){
		var icur=0;
		if (attr=='opacity'){
			icur=Math.round(parseFloat(getStyle(obj,attr))*100);
		}
		else{
			icur=parseInt(getStyle(obj,attr));
		}
		
		
		
		
		var speed=(json[attr]-icur)/2;
		speed=speed>0?Math.ceil(speed):Math.floor(speed);
		
		
		
		if (icur!=json[attr])
		{
			flag=false;
		}

		if (attr=='opacity'){
			obj.style.filter='alpha:(opacity:'+icur+speed+')';
			obj.style.opacity=(icur+speed)/100;
		}
		else{
				obj.style[attr]=icur+speed+'px';
			}
		}
		
		
		if (flag){
			clearInterval(obj.timer);
			if (fn){fn();}	
		}
		
		
	},30)
	
}
