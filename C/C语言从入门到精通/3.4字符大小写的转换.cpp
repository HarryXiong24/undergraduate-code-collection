#include<stdio.h>
int main()
{
	char ch,c;
	printf("输入一个字符：");
	scanf("%c",&ch);
	if(ch>='A'&&ch<='Z')
	{
	
	   c=ch+32;
	   printf("字母为大写字母%c,转换为小写字母%c",ch,c);
    }
	else if(ch>='a'&&ch<='z')
	{
	   c=ch-32;
	   printf("字母为小写字母%c,转换为大写字母%c",ch,c); 
    }
	else
	   printf("输入的不是字符，无法转换");
return 0; 
 } 
