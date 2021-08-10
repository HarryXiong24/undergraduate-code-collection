#include<stdio.h>
int main()
{
	char str1[10],str2[10];
	char *p1,*p2;
	p1=str1;
	p2=str2;
	
	printf("Input:");
	gets(p2);
	
	for(;*p2!=0;p1++,p2++)
	{
		*p1=*p2;
	}
	*p1='\0';
	printf("\n¸´ÖÆºóµÄ×Ö·û´®:%s",str1);
} 
