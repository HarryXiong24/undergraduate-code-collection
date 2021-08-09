#include<stdio.h>
#include<stdlib.h>

//链式栈的系列操作
typedef int DataType;

//链栈的结点类型 
typedef struct node{
	DataType data;
	struct node *next;
}SNode;

//链栈的结构类型
typedef struct{
	SNode *top;
}LinkStack;

//初始化
void initStack(LinkStack *LS)
{
	LS->top = NULL;	
} 

//清空栈
void clearStack(LinkStack *LS) 
{
	SNode *p = NULL;
	SNode *q = NULL;
	
	q = LS->top;
	while(q != NULL)
	{
		p = q;                         //待清除结点 
		q = q->next;
		free(p); 
	}
	LS->top = NULL;
}

//读取栈顶元素
void getTop(LinkStack *LS) 
{
	if(LS->top == NULL)
	{
		printf("空栈!\n");
		exit(1);
	}
	else
	{
		printf("%d",LS->top->data);
	}
}

//检查栈是否为空
int isEmpty(LinkStack *LS)
{
	return (LS->top == NULL);
}

//入栈
void push(LinkStack *LS, DataType elem)
{
	SNode *t = NULL;
	t = (SNode *)malloc(sizeof(SNode));
	if( t== NULL )
	{
		printf("内存分配错误!\n");
		exit(1);
	}
	t->data = elem;
	t->next = LS->top;
	LS->top = t;
} 

//出栈
void pop(LinkStack *LS) 
{
	SNode *t;
	if(LS->top == NULL)
	{
		printf("栈空!\n");
		exit(1);
	}
	t = LS->top;
	printf("%d\n",t->data);
	LS->top = LS->top->next;
	free(t);
}

//测试代码 
int main()
{
	LinkStack LS;
	
	initStack(&LS);
	push(&LS, 5);
	pop(&LS); 
	push(&LS, 3);
	getTop(&LS);
}
 
