/*
 *  文件名：SeqQueue.c
 *	循环队列的实现
 *	版本：1.0
 *	时间：2016.06.26
 *	作者：wangx
 *	假定条件： 假设元素的基本类型为整数int
 *			
*/
//代码3. ---------顺序结构下的循环队列基本结构定义代码---------//
//文件名：SeqQueue.c
#include "stdio.h"
#include "malloc.h"

#define MAXQSIZE 10        //假定数组长度为10
typedef int QElemType;     //假定队列元素为比较简单的int型
typedef struct
{
    QElemType *base; //注意，连续存储空间需要在函数中动态申请，此处只是定义了指向该空间的指针
    int front; //队头指针,若队列不空,指向队列头元素的下标
    int rear;  //队尾指针,若队列不空,指向队列尾元素的下一个空位下标
}SeqQueue;

//代码3. ---------顺序结构下的“创建并初始化一个队列”操作算法代码---------//
//文件名：SeqQueue.c
//因为涉及到可能更改指向队列的指针值，所以采用二重指针ppQ为参数，以便返回
int InitQueue(SeqQueue **ppQ)
{ 
    //创建循环队列的基本结构，诞生base、front和rear
    *ppQ= (SeqQueue *)malloc(sizeof(SeqQueue));
    if (!*ppQ) return -1;
    //创建循环队列的数组载体结构，诞生base指向的数组空间
    (*ppQ)->base=(QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
    if(!(*ppQ)->base)
    {
        free(*ppQ);
        return -1;
    }
    //front和rear相等，初始化设其都为0（也可以不从0开始）
    (*ppQ)->front=(*ppQ)->rear=0;
    return 0;
}

//代码3. ---------顺序结构下的“队列销毁”操作算法代码---------//
//文件名：SeqQueue.c
//因为涉及到可能更改指向队列的指针值，所以采用二重指针ppQ为参数，以便返回
int DestroyQueue(SeqQueue **ppQ)
{ /* 销毁队列Q,Q不再存在 */
   if((*ppQ)->base)
     free((*ppQ)->base);
   if(*ppQ)
     free(*ppQ);
   *ppQ= NULL;
   return 0;
}

//代码3. ---------顺序结构下的“清空队列”操作算法代码---------//
//文件名：SeqQueue.c
//函数要求队列本身是已存在的
int ClearQueue(SeqQueue *pQ)
{
    if (pQ==NULL) return -1;
    pQ->front=pQ->rear=0;    //注意，并不需要对数组中已存在的元素置为0或空
    return 0;
}

//代码3. ---------顺序结构下的“判断队列是否为空”操作算法代码---------//
//文件名：SeqQueue.c
//函数要求队列本身是已存在的，否则返回-1
//若队列pQ为空队列,则返回1,否则返回0
int QueueIsEmpty(SeqQueue *pQ)
{
    if (pQ== NULL) return -1;
    if(pQ->front==pQ->rear) /* 队列空的标志 */
        return 1;
    else
        return 0;
}

//代码3. ---------顺序结构下的"获取队列元素个数"操作算法代码---------//
//文件名：SeqQueue.c
//函数要求队列本身是已存在的，否则返回-1
int GetQueueLength(SeqQueue *pQ)
{
    int length;
    if (pQ== NULL) return -1;
    //循环队列中，rear的值有可能会小于front，故要加个MAXQSIZE再来取余
    length= (pQ->rear-pQ->front+MAXQSIZE)%MAXQSIZE;
    return length;
}

//代码3. ---------顺序结构下的"获取队头元素的值"操作算法代码---------//
//文件名：SeqQueue.c
//队列为空或者队列不存在，均返回-1，否则将队头元素的值存储到地址为pe的空间中，并返回0
int GetHead(SeqQueue *pQ,QElemType *pe)
{
    if (pQ== NULL) return -1;
    /* 若队列不空,则用e返回Q的队头元素,并返回0,否则返回-1 */
    if(pQ->front==pQ->rear) /* 队列空 */
        return -1;
    *pe=pQ->base[pQ->front];
    return 0;
}

//代码3. ---------顺序结构下的"进队列"操作算法代码---------//
//文件名：SeqQueue.c
//队列不存在，返回-1；队列满，返回-2；正常进队返回0
//注意此时进队元素是普通的值传递方式	
int EnQueue(SeqQueue *pQ, QElemType e)
{
    if (pQ== NULL) return -1;
    if((pQ->rear+1)%MAXQSIZE==pQ->front) //如果队列满，产生真上溢，放弃操作
        return -2;
    pQ->base[pQ->rear]=e;                //先填值，注意，入队列和front无关
    pQ->rear=(pQ->rear+1)%MAXQSIZE;      //再循环加1
    return 0;
}

//代码3. ---------顺序结构下的"出队列"操作算法代码---------//
//文件名：SeqQueue.c
//队列不存在，返回-1；队列空，返回-2；正常出队返回0
//注意此时出队元素pe采用的是参数的地址传递方式	
int DeQueue(SeqQueue *pQ,QElemType *pe)
{
    if (pQ== NULL) return -1;
    if(pQ->front==pQ->rear)              //如果队列为空，直接放弃操作
        return -2;
    *pe=pQ->base[pQ->front];             //先读值，出队列操作与rear无关
    pQ->front=(pQ->front+1)%MAXQSIZE;    //再循环加1
    return 0;
}

int main()
{
    SeqQueue *pQ;
    InitQueue(&pQ);
	DestroyQueue(&pQ);
	return 0;
}