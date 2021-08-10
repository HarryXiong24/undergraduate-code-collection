#include<stdio.h>
int main()
{
	int a,b,c,result;
	printf("Input a,b,c:");
	scanf("%d%*c%d%*c%d",&a,&b,&c);
	if(a>9||b>9||c>9)
	  printf("error!because the number will be the 0~9\n");
	else 
	  printf("result=%d=%d*%d*%d+%d*%d*%d+%d*%d*%d",result=a*a*a+b*b*b+c*c*c,a,a,a,b,b,b,c,c,c);
 } 
