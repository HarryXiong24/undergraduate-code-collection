/*Çó¸¶·Ñ½ð¶î*/
#include<stdio.h>
int main()
{
	float count,pay;
	printf("Input your count:(kg)");
	scanf("%f",&count);
	if(count<10)
	  pay=count*8.5;
	else
	  pay=count*6.5;
	printf("You should pay:%f\n",pay); 
return 0;	
}
 
