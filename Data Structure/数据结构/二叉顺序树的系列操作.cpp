#include<stdio.h>
#include<stdlib.h>

//二叉排序树系列操作

//二叉排序树的结点类型定义
typedef int Datatype;
typedef struct node{
	struct node *LChild;
	Datatype data;
	struct node *RChild;
}BSTNode;

//二叉树的插入
BSTNode *insertBSTree(BSTNode *root, Datatype elem)
{
	BSTNode *t;
	if(root == NULL)
	{
		t = (BSTNode *)malloc(sizeof(BSTNode));
		t->data = elem;
		t->LChild = NULL;
		t->RChild = NULL;
	}
	else if(elem < root->data)
	{
		if(root->LChild == NULL)
		{
			t = (BSTNode *)malloc(sizeof(BSTNode));
			t->data = elem;
			t->LChild = NULL;
			t->RChild = NULL;
			root->LChild = t;
		}
		else
		{
			t = insertBSTree(root->LChild, elem);
		}
	}
	else if(elem > root->data)
	{
		if(root->RChild == NULL)
		{
			t = (BSTNode *)malloc(sizeof(BSTNode));
			t->data = elem;
			t->LChild = NULL;
			t->RChild = NULL;
			root->RChild = t;
		}
		else
		{
			t = insertBSTree(root->RChild, elem);
		}
	}
	
	return t;
}

//二叉排序树的建立
BSTNode *createBSTree()
{
	int elem;
	BSTNode *root = NULL;
	scanf("%d", &elem);
	
	while(elem != -1)
	{
		if(root == NULL)
		{
			root == insertBSTree(root, elem);
		}
		else
		{
			insertBSTree(root, elem);
		}
		scanf("%d", elem);
	}	
	
	return root;
} 

//二叉树的查找
BSTNode *searchBSTree(BSTNode *root, Datatype elem) 
{
	if(root == NULL)
	{
		return NULL;
	}
	else if(elem == root->data)
	{
		return root->data;
	}
	else if(elem < root->data)
	{
		return searchBSTree(root->LChild, elem);
	}
	else if(elem > root->data)
	{
		return searchBSTree(root->RChild, elem);
	}
}

//二叉树的删除 
BSTNode *delBSTree(BSTNode *root, Datatype elem) 
{
	BSTNode *f = NULL, *c = root, *fp, *p;
	while( c->data != elem )                        //查找待删除的结点c, f为其父结点
	{
		if( elem < c->data )
		{
			f = c;
			c = c->LChild; 
		}
		else
		{
			f = c;
			c = c->RChild;
		}
	}
	if( NULL == c->RChild )                        //结点c没有右孩子
	{
		if( NULL == f)                             //结点c是根结点	
		{
			c = c->LChild;
			free( root );
			return C;

		}	
		else                                      //结点c不是根结点
		{
			if( c->data < f->data )
				f->LchiId = c->LChild;
			else
				f->RChila = c->LChild;
			free( c );
		}
	}
	else if( NULL == c->LChild )                  //结点c没有左孩子
	{
		if( NULL = f)                            //结点c是根结点
		{
			c = c->RChild;
			free( root );
			return c;
		}
		else                                     //结点c不是根结点
		{
			if( c->data < f->data )
				f->LchiId = c->RChild;
			else
				f->RChila = c->RChild;
			free( c );
		}
	}
	else
	{
		fp = c;
		p = c->LChild;
		
		while(p->RChild != NULL)              //查找结点c的前驱p，fp是p的双亲结点 
		{
			fp = p;
			p = p->RChild; 
		}
		if(fp == c)                           //c的中序前驱是其左孩子 
		{
			fp->data = p->data;
			fp->LChild = p->LChild;
			free(p);
		}
		else                                  //c的中序前驱是其右孩子
		{
			c->data = p->data;
			fp->RChild = p->LChild;
			free(p);
		}
	}
	
	return root;
}
























 

