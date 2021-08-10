#include<stdio.h>
int bank(int o);

int main()
{
    int key,i,j;
	int q;
	int o;
	
	printf("欢迎您使用XHW银行ATM系统！\n相信本系统会给您完美的体验！\n\n\n") ; 
	
	printf("您有三次机会输入密码\n");
	printf("请输入6位数的密码:");
	scanf("%d",&key);
	
    
    for(i=1;i<3;i++)
    {
	    j=key;
		if(j==123456)
		{
		   q=1; 
		   printf("\n密码正确，成功进入！\n");
		   break;
 	    }
 	    else
		{    
		    q=0;
		    printf("\n密码错误！请再次输入:");
		    scanf("%d",&key);
	    }
    }
    
    if(j==123456)
	    bank(o);
	else
	{
	    printf("\n您的卡已经被冻结！\n");
        printf("\n请到XHW银行解冻！");
    }
    
	return 0;
}
	  
	  
	  
int bank(int o)
{
	int key,i,j;
	int q;
	
	if(q=1)
	{ 
    int a,m,x,y;
    printf("\n\n请您进行选择：\n");
    printf("1、查询余额\n2、存款\n3、取款\n4、呼叫人工\n5、退卡\n");
    printf("\n请输入您选择的选项：");
	scanf("%d",&a);
	printf("\n");
	
	if(a==5)
	{
		printf("请取回您的银行卡！欢迎下次使用！"); 
	}
	
	else 
	{
	for(y=1;;y++)
	{
	  switch(a)
      {
		case 1:
			{
				printf("\n您还有余额9999999999999999￥\n");
				break; 
			}
		case 2:
			{
				printf("\n请输入存款金额：");
				scanf("%d",&m);
			
			    if(m>2000)
				    {
				    	printf("\n一次性存款不能大于2000￥\n");
						printf("\n请再一次输入存款金额：") ; 
						scanf("%d",&m);
					}
				
				printf("\n请稍等，正在为您处理！\n");
				printf("\n存款完成！\n");
				break; 
			}
		case 3:
			{
				printf("\n请输入取款金额：");
				scanf("%d",&m);
				
				if(m>2000)
				    {
				    	printf("\n一次性取款不能大于2000￥\n");
						printf("\n请再一次输入取款金额：") ; 
						scanf("%d",&m);
					}
	
				printf("\n请稍等，正在为您处理！\n");
				printf("\n请取走您的现金!\n");
				break;
			}
		case 4:
			{
				printf("请稍等，正在为您拨号！\n"); 
				break; 
			}
       }
	    printf("\n请您继续选择：\n");
	    printf("1、查询余额\n2、存款\n3、取款\n4、呼叫人工\n5、退卡\n");
        printf("\n请输入您选择的选项：");
	    scanf("%d",&a);
	    printf("\n");  
	    
	    if(a==5)
      	{
		      printf("请取回您的银行卡！欢迎下次使用！"); 
		      break;
	    }
    }
    }
    }   
    return 1;
}
