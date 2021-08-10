#include<stdio.h>
int MIN(int x,int y,int z);

int main()
{
	int a,b,c,min;
	printf("Input a,b,c:");
	scanf("%d,%d,%d",&a,&b,&c);
	
	min=MIN(a,b,c);
	printf("\nThe min is:%d",min);
	return 0;
} 

int MIN(int x,int y,int z)
{
	int min,temp=0;
	min=x;
    
    if(y<z)
        temp=y;
    else
        temp=z;
        
    if(x<temp)
       min=x;
    else
       min=temp;
    
    return min;
}
