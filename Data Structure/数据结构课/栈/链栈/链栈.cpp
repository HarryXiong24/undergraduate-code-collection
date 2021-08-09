#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100 
#define STACKINCREMENT 20 

//´íÎóÂë 
#define PARAM_ERROR -1
#define NOTFIND  -2
#define MALLOC_ERROR  -3  
#define CANNOT_DEL  -4

typedef struct node
{
	int ii;
	int jj;
	int kk;
	struct node *next;
}Node;

typedef struct LinkStack{
	Node *top;
}LStack;

int createLinkStack(LStack **pStack)
{
	*pStack = (LinkStack *)malloc(sizeof(LinkStack));
	if(!(*pStack))
	{
		return MALLOC_ERROR;
	}
	
	(*pStack)->top = NULL;
	return 0;
}

int DestroyLinkStack(LStack **pStack)
{
	Node *pTemp1 = NULL;
	Node *pTemp2 = NULL;
	
	if((*pStack) == NULL)
	{
		return PARAM_ERROR;
	}
	
	pTemp1 = (*pStack)->top;
	while(pTemp1 != NULL)
	{
		pTemp2 = pTemp1;
		pTemp1 = pTemp1->next;
		free(pTemp2);
		pTemp2 = NULL;
	}
	
	free(*pStack);
	*pStack = NULL;
	
	return 0;
}

int IsEmpty(LStack *pStack)
{
	if(pStack->top == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Push(LStack *pStack, Node *value)
{
	Node *pNew;
	
	if(pStack == NULL)
	{
		return PARAM_ERROR;
	}
	
	pNew = (Node *)malloc(sizeof(Node));
	if(!pNew)
	{
		return MALLOC_ERROR;
	}
	
	pNew->ii = value->ii;
	pNew->jj = value->jj;
	pNew->kk = value->kk;
	pNew->next = NULL;
	
	pNew->next = pStack->top;
	pStack->top = pNew;
	
	return 0;
}

int Pop(LinkStack *pStack, Node *value)
{
	Node *pTemp;
	
	if(pStack == NULL || pStack->top == NULL)
	{
		return PARAM_ERROR;
	}
	
	pTemp = pStack->top;
	pStack->top = pTemp->next;
	
	value->ii = pTemp->ii;
	value->jj = pTemp->jj;
	value->kk = pTemp->kk;
	
	free(pTemp);
	
	return 0;
}

int main()
{
	LStack *L;
	Node value;
	
	createLinkStack(&L);
	
	value.ii = 10;
	value.jj = 11;
	value.kk = 12;
	Push(L, &value);
	
	value.ii = 20;
	value.jj = 21;
	value.kk = 22;
	Push(L, &value);
	
	value.ii = 30;
	value.jj = 31;
	value.kk = 32;
	Push(L, &value);
	
	value.ii = 40;
	value.jj = 41;
	value.kk = 42;
	Push(L, &value);
	
	while (!IsEmpty(L))
	{
		Pop(L, &value);
		printf("%d,%d,%d\n", value.ii, value.jj, value.kk);
	}
	DestroyLinkStack(&L);
	return 0;
	
}

















