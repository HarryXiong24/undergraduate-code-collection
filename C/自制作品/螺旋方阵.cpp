#include<stdio.h>

int main()
{
	int line;
	int a=1;
	int b=0;
	int c;
	int i,j;
	int arr[20][20];
	
	printf("请输入方阵的行数:");
	scanf("%d",&line);
	if(line>100)
	    scanf("error!");
	    
	c=line-1;
	    
	while(a<=line*line&&b<=c)
	{
		i=b;
		j=b;
		
		if(b==c)
		{
			arr[i][j]=a;
			break;
		}
		
		for(j=b;j<c;j++)
		{
			arr[i][j]=a;
			a++;
		}
		
		for(i=b;i<c;i++)
		{
			arr[i][j]=a;
			a++;
		}
		
		for(j=c;j>b;j--)
		{
			arr[i][j]=a;
			a++;
		}
		
		for(i=c;i>b;i--)
		{
			arr[i][j]=a;
			a++;
		}
		b++;
		c--;
	}
	
	for(i=0;i<line;i++)
	{
		for(j=0;j<line;j++)
		{
			printf("%4d",arr[i][j]);
		}
		printf("\n");
	}
	
}
