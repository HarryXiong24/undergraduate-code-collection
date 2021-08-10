#include<stdio.h>
int main()
{
	int a,b;
	int *p1=&a,*p2=&b,*p;
	printf("Input a,b:");
	scanf("%d,%d",&a,&b);
	
	if(*p1<*p2)
	{
		p=p1;
		p1=p2;
		p2=p;
	}
	printf("a=%d,b=%d",*p1,*p2);
}
