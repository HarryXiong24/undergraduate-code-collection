#include<stdio.h> 
#define max 5
int main()
{
	int s[max];
	int i;
	int sum;
		
    for(i=0;i<max;i++)
	{
		printf("Input a num:");
		scanf("%d",&s[i]);
	}
	
	for(i=0;i<max;i++)
	{
		
		printf("%-4d",s[i]);
		sum+=s[i];
	}
	 
	printf("平均值为：%d",sum/max);
	
	
} 
