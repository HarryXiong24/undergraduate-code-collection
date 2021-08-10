#include<stdio.h>
int main()
{
	int a,count=0;
	
	for(a=10000;a<=30000;a++)
	{
		if(a%3==0&&a%5==0&&a%7==0&&a%23==0)
		{                               //if后的大括号千万不能去掉 
		printf("the num is:%d\n",a); 
		count++;
	    }
	}
	
	printf("count:%d",count);
}
