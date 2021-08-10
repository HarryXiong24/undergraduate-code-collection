#include<stdio.h>
int main()
{
	float v,a,x,t;
	printf("Input a and t:");
	scanf("%f%*c%f",&a,&t);
	v=0; 
	x=0.5*a*t*t;
	printf("x=%f",x);
return 0;
 } 
