#include<stdio.h>
#include<stdlib.h>

//链式队列的系列操作

//定义结点类型 
typedef int Datatype;
typedef struct node{
	Datatype data;
	struct node *next;
}QNode;

//定义结构类型
typedef struct{
	QNode *front;
	QNode *rear;
}LinkQueue;

//初始化
void initQueue(LinkQueue *lq)
{
	lq->front = NULL;
	lq->rear = NULL;
} 

//清空队列
void clearQueue(LinkQueue *lq) 
{
	QNode *tmp;
	
	if( lq->front != lq->rear)
	{
		tmp = lq->front;
		lq->front = tmp->next;
		free(tmp);
	}
	
	free(lq->front);                    //如果头和尾一致
	lq->front = NULL;
	lq->rear = NULL; 
}

//读取队列头元素
void getTop(LinkQueue *lq) 
{	
	if(lq->front == NULL)
	{
		printf("队列为空!\n");
		exit(1);
	} 
	
	printf("%d\n",lq->front->data);
}

//检查队列是否为空
int isEmpty(LinkQueue *lq)
{
	return (lq->front == NULL);
}

//入队
void insQueue(LinkQueue *lq, Datatype elem)
{
	QNode *tmp;
	tmp = (QNode *)malloc(sizeof(QNode));
	
	if(lq->front == tmp)
	{
		printf("内存分配错误1\n");
		exit(1);
	}
	
	tmp->data = elem;
	tmp->next = NULL;
	
	if(lq->rear == NULL)                         //如果原队列为空，则队头和队尾指针都指向新结点 
	{
		lq->rear = tmp;
		lq->front = tmp; 
	}
	else                                         //如果队列不为空，则队尾指针指向新结点 
	{
		lq->rear->next = tmp;
		lq->rear = tmp;
	}
}

//出队
void delQueue(LinkQueue *lq) 
{
	QNode *tmp;
	Datatype out;
	
	if(lq->front == NULL)
	{
		printf("队列为空!\n");
		exit(1);
	}
	
	out = lq->front->data;                   //取出队头元素 
	tmp = lq->front;                      
	lq->front = tmp->next;                   //队头结点的下一个节点成为新的队头结点 
	
	if(lq->front == NULL)
	{
		lq->rear = NULL;
	}
	
	free(tmp);
	
	printf("%d\n",out);
}

//测试代码 
int main() 
{
	LinkQueue lq;
	
	initQueue(&lq);
	insQueue(&lq, 5);
	insQueue(&lq, 10);
	getTop(&lq);
	delQueue(&lq);
	getTop(&lq);
	
}
