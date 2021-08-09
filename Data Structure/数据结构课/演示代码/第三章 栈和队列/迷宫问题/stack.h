#include "stdio.h"   //主要是为了能够使用printf和scanf
#include "malloc.h"  //为了能使用malloc函数

/*  栈的顺序存储表示 */
 #define STACK_INIT_SIZE 100 /* 存储空间初始分配量 */
 #define STACKINCREMENT 20 /* 存储空间分配增量 */
 typedef struct Node
 {
   int ii; 
   int jj; 
   int kk; 
 }Node; /*  */

 typedef struct SqStack
 {
   Node *base; /* 在栈构造之前和销毁之后，base的值为NULL */
   Node *top; /* 栈顶指针 */
   int stacksize; /* 当前已分配的存储空间，以元素为单位 */
 }SqStack; /* 顺序栈 */

 /* 顺序栈的基本操作（迷宫问题未使用的函数已注释掉） */
 int InitStack(SqStack *S)
 { /* 构造一个空栈S */
   (*S).base=(Node *)malloc(STACK_INIT_SIZE*sizeof(Node));
   if(!(*S).base)
     return -1; /* 存储分配失败 */
   (*S).top=(*S).base;
   (*S).stacksize=STACK_INIT_SIZE;
   return 0;
 }

 int DestroyStack(SqStack *S)
 { /* 销毁栈S，S不再存在 */
   free((*S).base);
   (*S).base=NULL;
   (*S).top=NULL;
   (*S).stacksize=0;
   return 0;
 }
/*
 int ClearStack(SqStack *S)
 { // 把S置为空栈 
   (*S).top=(*S).base;
   return 0;
 }
*/
 int StackIsEmpty(SqStack S)
 { /* 若栈S为空栈，则返回1，否则返回0 */
   if(S.top==S.base)
     return 1;
   else
     return 0;
 }
/*
 int StackLength(SqStack S)
 { // 返回S的元素个数，即栈的长度
   return S.top-S.base;
 }
*/

 int Push(SqStack *S,int i, int j, int k)
 { /* 插入元素e为新的栈顶元素 */
   if((*S).top-(*S).base>=(*S).stacksize) /* 栈满，追加存储空间 */
   {
     (*S).base=(Node *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(Node));
     if(!(*S).base)
       return -1; /* 存储分配失败 */
     (*S).top=(*S).base+(*S).stacksize;
     (*S).stacksize+=STACKINCREMENT;
   }
   (*S).top->ii=i;
   (*S).top->jj=j;
   (*S).top->kk=k;
	(*S).top++;
   return 0;
 }

 int Pop(SqStack *S, int *i, int *j, int *k)
 { /* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回0；否则返回-1 */
   if((*S).top==(*S).base)
     return -1;
   --(*S).top;
   *i=(*S).top->ii;
   *j=(*S).top->jj;
   *k=(*S).top->kk;
   return 0;
 }

