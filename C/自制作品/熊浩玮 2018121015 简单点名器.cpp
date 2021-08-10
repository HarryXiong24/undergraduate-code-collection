#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int num,i,e;
    srand(time(NULL));
    
    for(i=1;;i++)
    {
	   printf("输入一个任意正整数开始程序：") ;
	   scanf("%d",&e); 
	   if(e==0)
	   {
		  printf("程序结束");
		  break; 
	   } 
	   else
	   {
	   	  num=rand()%82+1;
	      printf("\n恭喜%d被点中!\n\n如果需要退出程序请输入0\n\n**********************************\n\n",num);
	   }    
	}	
}
