#include<stdio.h> 
#include<stdlib.h>
main()
{
	int al,ai,i;
	int max,min;
	
	al=rand()%101+100;
	printf("%4d",al);
	max=min=al;
	
	for(i=1;i<10;i++)
	{
		ai=rand()%101+100;
		printf("%4d",ai);
		if(ai>max)
		    max=ai;
		if(ai<min)
		    min=ai;
	}
	printf("\nthe max:%d,the min:%d",max,min);
}

