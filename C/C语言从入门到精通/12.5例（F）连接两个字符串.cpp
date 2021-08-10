#include<stdio.h>
int main()
{
	char a[]="12345";
	char b[]="abcde";
	char c[80];
	
	int i=0,j=0,k=0;
	while(a[i]!='\0'||b[j]!='\0')
	{
		if(a[i]!='\0')
		{
			c[k]=a[i];
			i++;
		}
	    else
		{
			c[k]=b[j++];
			k++;
		}
	}
	c[k]='\0';
	puts(c);
	
}
