/*输出等级成绩*/
#include<stdio.h>
int main()
{
	int score,grade;
	printf("Input a score(0~100):");
	scanf("%d",&score);
    grade=score/10;
    switch(grade)
    {
    	case 10:                      /*注意不能打成“case ：10”，这是错误的。*/ 
    	case 9:
    	printf("A");
    	break;
    	case 8:
    	printf("B");
    	break;
    	case 7:
    	printf("C");
    	break;
    	case 6:
    	printf("D");
    	break;
	}
	if(score<60)
	printf("Sorry,you are F!");
return 0;
}
