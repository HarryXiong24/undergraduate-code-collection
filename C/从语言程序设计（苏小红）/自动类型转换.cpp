#include<stdio.h>
main() 
{
	int a=3;
	float b=3.5;
	double c=3.66;
	a=b;
	b=c;
	c=a;
	printf("a=%d\n",a);
	printf("b=%f\n",b);
	printf("c=%f\n",c);
}
