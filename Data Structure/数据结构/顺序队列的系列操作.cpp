#include<stdio.h>
#include<stdlib.h>

//顺序队列的系列操作
typedef int Datatype;
#define MaxSize 200
typedef struct{
	Datatype stack[MaxSize];
	int front;                              //头,在第一个元素之前的位置 
	int rear;	                            //尾，在最后一个元素的位置 
}SeqQueue;


//初始化
void initQueue(SeqQueue *q)
{
	q->front = -1;
	q->rear = -1;
}

//清空队列
void clearQueue(SeqQueue *q)
{
	q->front = -1;
	q->rear = -1;
}

//读取队列头元素
void getTop(SeqQueue *q)
{
	if(q->front == q->rear)
	{
		printf("队列为空!\n");
		exit(1);
	}

	printf("%d\n",q->stack[q->front + 1]);
}

//检查队列是否为空
int isEmpty(SeqQueue *q)
{
	return (q->front == q->rear);	
} 

//入队
void InsQueue(SeqQueue *q, Datatype elem)
{
	if(q->rear == MaxSize - 1)
	{
		printf("队列已满!\n");
		exit(1);
	}
	
	q->rear++;
	q->stack[q->rear] = elem;
}

//出队
void delQueue(SeqQueue *q) 
{
	if(q->front == q->rear)
	{
		printf("队列为空!\n");
		exit(1);
	}
	
	q->front++;
	printf("%d\n",q->stack[q->front]);
}

//测试代码 
int main()
{
	SeqQueue q;
	
	InsQueue(&q, 5);
	InsQueue(&q, 10);
	getTop(&q);
	delQueue(&q);
	getTop(&q);	
}












 












