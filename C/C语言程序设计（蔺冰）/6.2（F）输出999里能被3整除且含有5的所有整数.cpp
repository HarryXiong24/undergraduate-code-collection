#include<stdio.h>
int main()
{
	int bai,shi,ge,i;
	int count=0;
	
    for(i=1;i<1000;i++)
    {
    	ge=i%10;
    	shi=i/10%10;
    	bai=i/100%10;
    
    	if(i%3==0&&(ge==5||shi==5||bai==5))
    	{
		   printf("%-6d",i);
		   count++;
	    }   
    } 
    printf("\ncount=%d",count);
}

