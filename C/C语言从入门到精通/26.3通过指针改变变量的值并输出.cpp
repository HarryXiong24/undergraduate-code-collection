#include<stdio.h>
int  main()
{
	int a,b;
	printf("Input a,b:");
	scanf("%d,%d",&a,&b);
	printf("a=%d,b=%d\n",a,b);
	
	int *p1=&a,*p2=&b;
	*p1=10;
	*p2=20;
	
	printf("a=%d,b=%d\n",*p1,*p2);
	printf("a=%d,b=%d\n",a,b);
	
}
