#include<stdio.h>
#define max 6
int main()
{
	char arr[max];
	printf("Input:");
	scanf("%s",arr);
	
	printf("%c\n",arr[5]);     //以字符形式输入 
	printf("%s",arr);          //以字符串形式输入 
}
