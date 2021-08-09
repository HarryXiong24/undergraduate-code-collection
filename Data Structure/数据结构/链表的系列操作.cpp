#include<stdio.h>
#include<stdlib.h>

//链表的系列操作

//链表的结构
typedef int Datatype;                    //数据类型的定义
typedef struct node{
	Datatype data;                       //数据域
	struct node *next;                   //指针域 
}LNode; 

//链表的初始化(头指针的建立)
LNode *initList(LNode *h)
{
	h = (LNode *)malloc(sizeof(LNode));
	h->next = NULL;
	
	return h;
} 

//建立链表(元素的输入)
void createList(LNode *h) 
{
	LNode *tmp;
	int len,i;
	int elem;
	
	printf("请输入链表的长度:");
	scanf("%d",&len);
	
	for(i = 0; i < len; i++)
	{
		tmp = (LNode *)malloc(sizeof(LNode));
		printf("请输入第%d个元素:",i+1);
		scanf("%d",&elem);
		tmp->data = elem;
		tmp->next = NULL;
		
		h->next = tmp;                          //因为头指针作为链表唯一的连接信息，需要不断的向前移动 
		h = h->next;
	}
	
}

//清空链表
void clearList(LNode *h) 
{
	LNode *tmp;
	
	while(h->next != NULL)
	{
		tmp = h->next;                       //h->next才有值 
		h->next = tmp->next;                 //也可以写成 h->next = h->next->next 
		free(tmp);
	}
	
	printf("清空成功!\n"); 

}

//输出链表中所有元素
void outputList(LNode *h) 
{
	LNode *tmp;
	int i=0;
	tmp = h->next;
	
	while( tmp != NULL)
	{
		printf("第%d个元素为:",i+1);
		i++;
		printf("%d\n",tmp->data);
		tmp = tmp->next;
	}

}

//求链表的长度
void getLength(LNode *h) 
{
	LNode *tmp;
	int len = 0;
	tmp = h->next;
	
	while( tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	
	printf("链表长度为:%d\n",len);
}

//判断链表是否为空
void isEmpty(LNode *h) 
{
	if(h->next == NULL)
	{
		printf("链表为空!\n");
	}
	else
	{
		printf("链表不为空!\n");
	}
}

//替换链表的p节点的数
void changElem(LNode *h,int in, Datatype elem)
{
	LNode *p;
	int count = 1;                                      //遍历次数 
	
	p = (LNode *)malloc(sizeof(LNode)); 
	
	p = h->next;
	while( count != in )
	{
		p = p->next;
		count++;
	}
	
	p->data = elem;
	
}

//在链表的p节点后插入一个数
void insertElem(LNode *h,int in, Datatype elem)
{
	LNode *p;
	LNode *pnew;
	int count = 1;                                      //遍历次数 
	
	pnew = (LNode *)malloc(sizeof(LNode)); 
	pnew->data = elem;
	
	if(in == 0 && h != NULL)
	{
		pnew->next = h->next;
		h->next = pnew;
	}
	else
	{
		p = h->next;
		
		while( count != in )
		{
			p = p->next;
			if(p->next == NULL)
			{
				printf("溢出!\n");
				exit(1);
			}
			count++;
		}
		
		pnew->next = p->next;
		p->next = pnew;
	}
}

//在链表的p节点前插入一个数
void Eleminsert(LNode *h,int in, Datatype elem)
{
	LNode *p;
	LNode *pnew;
	int count = 1;                                      //遍历次数 
	
	pnew = (LNode *)malloc(sizeof(LNode)); 
	pnew->data = elem;
	
	if(in == 1 && h != NULL)
	{
		pnew->next = h->next;
		h->next = pnew;
	}
	else
	{
		p = h->next;
		
		while( count != in-1 )
		{
			p = p->next;
			if(p->next == NULL)
			{
				printf("溢出!\n");
				exit(1);
			}
			count++;
		}
		
		pnew->next = p->next;
		p->next = pnew;
	}
	
}

//在链表的p节点删除一个数
void delElem(LNode *h,int in)
{
	LNode *p;
	LNode *del;
	int count = 1;                                      //遍历次数 
	
	if(in == 0 && h != NULL)
	{
		del = h->next;
		h->next = h->next->next;
		free(del);
	}
	else
	{
		p = h->next;
		
		while( count != in-1 )
		{
			p = p->next;
			if(p->next == NULL)
			{
				printf("溢出!\n");
				exit(1);
			}
			count++;
		}
		del = p->next;
		p->next = p->next->next;
		free(del);
	}

}

//给出某值查找是否出现在链表里
void searchElem(LNode *h, Datatype elem) 
{
	LNode *tmp;
	int flag = 0;
	int count = 1;
	tmp = h->next;
	
	while( tmp!=NULL )
	{
		if(tmp->data == elem)
		{
			printf("找到,为第%d个元素!\n",count);
			flag = 1;
		}
		tmp = tmp->next;
		count++;
	}
	
	if(flag == 0)
	{
		printf("没有找到!\n");
	}

}


//删除表中大于min，小于max的元素
void fun(LNode *h, Datatype min, Datatype max)
{
	LNode *p;
	LNode *tmp;
	
	p = h->next;
	tmp = h;
	while( p != NULL )
	{
		if( (p->data > min) && (p->data < max) )
		{
			tmp->next = p->next;
			free(p);
		}
		else
		{
			tmp->next = p;
			tmp = tmp->next;
		}
		p = tmp->next;
	}
		
} 

//测试代码 
int main()
{
	LNode h;
	
	createList(&h);
	outputList(&h);
	getLength(&h);
	printf("\n");
	
	/*changElem(&h, 5, 80);
	outputList(&h);
	getLength(&h);
	printf("\n");
	
	insertElem(&h, 5, 100);
	outputList(&h);
	getLength(&h);
	printf("\n");
	
	Eleminsert(&h, 1, 100);
	outputList(&h);
	getLength(&h);
	printf("\n");
	
	delElem(&h, 5);
	outputList(&h);
	getLength(&h);
	printf("\n");
	
	searchElem(&h, 45);
	printf("\n");*/
	
	printf("aaaaaaaaaa\n");
	
	fun(&h, 5, 10);
	outputList(&h);
	getLength(&h);
	printf("\n");
	
	clearList(&h); 
}
