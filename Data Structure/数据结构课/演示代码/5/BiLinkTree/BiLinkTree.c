//代码5.5---------二叉树的顺序存储表示结构定义---------//
//文件名：BiLinkTree.c（第1部分，共10部分）
#include  "stdio.h"      //scanf函数和printf函数需要用到该头文件
#include  "malloc.h"     //如果代码中需要用到malloc函数，则需要该头文件
#include  "string.h"     //memset和strcpy函数需要该头文件
#include  "BiTree.h"     //内含对TelmType、BitNode和BiTree这三个类型的定义
#include "LinkQueue.h"   //二叉链表的非递归创建函数需要用到链队列来辅助完成，故此处引入链队列
#include "LinkStack.h"   //二叉链表的非递归遍历函数需要用到链栈来辅助完成，故此处引入链栈

//代码5.6  ---------非递归的二叉链表创建和初始化操作--------- //
//文件名：BiLinkTree.c（第2部分，共10部分）
int ElemIsEmpty(TelemType e)
{
	if (strcmp(e.name, "空")==0 && e.number==0)
		return 1;
	else
		return 0;
}

// N_CreateBitree算法要求运行时以"双亲结点值,当前元素值,左右标记"的形式接受每个结点的信息
BiTree N_CreateBitree()
{
    LinkQueue Q;
    BiTNode *P= NULL, *R= NULL;
    BiTree  bt;
    TelemType par, data;
    char LR;
    InitQueue(&Q);
    bt=NULL;
    printf("请按顺序输入节点的双亲、节点及LR标记值：\n");
    scanf("%s%d", par.name,  &par.number);
    scanf("%s%d", data.name, &data.number);
    scanf("%c", &LR);
    while(LR !='L' && LR !='R') scanf("%c", &LR);

    while (! ElemIsEmpty(data))
    {
        P= (BiTNode*)malloc(sizeof(BiTNode));
        strcpy(P->data.name, data.name);
        P->data.number= data.number;
        P->Lch= NULL;
        P->Rch= NULL;

        if (ElemIsEmpty(par))
        {
            bt= P;
            EnQueue(&Q, P);
        }
        else
        {
            GetHead_Q(Q, &R);                       //访问队头元素，赋给R
            while(strcmp(R->data.name, par.name)!=0)
            {
                DeQueue(&Q, &R);
                GetHead_Q(Q, &R);
            }
            if (LR=='L')        //将新结点P挂接到二叉链表中
            {
                R->Lch= P;
            }
            else
            {
                R->Rch= P;
                DeQueue(&Q, &R);
            }
            EnQueue(&Q, P);
        }
        scanf("%s%d", par.name,  &par.number);
        scanf("%s%d", data.name, &data.number);
        scanf("%c", &LR);
        while(LR !='L' && LR !='R') scanf("%c", &LR); 
    }
    return bt;
}

//----------------------------------------------------------------------------------------//
//代码5.7---------二叉链表存储结构下的"判断树是否为空"操作---------//
//文件名：BiLinkTree.c（第3部分，共10部分）
int  TreeIsEmpty(BiTree  bt)
{
    // 参数有效性检验。如果bt指针无效，则视其表达的树为空树。
        if (bt == NULL) 
        return  1;
    // 若bt指针确实指向某个结点，但该结点内的值为空，则视该根结点为空，进而视该树/子树为空
    if (strcmp(bt->data.name, "空")==0 && bt->data.number==0)
        return 1;
    else
        return 0;  // 若上述判断条件均不满足，则视该树/子树存在
}
//---------------------------------------------------------------------------------------
//代码5.8--------二叉链表存储结构中的求左孩子地址操作---------//
//文件名：BiLinkTree.c（第4部分，共10部分）
BiTree  GetNodeLeftChild(BiTree  bt)
{
    if( bt == NULL)
       return  NULL;
    else
       return  bt->Lch;
}

//代码5.9---------递归实现的二叉链表先序遍历操作---------
//文件名：BiLinkTree.c（第5部分，共10部分）
int  PreOrderTravBiTree (BiTree  bt)   //注意函数头格式，与二叉链表下的有所不同
{
    if (TreeIsEmpty(bt))         // 递归函数首先应处理特殊情况，该情况下必定不需要再递归。
         return  1;
    else 
    {
         printf("%s  ",  bt->data.name);         //"访问"该树/子树的根节点
         printf("%d\n",  bt->data.number);
         PreOrderTravBiTree (bt->Lch);       //先序遍历该树/子树的左子树
         PreOrderTravBiTree (bt->Rch);      //先序遍历该树/子树的右子树
         return 1;
    }
}
//代码5.10-------非递归实现的二叉链表先序遍历操作------------------//
//文件名：BiLinkTree.c（第6部分，共10部分）
int N_PreOrderTravBiTree(BiTree bt)
{
   LinkStack S;
   BiTNode *p;

   InitStack(&S);
   ClearStack(&S);
   p=bt;
   while(1)
   {
	   if (p==NULL)
	   {

		   if (StackIsEmpty(&S))
		   {
			   return 0;
		   }
		   else
		   {
			   Pop(&S, &p);
			   p= p->Rch;
		   }
	   }
	   else
	   {
			printf("(%s,%d)\n", p->data.name, p->data.number);
			Push(&S, p);
			p= p->Lch;
	   }
   }
}
//代码5.11---------递归实现的二叉链表中序遍历操作---------//
//文件名：BiLinkTree.c（第7部分，共10部分）
int  InOrderTravBiTree( BiTree  bt)
{
    if (TreeIsEmpty( bt))        // 递归函数首先应处理特殊情况，该情况下必定不需要再递归。
         return  0;
    else 
    {
         InOrderTravBiTree(bt->Lch);               //中序遍历左子树
         printf("%s  ",  bt->data.name);         //"访问"根节点
         printf("%d\n",  bt->data.number);
         InOrderTravBiTree(bt->Rch);               //中序遍历右子树
         return 0;
}
}


//代码5.12-------非递归的二叉链表中序遍历操作------------------//
//文件名：BiLinkTree.c（第8部分，共10部分）
int N_InOrderTravBiTree(BiTree bt)
{
    LinkStack S;
    BiTNode *p;

    printf("该二叉树的中序遍历结果为：\n");
    InitStack(&S);
    ClearStack(&S);
    p=bt;
    while(1)
    {
        if (p==NULL) {
            if (StackIsEmpty(&S)) {
                return 0;	
            }
            else {
                Pop(&S, &p);
                printf("(%s,%d)\n", p->data.name, p->data.number);
                p= p->Rch;
            }
        }
        else {
            Push(&S, p);
            p= p->Lch;
        }
    }
}
//代码5.13-------非递归的二叉链表后序遍历算法代码------------//
//文件名：BiLinkTree.c（第9部分，共10部分）
//正常遍历结束返回0， 非正常遍历结束返回-1
int  N_PostOrderTravBiTree(BiTree  bt)
{
    LinkStack S;    
    BiTNode *p, *Pr;

    if (bt == NULL) return -1;

    InitStack(&S);
    p= bt;
	Pr=NULL;

    while(1)
    {
        if (p!=NULL)
        {
            Push(&S, p);
            p= p->Lch;
        }
        else
        {
			if (StackIsEmpty(&S)) return 0; 
            GetTop(&S, &p);

            while(p->Rch==NULL || p->Rch==Pr)
            {
                Pop(&S, &p);
                printf("%s  ",  p->data.name);
                printf("%d\n",  p->data.number);
				Pr= p;

				if (StackIsEmpty(&S)) return 0; 
		        GetTop(&S, &p);
            }
			p= p->Rch;
        }
    }
}

//代码5.14---------递归的二叉链表结构下的创建操作算法代码---------//
//文件名：BiLinkTree.c（第10部分，共10部分）
// 注意递归函数的参数类型为二级指针，函数中对应的指针写法也相应有所变化
int CreateBitree(BiTNode  **bt)
{
    TelemType data;
    scanf("%s", data.name);
    scanf("%d", &data.number);
    if (ElemIsEmpty(data))
        *bt=NULL;
    else{
        *bt=(BiTNode  *)malloc(sizeof(BiTNode));
        if (*bt==NULL)
            return 0;
        strcpy((*bt)->data.name,  data.name);
        (*bt)->data.number=  data.number;
        CreateBitree(&((*bt)->Lch));     //(*bt)->Lch为BiTNode *变量，而参数则是Node **变量，
        CreateBitree(&((*bt)->Rch));     //所以需要&取址，否则形参无法保留*Lch值
    }
	return 1;
}


/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	BiTree bt;
    bt= N_CreateBitree();
/*    printf("递归的中序遍历的结果序列为：\n");
    InOrderTravBiTree (bt);
    printf("非递归的中序遍历的结果序列为：\n");
    N_InOrderTravBiTree (bt);
*/	return 0;
}
/*
N_CreateBitree()测试输入数据：
空 0 点1 10 L
点1 10 点2 20 L
点1 10 点3 30 R
点3 30 点4 40 L
点3 30 点5 50 R
点4 40 点6 60 R
点5 50 点7 70 L
空 0 空 0 L

PreOrderTravBiTree()测试输入数据
空 0 点1 10 L
点1 10 点3 30 R
点3 30 点6 60 L
点3 30 点7 70 R
空 0 空 0 L


N_PreOrderTravBiTree()测试输入数据
空 0 A 100 L
A 100 B 100 L
A 100 C 100 R
B 100 D 100 L
B 100 E 100 R
C 100 F 100 L
C 100 G 100 R
D 100 H 100 L
F 100 I 100 L
G 100 J 100 R
H 100 K 100 R
空 0 空 0 L

CreateBitree()测试输入数据：
点1 10
点2 20
空 0
空 0
点3 30
点4 40
空 0
点6 60
空 0
空 0
点5 50
点7 70
空 0
空 0
空 0

中序遍历的测试数据
空 0 A 100 L
A 100 B 100 L
A 100 C 100 R
B 100 D 100 L
B 100 E 100 R
C 100 F 100 L
C 100 G 100 R
D 100 H 100 L
F 100 I 100 L
G 100 J 100 R
H 100 K 100 R
空 0 空 0 L


*/
