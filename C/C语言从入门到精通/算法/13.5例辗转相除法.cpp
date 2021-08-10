#include<stdio.h>
int main()
{
	int m,n,r,t;
	printf("Input m,n:");
	scanf("%d%*c%d",&m,&n);
	
	if(n>m)
	{
	    n=t;
	    n=m;
	    m=t;
	}
	
	do
	{
		r=m%n;
		m=n,n=r;
	}while(r!=0);
	
	printf("m,n的最大公约数是:%d",m);	    
}
