#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[11];
	int i;
	int num;
	
	printf("Input the number:\n");
	
	for(i = 1; i <= 10; i++)
	{
		scanf("%d", &a[i]);
	}	
	
	printf("Input the research num:\n");
	scanf("%d", &num);
	
	a[0] = num;
	
	for(i = 10; i >= 0; i--)
	{
		if(a[i] == a[0] && i != 0)
		{
			printf("Find!    %d\n", i);
			break;
		}
		if(i == 0)
			printf("Not Find!\n"); 
	}
} 
