#include<stdio.h>
int main()
{
	char str[3][100];
	int i,j;
	int a=0,b=0,c=0;
	
	for(i=0;i<3;i++)
	{
	printf("请输入第%d串字符:",i);
	gets(str[i]);
	getchar();
    }
	
	for(i=0;i<3;i++)
	{
		for(j=0;str[i][j]!='\0';j++)
		{
		if((str[i][j]>'A'&&str[i][j]<'Z')||(str[i][j]>'a'&&str[i][j]<'z'))
		    a++;
		else if(str[i][j]>'0'&&str[i][j]<'9')
		    b++;
		else
		    c++;
		}
	}
	
	printf("\n字母个数:%d  数字个数:%d 其他:%d",a,b,c);
	 
} 
