#include<stdio.h>
main()
{
	int a,b,c,max;
	printf("Input a,b,c:");
	scanf("%d,%d,%d",&a,&b,&c);
    max=a;
    if(max<b)
    max=b;
    if(max<c)
    max=c;
    printf("the largest number=%d\n",max);
    
}
