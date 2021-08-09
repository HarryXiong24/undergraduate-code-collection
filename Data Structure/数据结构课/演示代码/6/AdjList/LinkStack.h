
#include "malloc.h" 
#include "stdio.h"

typedef struct SNode
 {
     int adjVexNo;
	 LinkListNode *p;
     struct SNode *next;
 }SNode,*SNodePtr;

 typedef struct LinkStack
 {
	 SNodePtr Top;
	 int depth;
 }LinkStack;


int InitStack(LinkStack **ppS)
{
	(*ppS)= (LinkStack *)malloc(sizeof(LinkStack));
	if (*ppS==NULL) return -1;
	(*ppS)->Top= NULL;
	(*ppS)->depth= 0;
	return 0;
}

int ClearStack(LinkStack *pS)
{
	SNodePtr p;
	if (pS==NULL) return -1;
	while(pS->Top!= NULL)
	{
		p= pS->Top;
		pS->Top= pS->Top->next;
		free(p);
	}
	return 0;
}

int DestroyStack(LinkStack **ppS)
{
	ClearStack(*ppS);
	free(*ppS);
	*ppS=NULL;
	return 0;
}

int GetStackTop(LinkStack *pS, int *padjVexNo, LinkListNode **pp)
{
    if (pS== NULL) return -1;
	if (pS->Top == NULL) return -2;

	*padjVexNo= pS->Top->adjVexNo;
	*pp = pS->Top->p;
	return 0;
}

int Push(LinkStack *pS, int adjVexNo, LinkListNode *p)
 {
   SNodePtr temp;
   if (pS==NULL) return -1;
   temp=(SNodePtr)malloc(sizeof(SNode));
   if(!temp) return -2;
   temp->adjVexNo=adjVexNo;
   temp->p= p;

   temp->next= pS->Top;
   pS->Top=temp;
   return 0;
 }

int Pop(LinkStack *pS, int *padjVexNo, LinkListNode **pp)
{
	SNodePtr temp;
    if (pS== NULL) return -1;
	if (pS->Top == NULL) return -2;
	temp= pS->Top;
	pS->Top= pS->Top->next;

	*padjVexNo= temp->adjVexNo;
	*pp = temp->p;
	free(temp);
	return 0;
}

int StackIsEmpty(LinkStack *pS)
{
	if (pS==NULL) return -1;
	if (pS->Top == NULL)
		return 1;
	else
		return 0;

}