//代码7.2--------- 二叉排序树的二叉链表结点结构定义 ---------//
//文件名：BiOrderTree.c（第1部分，共7部分）
// 用typedef定义一个新的结构体类型（取名为BiTNode）和指向该结构体类型的指针的类型（取名BiTree）。
#include "stdio.h"
#include "malloc.h"
#define  ENDKey  -1         //创建二叉排序树的专用变量，输入-1表示输入结束

typedef struct  BSTNode
{
    int  Key ; 
    struct BSTNode  *Lch,*Rch;
}BSTNode, *BSTree;

//代码7.3--------- 递归的二叉排序树查找算法 ---------//
//文件名：BiOrderTree.c（第2部分，共7部分）
// 在bst指针所指向的二叉排序树中搜索值为Key的结点，如果查找成功，则函数返回该结点的地址；
// 如果查找失败，函数返回NULL，并且pre指针返回查找该元素时在二叉排序树中经历的最后一个结点。
BSTNode *SearchBST(BSTree bst, int Key, BSTNode **pre)
{
	if (!bst){
		return NULL;
	}
	else if (Key == bst->Key) 
			return bst;
	else if (Key <  bst->Key) {
			if (pre!= NULL)	*pre= bst;
			return SearchBST(bst->Lch, Key, pre);
			}
	else {	
			if (pre!= NULL)	*pre= bst;
	    	return SearchBST(bst->Rch, Key, pre);
	}
}

//代码7.4--------- 非递归的二叉排序树查找算法 ---------//
//文件名：BiOrderTree.c（第3部分，共7部分）
// 在bst指针所指向的二叉排序树中搜索值为Key的结点，如果查找成功，则函数返回该结点的地址；
// 如果查找失败，函数返回NULL，并且pre指针返回查找该元素时在二叉排序树中经历的最后一个结点。
BSTNode *N_SearchBST(BSTree bst, int K, BSTNode **pre)
{
	BSTree p;

	if (bst== NULL)
		return NULL;

	p=bst;
	while(p)
	{   
		if(K==p->Key)     //在树中找到值相同的元素
		{
			return p;
		}
        else 
			if(K<p->Key)
		{
			if (pre!=NULL) *pre=p;
			p=p->Lch;
		}
        else 
		{
			if (pre!=NULL) *pre=p;
			p=p->Rch;
		}
	}
	return NULL;
}

//代码7.5 --------- 二叉排序树的插入算法 --------- //
//文件名：BiOrderTree.c（第4部分，共7部分）
//bst为指向二叉排序树根结点的二重指针；k为要插入的结点的值
//插入成功，函数返回0,；插入失败，函数返回-1（当树中已存在结点k时会插入失败）
int InsertBST(BSTree *bst, int k)
{ 
	BSTree r,pre;	
	
	r=(BSTree)malloc(sizeof(BSTNode));
	r->Key=k;
	r->Lch=NULL; 
	r->Rch=NULL;
	if (*bst == NULL)
	{
		*bst=r;
		return 1;
	}
	pre= NULL;
    if (!SearchBST(*bst, k, &pre)){
		//没有找到值相同的元素，则根据找到的最后一个元素来做插入操作
		if(k<pre->Key)
			pre->Lch=r;
		else 
			pre->Rch=r;
		return 0;	
	}
	else
		return -1;
}

//代码7.6 --------- 二叉排序树的创建算法 --------- //
//文件名：BiOrderTree.c（第5部分，共7部分）
//bst为指向二叉排序树根结点的二重指针
void  CreateBST(BSTree  *bst)
{ 
	int Key;
	*bst=NULL;
	scanf("%d", &Key);
	while (Key!=ENDKey)   
	{
		InsertBST(bst, Key);
		scanf("%d", &Key);
	}
	getchar();
}

void  InOrder(BSTree root) 
{
	if (root!=NULL)
	{
		  
		InOrder(root->Lch);
		printf("%d ",root->Key);  
		InOrder(root->Rch);  
	}
}

//代码7.7 --------- 二叉排序树的删除单个结点算法 --------- //
//文件名：BiOrderTree.c（第6部分，共7部分）
//已知结点地址p，在二叉排序树中删除该结点
int DeleteByVexAddr(BSTNode **p)
{
	BSTNode *q, *s;
	if ((*p)->Rch==NULL){
		q= *p;
		*p= (*p)->Lch;
		free(q);
	}
	else if ((*p)->Lch==NULL){
		q= *p;
		*p= (*p)->Rch;
		free(q);
	}
	else{
		q=*p;
		s=(*p)->Lch;
		while(s->Rch){
			q=s; s=s->Rch;
		}
		(*p)->Key= s->Key;
		if (q!= *p)
			q->Rch= s->Lch;
		else
			q->Lch= s->Lch;
		free(s);
	}
	return 0;
}

//代码7.8---------递归实现的二叉排序树的删除操作函数---------//
//文件名：BiOrderTree.c（第7部分，共7部分）
//已知结点的值k，在二叉排序树中找到并删除该结点
int DeleteByVexValue(BSTree *bst, int k)
{
	if (!*bst)
		return -1;
	else{
		if (k==(*bst)->Key)
			return DeleteByVexAddr(bst);
		else if ( k < (*bst)->Key )
			return DeleteByVexValue(&(*bst)->Lch, k);
		else 
			return DeleteByVexValue(&(*bst)->Rch, k);
	}
}

int main()
{
	BSTree T, pAnswer;
	int K;
	printf("建立二叉排序树，请输入序列，以-1结束：\n");
    CreateBST(&T);
	printf("中序遍历二叉排序树,输出序列为:\n");
	InOrder(T);
    printf("\n");
	printf("请输入你要查找的元素:\n");
    scanf("%d",&K);
	pAnswer= SearchBST(T,K, NULL);
    if(pAnswer==NULL)
		printf("查找失败!#o#\n");
    else 
		printf("查找成功!由返回地址索引到%d\n",pAnswer->Key);
	printf("请输入你要删除的元素:\n");
    scanf("%d",&K);
	DeleteByVexValue(&T, K);
	printf("删除%d后二叉排序树的输出序列为:\n",K);
	InOrder(T);
	printf("\n请输入你要插入的元素:\n");
    scanf("%d",&K);
	if (InsertBST(&T, K)==0)
		printf("插入成功！\n");
	else
		printf("插入失败，二叉树中已存在该元素！\n");
	printf("插入%d后二叉排序树的输出序列为:\n",K);
	InOrder(T);
	return 0;
}

/*
输入的测试数据如下
50 40 60 70 30 20 90 84 65 32 37 98 57 -1
37
37
*/