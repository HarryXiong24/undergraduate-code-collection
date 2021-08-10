//用指针数组输出单位矩阵//
#include<stdio.h>
int main()
{
	int a1[3]={1,0,0};
	int a2[3]={0,1,0};
	int a3[3]={0,0,1};
	
	int *p[3];
	p[0]=a1;
	p[1]=a2;
	p[2]=a3;
	
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%2d",p[i][j]);
		}
		printf("\n");
	}
	
} 

