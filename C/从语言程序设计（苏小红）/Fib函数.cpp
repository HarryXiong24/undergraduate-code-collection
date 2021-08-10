#include<stdio.h>
long Fib(int n);
int count;
int main()
{
	int n,i;
	long result;
	printf("Input n:");
	scanf("%d",&n);
    for(i=0;i<=n;i++)
       {
       	count=0;
       	result=Fib(i);
       	printf("Fib(%d)=%ld,count=%d\n",n,result,count);
	   }
return 0;
}

long Fib(int n)
{
	count++;
	if(n<0)
	   return -1;
	else if(n==0)
	   return 0;
	else if(n==1)
	   return 1;
	else
	   return(Fib(n-1)+Fib(n-2));	 
}
