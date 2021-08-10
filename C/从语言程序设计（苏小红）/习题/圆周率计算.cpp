#include<stdio.h>
#define PI 3.14159 
main()
{
	double r;
	printf("Input r:");
	scanf("%lf",&r);
	if(r<0)
	{
	  printf("r<0!You are error!\n");
	  printf("Please input again:");
	  scanf("%lf",&r);
	  printf("cir=%f\n",2*r*PI);
	  printf("area=%f\n",PI*r*r);
    }
	else 
	{
	  printf("cir=%f\n",2*r*PI);
	  printf("area=%f\n",PI*r*r);
    }
}
