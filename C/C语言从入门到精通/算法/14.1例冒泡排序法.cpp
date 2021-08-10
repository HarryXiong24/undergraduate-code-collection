#include<stdio.h>
int main()
{
	int m[8]={5,2,30,98,20,1,45,80};
	int a[10]={0};
	int b[40]={0};
	int c[50]={0};
	int i; 
	
	for(i=0;i<8;i++)
	{
		if(m[i]>0&&m[i]<11)
		    a[m[i]-1]=1;
		if(m[i]>11&&m[i]<51)
		    b[m[i]-1]=1;
		if(m[i]>50&&m[i]<100)
		    c[m[i]-1]=1;
	}
	
	for(i=0;i<10;i++)
    {
    	if(a[i]==1)
    	  printf("%4d",i+1);
	}
	
	for(i=11;i<51;i++)
	{
		if(b[i]==1)
		  printf("%4d",i+1);
	}
	
	for(i=51;i<100;i++)
	{
		if(c[i]==1)
		  printf("%4d",i+1);
	}
} 
