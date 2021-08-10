//输出任意区间内的所有素数// 
#include<stdio.h>
int main()
{
	long a,b;
	long n,i;
	long count=0;
	long flag=0;
	
	printf("从小到大输入两个数，作为你需要的区间：");
	scanf("%ld%*c%ld",&a,&b);
	printf("您输入的区间为[%ld,%ld]\n",a,b);

	for(n=a;n<=b;n++)  
	{
	   for(i=2;i<n;i++)
	   {
		  if(n%i==0)
		    break;
		  else if(i==n-1)
		    flag=1;    
	   }
	     
		  if(flag==1)
		  {
		     printf("%7ld",n);
		     count++;
		     flag=0;
		  if(count%10==0)
	         printf("\n"); 	
		  }
	         
    }
} 
