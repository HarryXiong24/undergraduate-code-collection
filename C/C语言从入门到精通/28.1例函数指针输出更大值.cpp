#include<stdio.h>
int xhw(int a,int b);

int xhw(int a,int b)
{
	int t;
	if(a>b)
	    t=a;
	else
	    t=b;
  	return t;
} 

int main()
{
	int x,y,c;
	int (*p)(int x,int y);
	p=xhw;
    
    printf("Input a,b:");
    scanf("%d,%d",&x,&y);
    c=(*p)(x,y);
    
    printf("max=%d",c);	
}
