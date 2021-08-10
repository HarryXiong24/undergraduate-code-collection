#include<stdio.h>
main()
{
	int a,b;
	printf("Input a:\n");
	printf("Input b:\n");
	scanf("%d %*C%d",&a,&b);
	printf("a+b=%d\n",a+b);
 } 
