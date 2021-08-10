#include<stdio.h>
int main()
{
	int a[10];
	int i,j,k;
	int temp;
	
	for(i=0;i<10;i++)
	{
		printf("输入第%d个数:",i);
		scanf("%d",&a[i]);
	}
	
	printf("\n输入的数为:\n");
	for(i=0;i<10;i++)
	{
		printf("%-4d",a[i]);
	}
	
	for(i=0;i<10;i++)
	{
		k=i;
		for(j=i+1;j<10;j++)
		{
			if(a[j]<a[k])
			{
			   k=j;
		    }
		}
		if(k!=i)                        //优化，让自己和自己不交换 
      	{  
		     temp=a[k];
		     a[k]=a[i];
		     a[i]=temp;
	    }
	}
	
	printf("\n选择排序后:\n");
	for(i=0;i<10;i++)
	{
		printf("%-4d",a[i]);
	}
	
}
