#include<stdio.h>
int main()
{
	char ch;
	printf("Input a word:");
	scanf("%c",&ch);
	if(ch>='A'&&ch<='Z')
	printf("´óÐ´×ÖÄ¸\n");
	else if(ch>='a'&&ch<='z')
	printf("Ð¡Ð´×ÖÄ¸\n");
	else if(ch>='0'&&ch<='9')
	printf("Êý×Ö\n");
	else
	printf("ÆäËû×ÖÄ¸\n");
return 0;
}
