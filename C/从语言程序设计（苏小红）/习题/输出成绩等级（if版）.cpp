/*输出等级成绩*/
#include<stdio.h>
int main()
{
	float score;
	printf("Input a score(0~100):");
	scanf("%f",&score);
	if(score>=90)
	  printf("A");
	else if(score>=80&&score<90)
	  printf("B");
	else if(score>=70&&score<70)
	  printf("C");
	else if(score>=60&&score<70)
	  printf("D");
	else
	  printf("Sorry,you are F!");
 } 
