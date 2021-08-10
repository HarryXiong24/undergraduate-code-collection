#include<stdio.h>
#include<math.h>
main()
{
	float a,b,c,s;
	printf("Input a,b,c:");
	scanf("%f,%f,%f",&a,&b,&c);
	s=(a+b+c)/2; 
	printf("area=%f\n",(float)sqrt(s*(s-a)*(s-b)*(s-c)));
}
 
