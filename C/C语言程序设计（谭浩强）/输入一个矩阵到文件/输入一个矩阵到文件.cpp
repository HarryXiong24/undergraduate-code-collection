#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp1;
	int a[3][3];
	int i,j;
	char filename[10];
	
	printf("Input a file name:\n");
	scanf("%s",filename);
	
	
	if((fp1=fopen(filename,"w"))==NULL)
	{
		printf("Error!\n");
		exit(0);
	}
	
	printf("Input 9 numbers:\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
		printf("\n");
	}
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			fprintf (fp1,"%3d",a[i][j]);
			printf("%3d",a[i][j]);
		}
		fprintf(fp1,"\n");
		printf("\n");
	}
		
}
 
