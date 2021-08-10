#include<stdio.h>
#include<math.h> 
main()
{
	int a,b;
	char op;
	printf("Input a and b:");
	scanf("%d%c%d",&a,&op,&b);
	switch(op)
	{
		case'+':
		printf("%d+%d=%d\n",a,b,a+b); 
		break;
		case'-':
		printf("%d-%d=%d\n",a,b,a-b);
		break;
		default:
		printf("invaild operator!\n");
    }
}
