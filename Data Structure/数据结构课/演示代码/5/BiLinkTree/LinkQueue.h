/*
    链队列定义和实现文件
*/
#include "BiTree.h"
#include "malloc.h" 
#include "stdio.h"

//链队列的存储基本载体是链表，定义QNode为链表结点类型，QueuePtr为指向链表结点的指针类型
typedef struct QNode   
{
	/*二叉链表的非递归创建函数要求的链队列，其存储的基本元素类型
	是指向某个二叉链表结点的指针类型，即BiTNode *, 所以成员pData如下定义    */
	BiTNode *pData;      
	struct QNode *next;
}QNode,*QueuePtr;

//一个链队列结构体，含有2个成员，队头指针和队尾指针，都是QueuePtr类型
typedef struct
{
	QueuePtr front, rear;
}LinkQueue;
 

int InitQueue(LinkQueue *Q)
{
	(*Q).front=(*Q).rear=(QueuePtr)malloc(sizeof(QNode));
	if(!(*Q).front)
		return -1;
	(*Q).front->next=NULL;
	return 0;
}

int DestroyQueue(LinkQueue *Q)
{
   while((*Q).front)
   {
     (*Q).rear=(*Q).front->next;
     free((*Q).front);
     (*Q).front=(*Q).rear;
   }
   return 0;
}

int ClearQueue(LinkQueue *Q)
{
   QueuePtr p,q;
   (*Q).rear=(*Q).front;
   p=(*Q).front->next;
   (*Q).front->next=NULL;
   while(p)
   {
     q=p;
     p=p->next;
     free(q);
   }
   return 0;
}

 int QueueIsEmpty(LinkQueue Q)
 { 
   if(Q.front==Q.rear)
     return 1;
   else
     return 0;
 }

 int GetHead_Q(LinkQueue Q, BiTNode **e)
 {
   QueuePtr p;
   if(Q.front==Q.rear)
     return -1;
   p=Q.front->next;
   *e=p->pData;
   return 0;
 }

 int EnQueue(LinkQueue *Q, BiTNode *e)
 {
   QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
   if(!p)
     return -1;
   p->pData=e;
   p->next=NULL;
   (*Q).rear->next=p;
   (*Q).rear=p;
   return 0;
 }

 int DeQueue(LinkQueue *Q, BiTNode **e)
 {
   QueuePtr p;
   if((*Q).front==(*Q).rear)
     return -1;
   p=(*Q).front->next;
   *e=p->pData;
   (*Q).front->next=p->next;
   if((*Q).rear==p)
     (*Q).rear=(*Q).front;
   free(p);
   return 0;
 }

