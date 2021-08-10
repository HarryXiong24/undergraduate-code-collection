#include<stdio.h>
int MIN(int n);
int main()
{
	int a,b,c,min,middle,max,n;
	min=MIN(n);
    
}

int MIN(int n)
{
	int a,b,c,min,middle,max;
	printf("Input a,b,c:"); 
	scanf("%d%*c%d%*c%d",&a,&b,&c);
	min=a;                                /*先假设a是最小数，如果不是，之后再用if语句否认*/
	if(min>b)
	   min=b;
	if(min>c)
	   min=c;
	printf("min=%d",min);
}
