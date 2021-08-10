#include<stdio.h>
int fun(int i);

int main()
{
	int result,n;
	printf("Input n:");
	scanf("%d",&n);
	
	result=fun(n);
	
	printf("%d!=%d",n,result);
}

int fun(int i)
{
	int res;
	
	if(i==0)
	   res=1;
	else if(i==1)
	   res=1;
	else
	   res=fun(i-1)*i;
	   
	return res;
}

