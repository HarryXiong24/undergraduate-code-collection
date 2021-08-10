#include<stdio.h>

int main()
{
	int a[3][3][3];
	int i,j,k;
	
	printf("«Î ‰»Î£∫\n");
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				scanf("%d",&a[i][j][k]);
			}
		}
	}
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				printf("%d",a[i][j][k]);
			}
		}
	}
	return 0;
}
