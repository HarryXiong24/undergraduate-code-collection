#include<stdio.h>
int main()
{
	int day,month,year;
	int days=0;              //需要定义一个days为中间量，方便转化和计算 
	int flag=1; 
	printf("Input a date(eg:2018.10.15):");
	scanf("%d%*c%d%*c%d",&year,&month,&day);
	
	switch(month)
	{
		case 12:            //月份要倒着输，因为输入4月时，从case4进入，如果顺着输，这是运算5,6……的天数和
			days+=31;
		case 11:
			days+=30;
		case 10:
		    days+=31;
		case 9:
		    days+=30;
		case 8:
		    days+=31;
		case 7:
		    days+=31;
		case 6:
		    days+=30;
		case 5:
		    days+=31;
		case 4:
		    days+=30;
		case 3:
		    days+=31;
		case 2:
		    days+=28;
		case 1:
		    days+=0;          //注意只要加0了
		break;
	default:
		  flag=0;		
	}
	
	if((year%400==0||(year%4==0&&year%100!=0))&&month>2)
    {
    	days++;	
	}
	
	days+=day;
	
	if(flag==0)
	   printf("error!");
	else
	   printf("一共有%d天",days);     //days为总天数，而day为输入的那个月的天数，特别要区分 
 }
 
