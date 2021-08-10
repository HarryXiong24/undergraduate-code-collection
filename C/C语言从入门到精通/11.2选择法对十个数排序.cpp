#include<stdio.h>
int main()
{
	int str[10];
	int i,j;
	int temp;
	
	printf("Input 10 num:");
	for(i=1;i<10;i++)
	{
		scanf("%d",&str[i]);
	}
	
	for(j=10;j>1;j--)
	{
	for(i=2;i<10;i++)
	{
		if(str[i]<str[i-1])
		{
			temp=str[i-1];
			str[i-1]=str[i];
			str[i]=temp;
		}
	}
    }
	
	for(i=1;i<10;i++)
	{
		printf("%-6d",str[i]);
	}	
} 
