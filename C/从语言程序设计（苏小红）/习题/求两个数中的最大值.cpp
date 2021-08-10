/*求两个数中的最大值*/ 
#include<stdio.h>
int main()
{
	int a,b;
	printf("Input a,b:");
    scanf("%d%*c%d",&a,&b);
	if(a>b)
	  printf("max=%d",a);
	if(a<b)
	  printf("max=%d",b);
}

