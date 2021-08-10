#include<stdio.h>
#define MONTH 12 
int main()
{
	int A[MONTH]={31,28,31,30,31,30,31,31,30,31,30,31};
	int month;
	do{
		printf("Input a month:");
		scanf("%d",&month);
	}while(month<1 ||month>12);
	printf("The number of days is %d\n",A[month-1]);
	return 0; 
}

