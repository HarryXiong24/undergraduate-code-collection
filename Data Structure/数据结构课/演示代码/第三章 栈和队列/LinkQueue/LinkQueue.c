/*
 *  文件名：LinkQueue.c
 *	链队列的实现
 *	版本：1.0
 *	时间：2016.06.26
 *	作者：wangx
 *	假定条件： 假设元素的基本类型为int类型
 *			
*/

//链队列
#include "stdio.h"
#include "malloc.h"
 
typedef int QElemType;         //假设队列元素类型为int，读者可更换为其他类型

typedef struct QNode          //定义单向链表的结点类型名为QNode，并定义指向
{                             //这种类型的指针的类型名称为QueuePtr
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;
/*将队头指针和队尾指针打包封装，定义出新的结构体类型，
  即链队列的数据类型，取名为LinkQueue
*/
typedef struct                
{
    QueuePtr front;           // 队头指针
    QueuePtr rear;            // 队尾指针
}LinkQueue;

//代码3. ---------链队列的创建和初始化操作---------//
//文件名：LinkQueue.c
//以指向LinkQueue结构体的二重指针ppQ为参数，在函数内构建B和C部分，实现关联
int InitQueue(LinkQueue **ppQ)
{ 
    (*ppQ)=(LinkQueue *)malloc(sizeof(LinkQueue));
    if(!(*ppQ))  return -1;
    (*ppQ)->front=(*ppQ)->rear=(QueuePtr)malloc(sizeof(QNode));
    if(!(*ppQ)->front)  return -2;
    (*ppQ)->front->next=NULL;
    return 0;
}

//代码3. ---------链队列的“判断是否为空”操作---------//
//文件名：LinkQueue.c
//以指向LinkQueue结构体的一重指针pQ为参数
// 如果参数有误，返回-1; 若Q为空队列,则返回1,否则返回0 
int QueueIsEmpty(LinkQueue *pQ)
{ 
    if (pQ==NULL) return -1;
    if(pQ->front==pQ->rear)
        return 1;
    else
        return 0;
}

//代码3. ---------链队列的“读取队头元素”操作---------//
//文件名：LinkQueue.c
//以指向LinkQueue结构体的一重指针pQ为参数
// 如果队列存在且非空，获取队头元素的值，以地址传递的方式通过e传出；如果参数有误，返回-1;  
int GetQueueHead(LinkQueue *pQ,QElemType *e)
{
    if(QueueIsEmpty(pQ)!=0)
        return -1;
    *e=pQ->front->next->data;
    return 0;
}

//代码3. ---------链队列的“入队列”操作---------//
//文件名：LinkQueue.c
//以指向LinkQueue结构体的一重指针pQ为参数
// 如果队列不存在或操作异常，返回负数; 反之，成功操作返回0  
int EnQueue(LinkQueue *pQ,QElemType e)
{ 
    QueuePtr R;
    if (pQ==NULL) return -1;
    // 为新进元素e申请结点空间，并让指针R指向。 
    R=(QueuePtr)malloc(sizeof(QNode));
    if(!R) return -2;          //内存申请失败，返回-2
    R->data=e;
    R->next=NULL;
    //进行入队的指针关联
    pQ->rear->next=R;
    pQ->rear=R;
    return 0;
}

//代码3. ---------链队列的“出队列”操作---------//
//文件名：LinkQueue.c
//以指向LinkQueue结构体的一重指针pQ为参数，参数pe为地址传递形式
//将队头元素用指针e返回；若是唯一元素，需调整rear指针
//如果队列不存在或队列为空，返回-1; 反之，成功操作返回0  
int DeQueue(LinkQueue *pQ,QElemType *pe)
{
    QueuePtr R;
    if (pQ==NULL) return -1;            //队列不存在，返回-1
    if(pQ->front==pQ->rear) return -2;  //队列为空，返回-2
        
    R=pQ->front->next;			        //令R指向表头后的第一个结点
    *pe=R->data;
    pQ->front->next=R->next;
    if(pQ->rear==R)                     //如果第一个结点也是最后一个结点
        pQ->rear=pQ->front;
    free(R);
    return 0;
}

//代码3. ---------链队列的“求队列长度”操作---------//
//文件名：LinkQueue.c
//以指向LinkQueue结构体的一重指针pQ为参数
int GetQueueLength(LinkQueue *pQ)
{
    QueuePtr p;
    int count=0;
    p=pQ->front;
    while(p!=pQ->rear)
    {
        count++;
        p=p->next;
    }
    return count;
}

//代码3. ---------链队列的“清空队列”操作---------//
//文件名：LinkQueue.c
//以指向LinkQueue结构体的一重指针pQ为参数
//清空后，front和rear指针均指向表头结点
int ClearQueue(LinkQueue *pQ)
{ /* 将Q清为空队列 */
    QueuePtr p,q;
	if (pQ==NULL) return -1;
    pQ->rear=pQ->front;    //rear指针归位
    p=pQ->front->next;     //p指针指向表中第一个数据结点
    pQ->front->next=NULL;  //表头结点的next域归位
    while(p!=NULL)         //循环释放每个数据结点的空间
    {
        q=p;
        p=p->next;
        free(q);
    }
    return 0;
}


//代码3. ---------链队列的销毁操作---------//
//文件名：LinkQueue.c
//以指向LinkQueue结构体的二重指针ppQ为参数
//在函数内先清空队列数据，然后销毁空队列的B、C部分，并归位队列指针
int DestroyQueue(LinkQueue **ppQ)
{ 
    if (ClearQueue(*ppQ)==-1) return -1;
    free((*ppQ)->front);
    free(*ppQ);
    ppQ= NULL;
    return 0;
}


int main()
{
	LinkQueue *pQ= NULL;
	InitQueue(&pQ);
	return 0;
}



