#include<stdio.h>
int main()
{
	int m[5]={10,2,3,21,5};
	int max;
	int i,j;
	
	for(j=5;j>1;j--)
	{
	for(i=1;i<j;i++)
	{
		if(m[i]>m[i-1])
		{
		 max=m[i];
		 m[i]=m[i-1];
		 m[i-1]=max;
     	}
	}
    }
	
	for(i=0;i<5;i++)
	{
		printf("%-4d",m[i]);
	}
}
