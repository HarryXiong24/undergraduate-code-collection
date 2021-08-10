#include<stdio.h>
main()
{
	int x;
	int find=0;
	for(x=1;!find;x++)
	{
		if(x%5==1&&x%6==5&&x%7==4&&x%11==10&&x>10000)
		{
		printf("x=%d\n",x);
		find=1;
		} 
	}
}
