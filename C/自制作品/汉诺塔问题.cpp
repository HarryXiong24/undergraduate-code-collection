#include<stdio.h>
int hanoi(int n,char a,char b,char c);
void move(char x,char y);

int main()
{
	int n;
	printf("Input:");
	scanf("%d",&n);
	hanoi(n,'A','B','C');

}

int hanoi(int n,char a,char b,char c)
{
	if(n==1)
	    move(a,c);
	else
	{
		hanoi(n-1,a,c,b);
		move(a,c);
		hanoi(n-1,b,a,c);
	}
	printf("count=%d\n");
	
}

void move(char x,char y)
{
	printf("%c------->%c\n",x,y);
}
