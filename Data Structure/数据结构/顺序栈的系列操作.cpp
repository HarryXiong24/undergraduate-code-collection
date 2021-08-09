#include<stdio.h>
#include<stdlib.h>

//顺序栈的系列操作
#define MaxSize 200
typedef int Datatype;

//栈的定义 
typedef struct{
	Datatype stack[MaxSize];                        
	int top;                                        //栈顶指针 
}SeqStack;

//栈的初始化
void initStack(SeqStack *s)
{
	s->top = -1;	
} 

//清空栈 
void clearStack(SeqStack *s)
{
	s->top = -1;
}

//读取栈顶元素
void getTop(SeqStack *s) 
{
	if(s->top == -1)
	{
		printf("栈空!\n");
		exit(1);
	}
	else
	{
		printf("%d\n",s->stack[s->top]);
	}
}

//检查栈是否为空
int isEmpty(SeqStack *s) 
{
	return (s->top == -1);
}

//入栈
void push(SeqStack *s, Datatype elem)
{
	if(s->top == MaxSize-1)
	{
		printf("栈满溢出!\n");
		exit(1);
	}
	s->top++;
	s->stack[s->top] = elem;
} 

//出栈
void pop(SeqStack *s) 
{
	if(s->top == -1)
	{
		printf("栈空!\n");
		exit(0);
	}
	printf("%d",s->stack[s->top]);
	s->top--;
}

//测试代码
int main()
{
	SeqStack s;
	initStack(&s);
	
	push(&s, 3);
	pop(&s);
	push(&s, 5);
	
} 
