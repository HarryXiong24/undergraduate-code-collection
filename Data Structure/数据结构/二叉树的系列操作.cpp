#include<stdio.h>
#include<stdlib.h>

//二叉树的系列操作

//二叉树的储存结构
typedef int Datatype;
typedef struct node{
	struct node *LChild;                               //左指针域
	Datatype data;
	struct node *RChile;                               //右指针域 
}BTNode;

//建立二叉树
BTNode *createBTree()
{
	BTNode *bt = NULL;
	int elem;
	scanf("%d",&elem);
	if(elem != -1)                      //若不为空，则建立一个新起点 
	{
		bt = (BTNode *)malloc(sizeof(BTNode));
		if(bt == NULL)
		{
			printf("内存分配失败!\n");
			exit(1);
		}
		bt->data = elem;
		bt->LChild = createBTree()      //建立左子树
		bt->RChile = createBTree()      //建立右子树 
	}
	
	return bt; 
}

//先序遍历
void preOrder(BTNode *root)
{
	if(root != BULL)
	{
		printf("%d",root->data);
		preOrder(root->LChild);
		preOreder(root->RChile);	
	}	
} 

//中序遍历
void midOrder(BTNode *root)
{
	if(root != BULL)
	{
		midOrder(root->LChild);
		printf("%d",root->data);
		midOreder(root->RChile);	
	}	
} 

//后序遍历
void postOrder(BTNode *root)
{
	if(root != BULL)
	{
		postOrder(root->LChild);
		postOreder(root->RChile);	
		printf("%d",root->data);
	}	
} 

//层次遍历
void layerOrder(BTNode *root) 
{
	BTNode *t;
	SeqOueue btQueue;              //建立顺序队列
	initQueue(&btQueue);           //初始化
	if(root != NULL)
	{
		InsQueue(&btQueue, *root);        //若而二叉树根节点不空，则将其入队 
		while( !isEmpty(btQueue) )
		{
			t = outQueue(&btQueue);    //取队头元素
			printf("%d",t->data);
			if(t->LChild != NULL)
			{
				InsQueue(&btQueue, t->LChild);           //如果当前节点有左子树，则将其入队 
			}	
			if(t->RChild != NULL)
			{
				InsQueue(&btQueue, t->RChild);           //如果当前节点有右子树，则将其入队 
			}	
		} 
	} 
}

//查找节点
BTNode *searchBTree(BTNode *root, Datatype elem)
{
	BTNode *t;
	if(root == NULL)                                  //想查找根节点 
	{
		return NULL;
	}
	if(root->data == elem)
	{
		return root;
	}
	else
	{
		t = searchBTree(root->LChild, elem);         //查找左树 
		if(t != NULL)
		{
			return t;
		}
		else
		{
			return searchBTree(root->RChile, elem); //查找右树 
		}
	}
}

//求二叉树的深度
//二叉树深度等于左子树和与右子树深度的最大值加1 
int getDepth(BTNode *root)
{
	int LDep,RDep;
	if(root == NULL)
	{
		return 0;
	}
	else
	{
		LDep = getDepth(root->LChild);
		RDep = getDepth(root->RChile); 
	}
}


 




















