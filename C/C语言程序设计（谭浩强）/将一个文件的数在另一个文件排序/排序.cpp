#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fp1,*fp2;
	int a[8];
	int i;
	
	if((fp1=fopen("file1.txt","w"))==NULL)
	{
		printf("无法打开文件！\n");
		exit(0);
	}
	
	
	printf("请输入要排序的8个数：\n"); 
	for(i=0;i<8;i++)
	{
		scanf("%d",&a[i]);
		fscanf(fp1,"%3d",&a[i]);
	}
	
	
    if((fp2=fopen("C:\\Users\\Lenovo\\Desktop\\编程\\C语言\\C语言程序设计（谭浩强）\\将一个文件的数在另一个文件排序\\whx.dat","w"))==NULL)
	{
		printf("无法打开文件！\n");
		exit(0);
	}
	
	printf("输入的数为：\n");
	for(i=0;i<8;i++)
	{
		fprintf(fp2,"%-3d",a[i]);
		printf("%-3d",a[i]);
	}
	fclose(fp2);
	
} 
