#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
	int imagic,guess,counter=0;
    srand(time(NULL));
	imagic=rand()%100+1;
	do{ 
		printf("Input an imagic number:");
		scanf("%d",&guess);
		counter++;
	if(guess>imagic)
	    printf("wrong!too high!\n");
	else if(guess<imagic)
	    printf("wrong!too small!\n");
	else
	    printf("you are right!good!\n");
      }while(guess!=imagic);
    printf("counter=%d\n",counter) ;	
}
