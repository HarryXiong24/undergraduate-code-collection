#include<stdio.h>
int main()
{
	int a[11]; 
	int i,j;
	int temp;
	
	for(i=1;i<11;i++)
	{
		printf("Input a[%d]:",i);
		scanf("%d",&a[i]);
	}
	
	for(i=1;i<11;i++)                                   //一共需要十个这样的过程(还是九个？) 
	{
		for(j=1;j<10;j++)                              //把最大数放到最右边,需要九次 
		{
			if(a[j]>a[j+1])
			    {
			    	temp=a[j];
			    	a[j]=a[j+1];
			    	a[j+1]=temp;
				}
		}	
	}
	
	printf("\nresult is:\n");
	for(i=1;i<11;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
} 
