#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
	int imagic,guess,counter=0,q;
    srand(time(NULL));
	imagic=rand()%100+1;
	int i;
	int p=1;
	
	printf("友情提示，本猜数系统只有十次机会\n"); 
	
	for(i=1;;i++)
	{
	do{ 
		printf("\nInput an imagic number:");
		scanf("%d",&guess);
		counter++;
		q=0;
		int e;
		
	  if(guess>imagic)
	  {
	    printf("\nwrong!too high!\n");
	    printf("counter=%d\n\n",counter);
	    
	    printf("想终止本次猜数请按2，否则请输入1，继续您的猜测：");
	    scanf("%d",&e);
	    if(e==2)
	        break;
	 
      }     
	  else if(guess<imagic)
   	  {
	    printf("\nwrong!too small!\n");
	    printf("counter=%d\n\n",counter);
	    
	    printf("想终止本次猜数请按2，否则请输入1，继续您的猜测：");
	    scanf("%d",&e);
	    if(e==2)
	        break;
	
      }  
	  else if(guess=imagic)
	  {
	    printf("\nyou are right!good!\n");
	    printf("counter=%d\n\n",counter);
      }
      else 
      {
      	q=1;
	  }
      
    }while(guess!=imagic&&counter<10);
    
    if(q==1)
        printf("Sorry,game out.\n")	;
    
    printf("\n重新启动程序请输入1，退出程序请输入2\n\n");
    scanf("%d",&p);
    
    if(p==2)
       break;
    else
       printf("\n游戏再次开始!\n");
    }
        
    printf("\n欢迎下次使用！");
}
