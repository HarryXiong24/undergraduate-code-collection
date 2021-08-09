#include<stdio.h>

//求多项式和的算法描述
//S(n) = a0 + a1x + a2x*2 + a3x*3 + ...... + an*x*n 

double fun(double a[], double x, int n)
{
	double S = a[n];
	int i;
	
	for(i = n - 1; i >= 0 ; i--)
	{
		S = S * x + a[i];	
	} 
	
	return S;
} 
