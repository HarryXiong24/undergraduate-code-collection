#include<stdio.h>
int main()
{
	int i,j;
	int n;
	
	printf("Input n:");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			printf(" ");
		}
		printf("%c",'A'+i-1);
		if(i==1)
		{
			printf("\n");
			continue;
		}
		
		for(j=1;j<=2*i-3;j++)
		{
			printf(" ");
		}
		printf("%c",'A'+i-1);
		printf("\n");
	}
	
	for(i=1;i<n;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf(" ");
		}
		printf("%c",'A'+n-i-1);
	    if(i==n-1)
		{
			printf("\n");
			break;
		}
		
		for(j=1;j<=2*(n-i)-3;j++)
		{
			printf(" ");
		}
		
		printf("%c",'A'+n-i-1);
		printf("\n");
	}
} 
