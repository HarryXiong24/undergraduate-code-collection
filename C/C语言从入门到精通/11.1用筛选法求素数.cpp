#include<stdio.h>
int main()
{
	int str[100];
	int j;
	int i=1;
	int k;
	
	for(j=1;j<100;j++)
	{
		str[j]=i;
		i++;
    }
    
    for(j=1;j<100;j++)
    {
	    for(k=2;k<j;k++)	
		{		
			if(str[j]%k==0)
			   break;
			if(k==str[j]-1)
			   printf("%-4d",str[j]);
		}	
    }		
} 
