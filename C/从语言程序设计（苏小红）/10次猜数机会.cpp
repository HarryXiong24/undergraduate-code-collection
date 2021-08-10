
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
	int imagic,guess,counter=0;
    srand(time(NULL));
	imagic=rand()%100+1;
	printf("友情提示，本猜数系统只有十次机会\n\n"); 
	do{ 
		printf("Input an imagic number:");
		scanf("%d",&guess);
		counter++;
	if(guess>imagic)
	{
	    printf("\nwrong!too high!\n");
	    printf("counter=%d\n\n",counter);
    }  
	else if(guess<imagic)
	{
	    printf("\nwrong!too small!\n");
	    printf("counter=%d\n\n",counter);
    }  
	else
	{
	    printf("\nyou are right!good!\n");
	    printf("counter=%d\n\n",counter);
    }
      }while(guess!=imagic&&counter<10);
	printf("Sorry,game out.\n")	;
}
