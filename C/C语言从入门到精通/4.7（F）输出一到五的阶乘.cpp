/*#include<stdio.h>
main()
{
	int a,b,x;
	printf("Input a num:"); 
	scanf("%d",&x);
	do
	{
		a=1;
		b=a*(a+1);
		a++;
	
	}while(a<=x);
	printf("%d!=%d",x,b);
}*/

#include<stdio.h>
main()
{
	int a,b,x;
	printf("Input a num:"); 
	scanf("%d",&x);
	b=1;
	for(a=1;a<=x;a++)
	{
	   b=b*a;
	}
	printf("%d!=%d",x,b);
}




