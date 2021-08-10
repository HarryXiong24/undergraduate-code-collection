#include<stdio.h>
int (*pfun)(int x,int y);    //函数指针 
int fun1(int *a,int *b);     //指针作函数参数 
int *fun2(int m,int n);      //指针函数 
int fun3(int c,int d);
int fun4(int c,int d);

int main()
{
	int p,q;
	int *p1;
	int *p2;
	int result;
	printf("Input p and q:");
	scanf("%d,%d",&p,&q);
	printf("Output_one:p=%d,q=%d\n",p,q);
	
	fun1(&p,&q);
	printf("Output_two:p=%d,q=%d\n",p,q);
	
	p1=fun2(p,q);
	printf("Output_three:%d\n",*p1);
	
	pfun=fun3;
	result=pfun(p,q);
	printf("Outeput_four:%d\n",result);
	
	pfun=fun4;
	result=pfun(p,q);
	printf("Output_five:%d\n",result);
	
} 

int fun1(int *a,int *b)
{
	*a=10;
	*b=10;
}

int *fun2(int m,int n)
{
	static int j;                              //如果就定义int j，那么出了这个函数的作用域，返回的地址不起作用 
	j=m+n;
	return &j;                                //返回的地址一定是要有效的地址 
}

int fun3(int c,int d)
{
	int g;
	g=c-d;
	return g;
}

int fun4(int c,int d)
{
	int h;
	h=c*d;
	return h;
}


