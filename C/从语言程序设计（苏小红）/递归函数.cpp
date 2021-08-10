#include<stdio.h>
long Fact(int n);
int main()
{
	int n;
	long result;
	printf("Input n:");
	scanf("%d",&n);
	result=Fact(n);
	if(result==-1)              /*对数值进行返回值的检验*/
	    printf("n<0,error!\n");
	else
	    printf("%d!=%ld\n",n,result);
	return 0; 
}

long Fact(int n)
{
	if(n<0)
	    return -1;
	else if (n==0||n==1)
	    return 1;
	else
	    return(n*Fact(n-1));	
} 
