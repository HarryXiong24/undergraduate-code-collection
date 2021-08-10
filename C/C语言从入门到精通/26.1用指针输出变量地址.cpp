#include<stdio.h>
int main()
{
	int a,b;
	int *p1=&a,*p2=&b;
	printf("Input a,b:");
	scanf("%d,%d",&a,&b);
	
	printf("a的地址%d，b的地址%d",p1,p2);
}
