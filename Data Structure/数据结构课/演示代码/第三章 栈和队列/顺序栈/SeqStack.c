/*
 *  文件名：SeqStack.c
 *	顺序栈的实现
 *	版本：1.0
 *	时间：2016.09.26
 *	作者：wangx
 *	假定条件： 假设元素的基本类型为结构体类型Node，内含3个整数int成员
 *			
*/


#include "stdio.h"   //主要是为了能够使用printf和scanf
#include "malloc.h"  //为了能使用malloc函数

#define PARAM_ERROR -1
#define MALLOC_ERROR -2
#define STACK_INIT_SIZE 100 //顺序栈初始分配的元素个数容量（以Node为单位的哦）
#define STACKINCREMENT 20   //存储空间分配增量(出现上溢时增加分配的元素个数)

 typedef struct Node
 {
   int ii; 
   int jj; 
   int kk; 
 }Node; //栈的每个元素的数据类型，同学们可以思考一下，如何支持对指针类型的压栈和出栈

 //创建了一个新类型“顺序栈”，不占内存
 typedef struct SeqStack
 {
   Node *Base; // 栈底指针，标志着一个顺序栈是否存在。在栈构造之前和销毁之后，Base的值为NULL
   Node *Top;  // 栈顶指针，指向当前的栈顶元素（存储当前栈顶元素的首地址）
   int stacksize; //当前能存储的最多元素个数，本例以Node为单位
 }SeqStack; 

 /* 构造一个空的顺序栈结构，并让实参指针指向该结构 */
int InitStack(SeqStack **ppStack)
{ 
	*ppStack= (SeqStack *)malloc( sizeof(SeqStack) );
	if (*ppStack == NULL)
		return MALLOC_ERROR;
	(*ppStack)->Base=(Node *)malloc( STACK_INIT_SIZE * sizeof(Node) );
	if(!(*ppStack)->Base)
	{
		free(*ppStack);  //把栈结构释放了
		return MALLOC_ERROR;
	}
	(*ppStack)->Top = (*ppStack)->Base;
	(*ppStack)->stacksize = STACK_INIT_SIZE;
	return 0;
}

/* 销毁顺序栈，*ppStack指向的栈结构体变量本身以及顺序存放的数据区域都不再存在 */
int DestroyStack(SeqStack **ppStack)
{
	//参数校验，要销毁，先要有栈才能销毁
	if (*ppStack == NULL)
		return PARAM_ERROR;

	if ((*ppStack)->Base != NULL) //这个if条件一般来说是废话，有栈的话，Base指针一般不可能会为NULL，
								  //但最好还是写一下，稳妥点，健壮点。一般调用free来释放任何空间之前都最好是判断一下。
		free((*ppStack)->Base);
	(*ppStack)->Base=NULL;
	(*ppStack)->Top=NULL;
	(*ppStack)->stacksize=0;
   return 0;
}

// 把pStack指向的栈结构设置为空栈，只需要调整Top指针即可，无需清空数据
int ClearStack(SeqStack *pStack)
{ 
	if (pStack == NULL)
		return PARAM_ERROR;

	pStack->Top = pStack->Base;
	return 0;
}

// 若栈S为空栈，则返回1，否则返回0 
int IsStackEmpty(SeqStack *pStack)
{
	if (pStack == NULL)
		return PARAM_ERROR;

   if(pStack->Top==pStack->Base)
     return 1;
   else
     return 0;
 }

// 返回S的元素个数，即栈的长度
int StackLength(SeqStack *pStack)
{
	if (pStack == NULL)
		return PARAM_ERROR;

	return pStack->Top - pStack->Base;  //还记得两个指针的相减是什么意思么？当他们都指向同一块内存区域中的不同元素时
}

//将元素压栈
 int Push(SeqStack *pStack, Node Value)
 { 
	if(pStack->Top - pStack->Base >= pStack->stacksize) //栈满，追加存储空间
	{
		pStack->Base=(Node *)realloc( pStack->Base, (pStack->stacksize+STACKINCREMENT)*sizeof(Node) );
		if(pStack->Base == NULL)
			return MALLOC_ERROR; 
		pStack->Top = pStack->Base + pStack->stacksize;
		pStack->stacksize += STACKINCREMENT;
	}
	//本例是假定先存储，然后指针再前进。所以在后续的出栈操作中就必须要先后退，再读取
	pStack->Top->ii=Value.ii; 
	pStack->Top->jj=Value.jj;
	pStack->Top->kk=Value.kk;
	pStack->Top++;
	return 0;
}

//出栈，并将栈顶元素的值提取出来给主调函数使用
//若栈不空，则弹出（逻辑上而言）栈的栈顶元素，用*pValue存储其值，并返回0；否则返回-1
int Pop(SeqStack *pStack, Node *pValue)
{ 
	if(pStack->Top==pStack->Base || pValue==NULL)
		return PARAM_ERROR;

	pStack->Top--; //Top指针回退一格
	pValue->ii=pStack->Top->ii; 
	pValue->jj=pStack->Top->jj;
	pValue->kk=pStack->Top->kk;
	return 0;
}

int main()
{
	Node value;
	SeqStack *pStack;
	InitStack(&pStack);
	value.ii= 10;
	value.jj= 11;
	value.kk= 12;
	Push(pStack, value);
	value.ii= 20;
	value.jj= 21;
	value.kk= 22;
	Push(pStack, value);
	value.ii= 30;
	value.jj= 31;
	value.kk= 32;
	Push(pStack, value);
	value.ii= 40;
	value.jj= 41;
	value.kk= 42;
	Push(pStack, value);
//	DestroyStack(&pStack);

	while (!IsStackEmpty(pStack))
	{
		Pop(pStack, &value);
		printf("%d  %d   %d\n", value.ii, value.jj, value.kk);
	}
	DestroyStack(&pStack);
	return 0;
}