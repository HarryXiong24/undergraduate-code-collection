#include<stdio.h>
int main()
{
	int MONTH[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int month;
	do{
		printf("Input a month:");
		scanf("%d",&month);
	}while(month<1 ||month>12);
	printf("The number of days is %d\n",MONTH[month-1]);
	return 0; 
}

