
#include "malloc.h" 
#include "stdio.h"

typedef struct QNode
 {
   int adjVexNo;
   struct QNode *next;
 }QNode,*QueuePtr;

 typedef struct
 {
   QueuePtr front,rear;
 }LinkQueue;
 

int InitQueue(LinkQueue **ppQ)
{
    *ppQ= (LinkQueue *)malloc(sizeof(LinkQueue));
	if (*ppQ==NULL) return -1;
    (*ppQ)->front=(*ppQ)->rear=(QueuePtr)malloc(sizeof(QNode));
    if((*ppQ)->front==NULL) return -1;
    (*ppQ)->front->next=NULL;
    return 0;
}

int ClearQueue(LinkQueue **ppQ)
{
	QNode *p, *q;
	if (ppQ==NULL) return -1;
	p= (*ppQ)->front->next;
    while(p!= NULL)
    {
        q=p->next;
        free(p);
        p=q;
    }
    (*ppQ)->front->next= NULL;
    (*ppQ)->rear= (*ppQ)->front;
    return 0;
}

int DestroyQueue(LinkQueue **ppQ)
{
	if (ClearQueue(ppQ)==-1) return -1;
	free((*ppQ)->front);
	free(*ppQ);
	*ppQ= NULL;
    return 0;
}

int QueueIsEmpty(LinkQueue *pQ)
{ 
	if (pQ==NULL) return -1;
    if(pQ->front==pQ->rear)
        return 1;
    else
        return 0;
}

int GetQueueHead(LinkQueue *pQ, int *padjVexNo)
{
    QueuePtr p;
    if (pQ==NULL) return -1;
    if(pQ->front==pQ->rear) return -2;
    p=pQ->front->next;
    *padjVexNo=p->adjVexNo;
    return 0;
}

int EnQueue(LinkQueue *pQ, int adjVexNo)
{
    QueuePtr p;
    if (pQ==NULL) return -1;
    p=(QueuePtr)malloc(sizeof(QNode));
    if(p==NULL) return -2;
    p->adjVexNo=adjVexNo;
    p->next=NULL;
    pQ->rear->next=p;
    pQ->rear=p;
    return 0;
}

int DeQueue(LinkQueue *pQ, int *padjVexNo)
{
    QueuePtr p;
    if (pQ==NULL) return -1;
    if(pQ->front==pQ->rear) return -2;
    p=pQ->front->next;
    if(p==pQ->rear)
        pQ->rear=pQ->front;
    *padjVexNo=p->adjVexNo;
    pQ->front->next=p->next;
    free(p);
    return 0;
}

