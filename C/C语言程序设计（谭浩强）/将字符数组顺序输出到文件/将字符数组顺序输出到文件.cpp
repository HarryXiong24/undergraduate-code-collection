#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fp;
	char str[3][10],temp[10];
	int i,j,k,n=3;
	printf("Enter string:\n");
	
	for(i=0;i<n;i++)
	{
	gets(str[i]); 
	}
	
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(strcmp(str[k],str[j])>0)
			k=j;
			if(k!=i)
			{
				strcpy(temp,str[i]);
				strcpy(str[i],str[k]);
				strcpy(str[k],temp);
			}
		}
    }
		
		if((fp=fopen("C:\\Users\\Lenovo\\Desktop\\编程\\C语言\\C语言程序设计（谭浩强）\\将字符数组顺序输出到文件\\xhw.dat","w"))==NULL)
		{
			printf("文件打开失败！\n");
			exit(0);
		}
		
		printf("\nThe new sequence:\n");
		for(i=0;i<n;i++)
		{
			fputs(str[i],fp);
			fputs("\n",fp);
			printf("%s\n",str[i]);
		}
		
		return 0;	 
} 
