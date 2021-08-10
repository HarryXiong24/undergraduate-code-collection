#include<stdio.h>
#include<stdlib.h>
main()
{
	int x;
	int a;
	printf("Input:x>",a);
	scanf("%d",&a);
    for(x=1;x<100000;x++)
    {
    	
		if(x%5==1&&x%6==5&&x%7==4&&x%11==10&&x>a)
    	{
    		printf("x=%d\n",x);
    		break;
		}
	}
 } 
