#include<stdio.h>
int main()
{
	int x,a,b,c,d,e,s;
	printf("Input a num:");
	scanf("%d",&x);
	
	if(x>99999)
	printf("error!");
	else if(x/10000!=0)
	{
	s=5;
	printf("这是五位数\n");
    }
	else if(x/1000!=0&&x/10000==0)
	{
	s=4;
	printf("这是四位数\n");
    }
	else if(x/100!=0&&x/1000==0)
	{
	s=3;
	printf("这是三位数\n");
    }
	else if(x/10!=0&&x/100==0)
	{
	s=2;
	printf("这是两位数\n");
    }
	else if(x/10==0)
	{
	s=1;
	printf("这是一位数\n");
    }
	
	a=x/10000;
	b=x/1000%10;
	c=x/100%10;
	d=x/10%10;
	e=x%10;
	
	switch(s)
	{ 
	   case 5:
	   printf("%d%d%d%d%d",e,d,c,b,a);
	   break;
	   case 4:
	   printf("%d%d%d%d",e,d,c,b);
	   break;
	   case 3:
	   printf("%d%d%d",e,d,c);
	   break;
	   case 2:
	   printf("%d%d",e,d);
	   break;
	   case 1:
	   printf("%d",e);
	   break;
	}
}
