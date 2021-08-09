
#include "BiTree.h"
#include "malloc.h" 
#include "stdio.h"

typedef struct SNode
 {
   BiTNode *data;
   struct SNode *next;
 }SNode,*SNodePtr;

 typedef struct LinkStack
 {
	 SNodePtr Top;
 }LinkStack;


int InitStack(LinkStack *S)
{
	S->Top= NULL;
	return 0;
}

int DestroyStack(LinkStack *S)
{
	SNodePtr p;
	while(S->Top!= NULL)
	{
		p= S->Top;
		S->Top= S->Top->next;
		free(p);
	}
	return 0;
}

int ClearStack(LinkStack *S)
{
	DestroyStack(S);
	return 0;
}

int Push(LinkStack *S, BiTNode *e)
 {
   SNodePtr p=(SNodePtr)malloc(sizeof(SNode));
   if(!p)
     return -1;
   p->data=e;
   p->next=S->Top;
   S->Top=p;
   
   return 0;
 }

int Pop(LinkStack *S, BiTNode **e)
{
	SNodePtr p;
	if (S->Top == NULL) return -1;
	p= S->Top;
	S->Top= S->Top->next;

	*e= p->data;
	free(p);
	return 0;
}

int StackIsEmpty(LinkStack *S)
{
	if (S->Top == NULL)
		return 1;
	else
		return 0;

}

int GetTop(LinkStack *S, BiTNode **e)
{
	*e= S->Top->data;
	return 0;
}