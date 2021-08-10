#include<stdio.h>
void input(int a[10]);
void sort(int a[10]);
void output(int a[10]);
int search(int a[10]); 

int main()
{
	int a[10];
	int temp;
	int i,j;
	int res;
	
	input(a);
	sort(a);
	output(a);
	
	res=search(a);
	if(res==-1)
	    printf("没有查找到！\n");
	else
	    printf("找到了！"); 
} 

void input(int a[10])
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("Input a[%d]:",i);
		scanf("%d",&a[i]);
	}
}

void sort(int a[10])
{
	int i,j;
	int temp;
	
	for(j=10;j>1;j--)                                     
	{
	    for(i=1;i<j;i++)                               
	    {
		    if(a[i]<a[i-1])
	     	{
		        temp=a[i];
		        a[i]=a[i-1];
		        a[i-1]=temp;
     	    }
	    }
    }
}

void output(int a[10])
{
	int i;
	printf("\nresult is:\n");
	for(i=0;i<10;i++)
	{
		printf("%4d",a[i]);
	}
	printf("\n");
}

int search(int a[10])
{
	int num;
	int high=9;
	int low=0;
	int mid;
	
	printf("\nInput a num:");
	scanf("%d",&num);
	
	while(low<=high)
	{
		mid=(high+low)/2;
		if(num>a[mid])
		    low=mid+1;
		else if(num<a[mid])
		    high=mid-1;
		else
		    return mid;	    
	}
	return -1;	
}

