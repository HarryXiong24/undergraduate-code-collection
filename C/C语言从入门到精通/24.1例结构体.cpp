#include<stdio.h>
int main()
{
	
struct student
  {
	char name[10];
	char sex;
	int  age;
	float score;
  }stu[5];
  
  int i;
  printf("Input messages:");
  for(i=0;i<5;i++)
  {
  	scanf("%s %c,%d,%f",&stu[i].name,&stu[i].sex,&stu[i].age,&stu[i].score);   //%s会把逗号也当成字符读进去 
  }
  
  printf("输出女性的数据：\n");
  for(i=0;i<5;i++)
  {
  	 if(stu[i].sex=='w')
	    printf("%s,%d,%f\n",stu[i].name,stu[i].age,stu[i].score);    
  }
  
}

