#include<stdio.h>
int main()
{
	int a,num,flag=0;
	printf("Input a num:");
	scanf("%d",&num);
	
	for(a=2;a<num;a++)
	{
	   if(num%a==0)
	   {
	   	  flag=1;
	   }
    }  
	 
	if(flag==1) 	
	    printf("%d是合数",num);
	else
	    printf("%d是素数",num);
} 
