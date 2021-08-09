//代码7.9  ---------平衡二叉树的二叉链表结点结构定义---------//
//文件名：BalanceTree.c（第1部分，共10部分）
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>    
#include <math.h>

typedef struct BSTNode
{
    int data;
    int Height;                    //以本结点为根结点的子树的高度
    struct BSTNode *lchild,*rchild;//左、右孩子指针
}BSTNode, *BSTree;

//代码7.10----------平衡二叉树中计算某结点为根的子树高度的操作--------- //
//文件名：BalanceTree.c（第2部分，共10部分）
static int Height(BSTree P)
{
	if (P==NULL)
		return 0;
	else
		return P->Height;
}



//代码7.11----------对以*p为根的平衡二叉树作单次顺旋处理，从左往右旋，左上，根下----------//
//文件名：BalanceTree.c（第3部分，共10部分）
//处理之后*p指向新的树根结点，即旋转处理之前的左子树的根结点。
void  RotateFromLtoR1(BSTree  *P) 
{
    BSTree lc;             
    lc = (*P)->lchild;         //lc指向的*P左子树根结点
    (*P)->lchild = lc->rchild; //rc的右子树挂接为*P的左子树
    lc->rchild = (*P); 
	(*P)->Height= max( Height((*P)->lchild), Height((*P)->rchild)) + 1;
	lc->Height=  max(Height(lc->lchild), Height(*P)) + 1;
	(*P) = lc; //p指向新的结点

}

//代码7.12----------对以*p为根的平衡二叉树作单次逆旋处理,从右往左旋，右上，根下----------//
//文件名：BalanceTree.c（第4部分，共10部分）
//处理之后*p指向新的树根结点，即旋转处理之前的右子树的根结点。
void RotateFromRtoL1(BSTree *P) 
{
    BSTree rc;             
    rc = (*P)->rchild;         //rc指向的*p右子树根结点
    (*P)->rchild = rc->lchild; //rc的左子树挂接为*p的右子树
    rc->lchild = (*P); 
	(*P)->Height= max(Height((*P)->lchild), Height((*P)->rchild)) + 1;
	rc->Height=  max(Height(rc->rchild), Height(*P)) + 1;

	(*P) = rc; //p指向新的结点
}

//代码7.13---------对以指针*P所指结点为根的二叉树做双顺旋处理，先逆旋，再顺旋---------//
//文件名：BalanceTree.c（第5部分，共10部分）
// 本算法结束后，指针*P指向新树的根结点
void RotateFromLtoR2(BSTree *P) 
{
	RotateFromRtoL1(&(*P)->lchild); //对*P的左子树作逆旋平衡处理
	RotateFromLtoR1(P);				//对*P作顺旋平衡处理
}

//代码7.14---------对以指针P所指结点为根的二叉树作双逆旋处理，先顺旋，再逆旋---------//
//文件名：BalanceTree.c（第6部分，共10部分）
// 本算法结束后，指针*P指向新树的根结点
void RotateFromRtoL2(BSTree *P)
{
    RotateFromLtoR1(&(*P)->rchild);	//对*P的右子树作顺旋处理
    RotateFromRtoL1(P);				//对*P作逆旋平衡处理
}


//代码7.15 ---------平衡二叉树的结点插入操作---------//
//文件名：BalanceTree.c（第7部分，共10部分）
//插入整型元素结点e，若T中不存在值相同的结点，则执行插入操作，并返回0，否则返回-1
int InsertAVL(BSTree *T, int e)
{
    if(!(*T))//插入新结点，树“长高”，置taller为1
    {
        *T = (BSTree)malloc(sizeof(BSTNode)); 
		if (*T==NULL)
		{
			printf("结点空间申请失败！");
			return -1;
		}
        (*T)->data = e;
		(*T)->Height = 1;
        (*T)->lchild = (*T)->rchild =NULL;
		return 0;
        
    }
    else
    if( e < (*T)->data)                 //应继续在*T的左子树中进行搜索
    {
        if(InsertAVL(&(*T)->lchild,e)== -1) 
			return -1;//未插入
		if (Height((*T)->lchild) - Height((*T)->rchild) == 2)
			if (e < (*T)->lchild->data)
				RotateFromLtoR1(T);     //插入的位置在左左，采用单次顺旋
			else
				RotateFromLtoR2(T);     //插入的位置在左右，采用双顺旋
	}
	else
    if( e > (*T)->data)                 //应继续在*T的左子树中进行搜索
    {
        if(InsertAVL(&(*T)->rchild,e)== -1) 
			return -1;//未插入
		if (Height((*T)->lchild) - Height((*T)->rchild) == -2)
			if (e > (*T)->rchild->data)  
				RotateFromRtoL1(T);     //插入的位置在右右，采用单次逆旋
			else
				RotateFromRtoL2(T);     //插入的位置在右左，采用双逆旋
	}
	//else 如果二者相等，说明树中已存在和有相同关键字的结点,则什么都不需要做

	//递归矫正从插入位置到根结点之间路径上所有结点的高度值
	(*T)->Height= max(Height((*T)->lchild), Height((*T)->rchild)) + 1;
    return 0;
}//InsertAVL



//代码7.16 --------- 平衡二叉树的创建操作代码---------//
//文件名：BalanceTree.c（第8部分，共10部分）
//T为指向平衡二叉树根结点的二重指针，数据录入以输入-1为结束标记
void CreatBST(BSTree *T)
{
    int e, taller=0;
    *T = NULL;
    printf("请输入关键字(以-1结束建立平衡二叉树):\n");
    scanf("%d",&e);getchar();
    while(e != -1)
    {
        InsertAVL(T,e);
        scanf("%d",&e);getchar();taller=0;
    }
}

//代码7.17 --------- 平衡二叉树的打印（方便调试和演示） ---------//
//文件名：BalanceTree.c（第9部分，共10部分）
//按树状"横向"打印输出二叉树的元素，m表示结点所在层次，初次调用时m=0
void PrintBST(BSTree T,int m)
{
    int i;
    if(T->rchild) PrintBST(T->rchild,m+1);
    for(i = 1; i<=m; i++)  
        printf("     ");//打印 i 个空格以表示出层次
    printf("%d\n",T->data);//打印 T 元素,换行 
    if(T->lchild) 
        PrintBST(T->lchild,m+1);
   
}

//代码7.18--------- 递归的平衡二叉树查找操作代码 ---------//
//文件名：BalanceTree.c（第10部分，共10部分）
//在T指针所指向的二叉排序树中搜索值为key的结点
//如果查找成功，则函数返回该结点的地址；如果查找失败，函数返回NULL
BSTree SearchBST(BSTree T,int key)
{
    if(!T) return NULL;
    else if(key==T->data) return T;
    else if(key<T->data) return SearchBST(T->lchild,key);
    else return SearchBST(T->rchild,key);
}


/*  
 * 查找最小结点：返回T为根结点的AVL树的最小结点。 
  
BSTree MinNodeInTree(BSTree T)  
{  
	BSTree p;
    if (T == NULL)
        return NULL;  
  
    p=T;
	while(p->lchild != NULL)  
        p = p->lchild;  
    return p;  
}  
   
 查找最大结点：返回tree为根结点的AVL树的最大结点。 
BSTree MaxNodeInTree(BSTree T)  
{  
	BSTree p;
    if (T == NULL)
        return NULL;  
  
    p=T;
	while(p->rchild != NULL)  
        p = p->rchild;  
    return p;  
}  

int DeleteNode(BSTree *T, BSTNode * pE)
{
	BSTree tmp, pMax, pMin;
    // 根为空 或者 没有要删除的节点，直接返回0。
    if (*T==NULL || pE==NULL)
        return 0;

    if (pE->data < (*T)->data)        // 待删除的节点在*T的左子树中
    {
        if (DeleteNode(&(*T)->lchild, pE)== -1)  //如果删除
			return -1;
        // 删除节点后，若AVL树失去平衡，则进行相应的调节。
        if (Height((*T)->rchild) - Height((*T)->lchild) == 2)
        {
            tmp =  (*T)->rchild;
            if (Height(tmp->lchild) > Height(tmp->rchild))
                RotateFromRtoL2(T);
            else
                RotateFromRtoL1(T);
        }
    }
    else if (pE->data > (*T)->data)// 待删除的节点在*T的右子树中
    {
        if (DeleteNode(&(*T)->rchild, pE)== -1)  //如果删除
			return -1;
        // 删除节点后，若AVL树失去平衡，则进行相应的调节。
        if (Height((*T)->lchild) - Height((*T)->rchild) == 2)
        {
            tmp =  (*T)->lchild;
            if (Height(tmp->rchild) > Height(tmp->lchild))
                RotateFromLtoR2(T);
            else
                RotateFromLtoR1(T);
        }
    }
    else    // (*T)是对应要删除的节点。
    {
        // (*T)的左右孩子都非空
        if (((*T)->lchild) && ((*T)->rchild))
        {
            if (Height((*T)->lchild) > Height((*T)->rchild))
            {
                // 如果(*T)的左子树比右子树高；
                // 则(1)找出(*T)的左子树中的最大节点
                //   (2)将该最大节点的值赋值给(*T)。
                //   (3)删除该最大节点。
                // 这类似于用"(*T)的左子树中最大节点"做"(*T)"的替身；
                // 采用这种方式的好处是：删除"(*T)的左子树中最大节点"之后，AVL树仍然是平衡的。
                pMax = MaxNodeInTree((*T)->lchild);
                (*T)->data = pMax->data;
                DeleteNode(&(*T)->lchild, pMax);
            }
            else
            {
                // 如果(*T)的左子树不比右子树高(即它们相等，或右子树比左子树高1)
                // 则(1)找出(*T)的右子树中的最小节点
                //   (2)将该最小节点的值赋值给(*T)。
                //   (3)删除该最小节点。
                // 这类似于用"(*T)的右子树中最小节点"做"(*T)"的替身；
                // 采用这种方式的好处是：删除"(*T)的右子树中最小节点"之后，AVL树仍然是平衡的。
                pMin = MaxNodeInTree((*T)->rchild);
                (*T)->data = pMin->data;
                DeleteNode(&(*T)->rchild, pMin);
            }
        }
        else
        {
            tmp = (*T);
			if ((*T)->lchild== NULL)
				(*T)= (*T)->rchild;
			else
				(*T)= (*T)->lchild;
            free(tmp);
        }
    }

    return 0;
}

int DeleteNodeByValue(BSTree *T, int e)
{
	BSTNode *pE;
	pE = SearchBST(*T, e);
	if (pE== NULL)  
		return -1;
	else
        return DeleteNode(T, pE);  
}
*/

int main(int argc,char* argv[])
{ 
    int input,K;
    BSTree T;
    T=(BSTree)malloc(sizeof(BSTNode));
    T=NULL;
	while(1)
	{   // system("cls"); 
        printf("*****************************************\n");
        printf("*1.创建     2.查找     3.插入     4.退出*\n");
        printf("*****************************************\n");
        printf("请输入您所需的操作功能:\t");
        scanf("%d",&input);
		getchar();   
		switch(input)
		{
		   case 1:
			   CreatBST(&T);
			   printf("生成的平衡二叉树如下所示：\n");
               PrintBST(T,0);
			   break;
		   case 2:
			   printf("请输入你要查找的关键字：");
               scanf("%d",&K); getchar();
               if(SearchBST(T,K)!=NULL) printf("该二叉树中存在关键字%d，查找成功!\n",K);
               else printf("查找失败!\n");
               break;
		   case 3:
               printf("请输入你要插入的关键字：");
               scanf("%d",&K); getchar();
               InsertAVL(&T,K);
			   PrintBST(T,0); break;
		   case 4:
               return 0;
		   default:
			   printf("输入错误，请重新选择。");break;
		}
		printf("\t\t按回车键继续..."); getchar();
	}
}

/*
10 20 30 50 60 32 60 24 54 80 28 39 93 -1

*/