#include<stdio.h>
void xhw(int *p1,int *p2)
{
    int temp;
	temp=*p1;
	*p1=*p2;
	*p2=temp;
    printf("*p1=%d,*p2=%d\n",*p1,*p2);
} 

int main()
{
	int a,b;
	int *x1=&a,*x2=&b;

	printf("Input a,b:");
	scanf("%d,%d",&a,&b);
	
	if(a>b)
	    xhw(x1,x2);
	printf("%d<%d",*x1,*x2);
	return 0;
}
