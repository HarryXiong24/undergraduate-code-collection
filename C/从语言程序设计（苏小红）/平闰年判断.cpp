#include<stdio.h>
main()
{
	int year;
	printf("Input a number:");
	scanf("%d",&year);
	if(year%4==0&&year%100!=0||year%400==0)
	printf("今年是闰年\n");
	else
	printf("今年是平年\n");
}
