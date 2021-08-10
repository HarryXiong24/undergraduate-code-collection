#include<stdio.h>
#define PI 3.14 
int main()
{
	float r,h,s,v;
	printf("Input r,h:");
	scanf("%f%*c%f",&r,&h);
	s=2*PI*r*h+2*PI*r*r;
	v=PI*r*r*h;
	printf("s=%.2f\n",s);
	printf("v=%.2f",v);
	
return 0;	
}
 
