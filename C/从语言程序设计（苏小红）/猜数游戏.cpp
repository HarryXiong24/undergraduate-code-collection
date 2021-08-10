#include<stdio.h>
#include<stdlib.h> 
main()
{
	int imagic,guess;
	int counter=0;
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
