#include<stdio.h>
#include<stdlib.h>

//堆的系列操作
//以小根堆为例 

//堆的顺序储存类型 
#define MaxSize 200
typedef int Datatype;
typedef struct{
	Datatype v[MaxSize];
	int len;
}Heap;

//初始化堆
void initHeap(Heap *h)
{
	h->len = 0;
}

//建立堆
//这里取第一个元素为0 
void createHeap(Heap *h)
{
	int i;
	Datatype elem;
	scanf("%d",&elem);
	
	while(elem != -1)
	{
		h->v[h->len] = elem;
		h->len++;
		scanf("%d",&elem);
	}
	
	for(i = h->len-1; i >= 0; i--)                    //从最后一个分支到根节点开始调整 
	{
		adjustHeap(h, i);
	}
} 

//插入堆
void insertHeap(Heap *h, Datatype elem)
{
	int i,j;
	if(h->len >= MaxSize)
	{
		printf("堆满!\n");
	}
	h->v[h->len] = elem;
	h->len++;
	i = h->len - 1;
	
	while(i != 0)
	{
		j = (i-1)/2;                          //双亲结点位置 
		if(elem >= h->v[j])
		{
			break;
		}
		else
		{
			h->v[i] = h->v[j];               //将双亲结点值下移 
			i = j;
		}
	} 
	h->v[i] = elem;
}

//堆的调整
//将堆中以第k个元素为根的子树调整为小根堆 
void adjustHeap(Heap *h, int k)
{
	int i = k;
	int j = 2*i + 1;           //该结点的左子结点 
	Datatype t = h->v[k];      //该结点 
	
	while(j < h->len)
	{
		if(j < h->len - 1 && h->v[j] > h->v[j+1])             //先比左右子结点大小 
		{
			j++;
		}
		if(t <= h->v[j])
		{
			break;
		}
		h->v[i] = h->v[j];
		i = j;
		j = 2*i + 1;
	}	
	h->v[i] = t;
} 

//删除堆顶元素,并将最后一个元素移到堆顶 
Datatype removeHeapTop(Heap *h)
{
	int i,j;
	Datatype top, t;
	
	if(h->len == 0)
	{
		printf("堆空!\n");
		exit(1);
	}
	
	top = h->v[0];
	h->len--;
	
	if(h->len == 0)           //如果删除后堆为空 
		return top;
	else
	{
		h->v[0] = h->v[h->len];
		adjustHeap( h, 0);
		
		return top;
	}
} 



















 

 
 
