#include<stdio.h>
int main()
{
    int a,b,c;
    int *p1=&a,*p2=&b,*p3=&c,*p;
    printf("Input a,b,c:");
    scanf("%d,%d,%d",&a,&b,&c);
    
    if(b<a)              //b,a与*p1，*p2可以互换// 
    {
    	*p=*p2;
    	*p2=*p1;             
    	*p1=*p; 
	}
	
	if(*p3<*p2)            //这只是个例子，大小比出来有错，不用在意// 
	{
		*p=*p3;
		*p3=*p2;
		*p1=*p;
	}
	
	if(c<a)
	{
		*p=*p3;
		*p3=*p1;
		*p1=*p;
		
	}
    printf("%d,%d,%d",*p1,*p2,*p3);




} 
