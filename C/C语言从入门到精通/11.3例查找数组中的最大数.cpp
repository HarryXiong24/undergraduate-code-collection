#include<stdio.h>
#define num 6
int main()
{
	int s[num],i;
	int max;
	
	for(i=0;i<num;i++)
	{
		printf("Input:");
		scanf("%d",&s[i]);
	}

    max=s[0];
	for(i=0;i<num;i++)
	{
        if(max<s[i])
		    max=s[i];
	}
	printf("the max is:%d",max);
} 
