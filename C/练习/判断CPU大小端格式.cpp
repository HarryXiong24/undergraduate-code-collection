#include<stdio.h>

int main()
{
	unsigned short X=0xAABB;
	char *p=(char *)&X;
	if(*p==0xBB)
		printf("小端格式");
	else if(*p==0xAA)
		printf("大端格式");
	else
		printf("\n王燚老师,这算惊喜吗?\n");
}
