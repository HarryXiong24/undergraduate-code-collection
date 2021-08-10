#include<stdio.h>
int  main()
{
	int m,n,a,b;
	printf("Input m,n:");
	scanf("%d%*c%d",&m,&n);
	
	   
   for(b=1;;b++) 
       {
       	   if(b%m==0&&b%n==0)
       	   {                                       //括号一定不能省略 
			  printf("最小公倍数是：%d",b); 
			  printf("\n最大公约数是：%d",a=(m*n)/b);   //记得数论中最大公因数*最小公倍数=两个数之积 
       	      break; 
           }   
	   }	   
}	 
