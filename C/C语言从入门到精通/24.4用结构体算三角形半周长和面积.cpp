#include<stdio.h>
#include<math.h>
struct cir_area
{
	float l;
	float s;
};

struct cir_area yuan(float a,float b,float c)
{
	struct cir_area result;
	result.l=(a+b+c)/2;
	result.s=sqrt(result.l*(result.l-a)*(result.l-b)*(result.l-c));
	return result;
}

int main()
{
	struct cir_area result;
	float a,b,c;
	printf("Input a,b,c:");
	scanf("%f,%f,%f",&a,&b,&c);
	result=yuan(a,b,c);
	printf("半周长是%f，面积是%f",result.l,result.s);
}
