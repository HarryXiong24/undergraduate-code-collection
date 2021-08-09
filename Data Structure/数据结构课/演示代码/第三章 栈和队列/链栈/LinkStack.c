/*
 *  文件名：LinkStack.c
 *	链栈的实现
 *	版本：1.0
 *	时间：2016.09.26
 *	作者：wangx
 *	假定条件： 假设元素的基本类型为int，且每个元素只有一个整数信息需要压栈
 *			
*/

#include "malloc.h" 
#include "stdio.h"

#define PARAM_ERROR -1
#define MALLOC_ERROR -2

typedef  int TElemType;
typedef struct SNode
{
	TElemType data;
   struct SNode *next;
}StackNode;

typedef struct 
{
	StackNode *Top; //一重指针，指向栈顶结点
}LinkStack, *PLinkStack; //PLinkStack是二重指针，等效于LinkStack *
//此处定义了一个链栈类型，叫LinkStack，该结构只有一个数据成员，即一个指向栈顶结点的指针Top
//因为链栈中不设置表头结点，也不需要栈底指针，所以只有一个Top指针变量来指向栈顶元素即可。同学们可以自行添加栈的其他辅助信息到这个结构里面，例如栈的当前深度之类的

 //初始化链栈，只需要将Top指针置空即可
 //子函数内改变Top指针的值，故形参为二级指针
int InitStack(LinkStack **ppStack)
{
   if (*ppStack== NULL) //参数校验，该二级指针必须要指向主调函数中的一个LinkStack *类型的指针变量，即该二级指针指向的东西必须存在！
		return PARAM_ERROR;

	*ppStack= (LinkStack*)malloc(sizeof(LinkStack));
	(*ppStack)->Top= NULL;
	return 0;
}

int ClearStack(LinkStack *pStack)
{
	StackNode *pTemp, *pNext;

	if (pStack== NULL)
		return PARAM_ERROR; //栈如果不存在，返回错误码。注意，空栈的状态是允许的，即允许pStack->Top==NULL

	pTemp= pStack->Top;
	while(pTemp!= NULL)
	{
		pNext= pTemp->next; 
		free(pTemp);
		pTemp= pNext;
	}
	return 0;
}

//因为链栈无表头，所以清空和销毁操作是同样的操作
int DestroyStack(LinkStack **ppStack)
{
   if (*ppStack== NULL)
		return PARAM_ERROR; //栈如果不存在，返回错误码。注意，空栈的状态是允许的，即允许pStack->Top==NULL

	ClearStack(*ppStack);
	free(*ppStack);
	*ppStack= NULL;
	return 0;
}

int Push(LinkStack *pStack, TElemType Value)
 {
   StackNode *p;
   if (pStack== NULL)
		return PARAM_ERROR; //栈如果不存在，返回错误码。注意，空栈的状态是允许的，即允许pStack->Top==NULL
   p=(StackNode *)malloc(sizeof(StackNode));
   if(!p)
     return MALLOC_ERROR;
   p->data=Value;
   //头插法入栈
   p->next=pStack->Top;  
   pStack->Top=p;
   
   return 0;
 }

int Pop(LinkStack *pStack, TElemType *pValue)
{
	StackNode *p;
	if (pStack== NULL || pStack->Top == NULL || pValue==NULL) 
		return PARAM_ERROR; //空栈无数据可返回，返回错误码
	p= pStack->Top;  //临时指针指向栈顶结点
	pStack->Top= pStack->Top->next;  //调整栈顶指针，指向下一个结点（出栈后的新栈顶结点）

	*pValue= p->data;  //将原栈顶结点的数据值取出，返回给主调函数使用
	free(p);  //销毁原栈顶结点
	p=NULL;
	return 0;
}

//判断一个栈是否为空栈
int IsStackEmpty(LinkStack *pStack)
{
	if (pStack==NULL) //参数校验
		return PARAM_ERROR;

	if (pStack->Top == NULL) //如果是空栈
		return 1;  //空栈返回1
	else
		return 0;

}

int main()
{
	TElemType value;
	LinkStack *pStack;
	InitStack(&pStack);
	Push(pStack, 10);
	Push(pStack, 20);
	Push(pStack, 30);
	Push(pStack, 40);
//	DestroyStack(&pStack);

	while (!IsStackEmpty(pStack))
	{
		Pop(pStack, &value);
		printf("%d  ", value);
	}
	DestroyStack(&pStack);
	return 0;
}