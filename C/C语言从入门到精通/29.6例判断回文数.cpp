#include<stdio.h> 
#include<string.h>
int is_sym(char *s); 

int main()
{
	char s[80];
	printf("Input:");
	gets(s);
	if(is_sym(s))
	   printf("Yes\n");
	else
	   printf("No\n");
}

int is_sym(char *s)
{
	int i=0,j=strlen(s)-1;
	while(i<j)
	{
		if(s[i]!=s[j])
		    return 0;
		else
		    i++;
		    j--;
	}
}
