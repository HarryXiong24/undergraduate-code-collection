#include <stdio.h>
#include <stdlib.h>

//遍历统计叶子节点的数目 
void leaf(BiTree *T)
{
	int count = 0;
	
    if(T)
	{
    	if(T->lchild==NULL&&T->rchild==NULL) 
		 	count++;
     	leaf(T->lchild);
     	leaf(T->rchild); 
	}
	else
		return count;
}

//二叉链表存储的二叉树的深度(高度)
struct BTreeNode
{ 
	elemtype data; 
	struct BTreeNode *lchild; 
	struct BTreeNode *rchild;
};

int hight(BTreeNode *T)
{ 
	int h1 = 0, h2 = 0, h = 0;
	if (T==null) 
		return(0); 
	else
	{ 
		h1=hight(T->lchild); 
		h2=hight(T->rchild); 
		if(h1>=h2) 
			h=h1+1;
		else 
			h=h2+1;
			 
		return h;
	}
}

// 二叉树的前序遍历 
void visit(char c)
{
	printf("%c",c);
}
 
void PreOrderTraverse(BiTree *T)
{
	if(T)
	{
		visit(T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

// 二叉树的中序遍历 
void InOrderTraverse(BiTree *T)
{
	if(T)
	{
		InOrderTraverse(T->lchild);
		visit(T->data);
		InOrderTraverse(T->rchild); 	
	}
}

// 二叉树的后序遍历 
void PostOrderTraverse(BiTree *T)
{
	if(T)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		visit(T->data);
	}
}

//求一棵二叉树中结点总数的算法。
int count(btNode *T)
{
	int num = 0;
	int m = 0, n = 0;
	if(T)
	{
		m=count(T->lchild);
		n=count(T->rchild);
		num=m+n+1;
	}
	    
	return num;
}


