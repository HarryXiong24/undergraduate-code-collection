#include <stdio.h>
#include <stdlib.h> 

#define QElemtype int 

typedef struct node{
	QElemtype data;
	struct node *next;
}QNode;

typedef struct{
	QNode *front;
	QNode *rear;
}LinkQueue;


int initQueue(LinkQueue **ppQ)
{
	LinkQueue *pTemp;
	
	pTemp = (LinkQueue *)malloc(sizeof(LinkQueue));
	
	if(pTemp == NULL)
	{
		return -1;
	}
	
	pTemp->front = pTemp->rear = (QNode *)malloc(sizeof(QNode));
	if(pTemp->front == NULL)
	{
		return -2;
	}
	
	pTemp->front->next = NULL;
	
	*ppQ = pTemp;
	
	return 0;
}

int clearQueue(LinkQueue *pQ)
{
	QNode *p1,*p2;
	
	p1 = pQ->front->next;
	
	while(p1 != NULL)
	{
		p2 = p1;
		p1 = p1->next;
		free(p2);
	}
	
	pQ->front->next = NULL;              //表头指针要归位
	pQ->front = pQ->rear;                //指针也要归位 
	 
	return 0; 
}

int delQueue(LinkQueue **ppQ)
{
	clearQueue(*ppQ);
	
	free((*ppQ)->front);
	free(*ppQ);
	*ppQ = NULL;
	
	return 0;
}

int QueueIsEmpty(LinkQueue *pQ)
{ 
    if (pQ == NULL) 
		return -1;
    if(pQ->front == pQ->rear)
        return 1;
    else
        return 0;
}

int GetQueueLength(LinkQueue *pQ)
{
	QNode *pTemp;
	int i = 0;
	
	pTemp = pQ->front->next;
	
	while(pTemp != NULL)
	{
		pTemp = pTemp->next;
		i++;
	}
	
	return i;
}

int enQueue(LinkQueue *pQ, QElemtype value)
{
	QNode *pnew = (QNode *)malloc(sizeof(QNode));
	
	if (pQ==NULL) 
		return -1;
		
	if(!pnew) 
		return -2; 
		 	
	pnew->data = value;
	pnew->next = NULL;
	  
	pQ->rear->next = pnew;
	pQ->rear = pnew; 
	
	return 0;
}

int deQueue(LinkQueue *pQ)
{
	QNode *pTemp;
	
	if(pQ == NULL) 
		return -1;
	if(pQ->front == pQ->rear) 
		return -2;  
		
	pTemp = pQ->front->next;
	pQ->front->next = pTemp->next;
	
	if(pTemp == pQ->rear)
	{
		pQ->rear = pQ->front;
	}
	
	free(pTemp);
	
	return 0;
}

int GetQueueHead(LinkQueue *pQ, QElemtype *value)
{
    if(QueueIsEmpty(pQ) != 0)
        return -1;
        
    *value = pQ->front->next->data;
    return 0;
}

int main()
{
	LinkQueue *pQ = NULL;
	int value;
	int len;
	
	initQueue(&pQ);
	
	enQueue(pQ, 10);
	enQueue(pQ, 2);
	enQueue(pQ, 3);
	enQueue(pQ, 4);
	enQueue(pQ, 5);
	
	len = GetQueueLength(pQ);
	printf("The lenth is %d.\n", len);
	
	GetQueueHead(pQ, &value);
	printf("%d\n", value);
	deQueue(pQ);
	
	GetQueueHead(pQ, &value);
	printf("%d\n", value);
	deQueue(pQ);
	
	GetQueueHead(pQ, &value);
	printf("%d\n", value);

	
	delQueue(&pQ);
	
	return 0;
}













