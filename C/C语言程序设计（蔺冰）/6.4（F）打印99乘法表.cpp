#include<stdio.h>
int main()
{
	int n,i,j;
	
	for(i=1;i<=9;i++)
    {
    	for(j=1;j<=9;j++)
    	{
    		printf("%d*%d=%-4d",i,j,n=i*j);      //这里设置一个-4d有助于使打印出来的更好看 
        }
    printf("\n");
	}   

} 
