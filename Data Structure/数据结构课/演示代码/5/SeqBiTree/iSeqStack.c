 /*  栈的顺序存储表示 */
#include "stdio.h"

 #define STACK_INIT_SIZE 100 /* 存储空间初始分配量 */
 #define STACKINCREMENT 20 /* 存储空间分配增量 */
 typedef struct SqStack
 {
   int *base; /* 在栈构造之前和销毁之后，base的值为NULL */
   int *top; /* 栈顶指针 */
   int stacksize; /* 当前已分配的存储空间，以元素为单位 */
 }SqStack; /* 顺序栈 */
 
/*  顺序栈的基本操作（8个） */
 int InitStack(SqStack *S)
 { /* 构造一个空栈S */
   (*S).base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
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

 int ClearStack(SqStack *S)
 { /* 把S置为空栈 */
   (*S).top=(*S).base;
   return 0;
 }

 int StackIsEmpty(SqStack *S)
 { /* 若栈S为空栈，则返回1，否则返回0 */
   if(S->top==S->base)
     return 1;
   else
     return 0;
 }

 int StackLength(SqStack S)
 { /* 返回S的元素个数，即栈的长度 */
   return S.top-S.base;
 }

 int GetTop(SqStack S,int *e)
 { /* 若栈不空，则用e返回S的栈顶元素，并返回0；否则返回-1 */
   if(S.top>S.base)
   {
     *e=*(S.top-1);
     return 0;
   }
   else
     return -1;
 }

 int Push(SqStack *S,int e)
 { /* 插入元素e为新的栈顶元素 */
   if((*S).top-(*S).base>=(*S).stacksize) /* 栈满，追加存储空间 */
   {
     (*S).base=(int *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(int));
     if(!(*S).base)
       return -1; /* 存储分配失败 */
     (*S).top=(*S).base+(*S).stacksize;
     (*S).stacksize+=STACKINCREMENT;
   }
   *((*S).top)++=e;
   return 0;
 }

 int Pop(SqStack *S,int *e)
 { /* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回0；否则返回-1 */
   if((*S).top==(*S).base)
     return -1;
   *e=*--(*S).top;
   return 0;
 }

