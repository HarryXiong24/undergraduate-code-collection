#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char ch,filename[10];
	printf("请输入所用的文件名：");
	scanf("%s",filename);
	getchar();                     //清楚回车符
	if((fp=fopen(filename,"w"))==NULL) 
	{
		printf("cannot open file!\n");
		exit(0);
	} 
	printf("请输入一个准备储存到磁盘的字符串（以#为结束）：");
	ch=getchar();
	while(ch!='#')
	{
		fputc(ch,fp);
		putchar(ch);
		ch=getchar();
	}
	fclose(fp);
	putchar(10);                    //换行
	return 0;
} 
