#include<stdio.h>
int main()
{
	char *p,s[8];
	int n=0;
	p=s;
	printf("Input:"); 
	gets(p);
	
	while(*p!=0)
	{
		n=n*8+*p-'0';
		p++;
	}
	printf("\n十进制数:%d\n",n);
}
