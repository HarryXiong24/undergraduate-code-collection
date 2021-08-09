#include <stdio.h>
#include <stdlib.h>

#define Elemtype int

//错误码 
#define PARAM_ERROR -1
#define NOTFIND  -2
#define MALLOC_ERROR  -3  
#define CANNOT_DEL  -4

typedef struct node{
	Elemtype data;
	struct node *next;
}LNode;

//本版本链表从1开始记数 
 
//创建表头节点 
int createList(LNode **head)
{
	LNode *pTemp = NULL;
	
	if(head == NULL)
	{
		return PARAM_ERROR;
	}
	
	pTemp = (LNode *)malloc(sizeof(LNode));
	if(pTemp == NULL)
	{
		return MALLOC_ERROR;
	}
	
	pTemp->data = 0;
	pTemp->next = NULL;
	
	*head = pTemp;
	
	return 0;
}

//查找函数,根据位置查找元素是否存在 
int searchByPos(LNode *head, int pos, LNode **p)
{
	LNode *pTemp;
	int i = 0;
	
	if(head == NULL)
	{
		return PARAM_ERROR;
	}
	
	pTemp = head;
	
	while(pTemp->next != NULL && i < pos)
	{
		pTemp = pTemp->next;
		i++;
	}
	
	if( i == pos )                    //找到的情况 
	{
		*p = pTemp;
		return 0;
	}
	else                              //没有找到的情况 
	{
		*p = NULL;
		return NOTFIND;
	}
} 

//根据位置插入值
int insertValue(LNode *head, int pos, Elemtype value)
{
	LNode *pNew;
	LNode *pTemp;
	
	if(head == NULL)
	{
		return PARAM_ERROR;
	}
	
	pNew = (LNode *)malloc(sizeof(LNode));
	if(pTemp == NULL)
	{
		return MALLOC_ERROR;
	}
	pNew->data = value;
	pNew->next = NULL;
	
	searchByPos(head, pos-1, &pTemp);                //寻找插入位置前一个位置 
	
	pNew->next = pTemp->next;
	pTemp->next = pNew;
	
	return 0;
} 

//获取链表长度
int getLenth(LNode *head)
{
	LNode *pTemp;
	int len = 0;
	
	if(head == NULL)
	{
		return PARAM_ERROR;
	}
	
	pTemp = head->next;
	
	while( pTemp != NULL)
	{
		len++;
		pTemp = pTemp->next;
	}
	
	return len;
}


//头插
int insertHead(LNode *head, Elemtype value) 
{
	int flag;
	
	flag = insertValue(head, 1, value);
	
	return flag;
}

//尾插
int insertTail(LNode *head, Elemtype value) 
{
	int flag,len;
	
	len = getLenth(head);
	
	flag = insertValue(head, len+1, value);                //因为插入队尾，所以应当为len+1个位置 
	
	return flag;
}

//指定位置删除元素
int delValue(LNode *head, int pos)
{
	LNode *pTemp1;
	LNode *pTemp2;
	int flag;
	
	if(head == NULL)
	{
		return PARAM_ERROR;
	}
	
	flag = searchByPos(head, pos-1, &pTemp1);
	
	if(flag == NOTFIND )
	{
		return CANNOT_DEL;
	}
	
	pTemp2 = pTemp1->next;
	pTemp1->next = pTemp1->next->next;
	
	free(pTemp2);
	
	return 0;
} 

//打印链表
int printList(LNode *head) 
{
	LNode *pTemp;
	
	if(head == NULL)
	{
		return PARAM_ERROR;
	}
	
	pTemp = head;
	
	while( pTemp->next != NULL)
	{
		pTemp = pTemp->next;
		printf("%d\n", pTemp->data);
	}
	
	return 0;
}
 
//清空链表
int clearList(LNode *head) 
{
	LNode *pTemp1;
	LNode *pTemp2; 
	
	if(head == NULL)
	{
		return PARAM_ERROR;
	}
	
	pTemp1 = head;
	
	while(pTemp1->next != NULL)
	{
		pTemp2 = pTemp1->next;
		pTemp1->next = pTemp1->next->next;
		free(pTemp2);
		pTemp2 = NULL;
	}
	
	return 0;
}

//销毁链表
int delList(LNode **head)  
{
	if(*head == NULL)
	{
		return PARAM_ERROR;
	}
	
	clearList(*head);                  //销毁之前先清空 
	
	free(*head);
	*head = NULL;
	
	return 0;
}

int main()
{
	LNode *p;
	int num, i, value;
	int len = 0;
	
	createList(&p);
	printf("Create a LinkNode!\n");
	
	//头插演示,初始化链表元素 
	printf("\n********************InsertHead Testing********************\n");
	printf("Please input the number you need to insert:\n");
	scanf("%d", &num);
	for(i = 0; i < num; i++)
	{
		printf("Please input the NO.%d value:\n", i+1);
		scanf("%d", &value);
		insertHead(p, value);
	}
	
	//打印初始化数据 
	printf("\n********************Print Testing********************\n");
	printf("The List print:\n");
	printList(p);
	
	//打印当前链表长度 
	printf("\n********************GetLenth Testing********************\n");
	len = getLenth(p); 
	printf("The List len is %d.\n", len);
	
	//删除其中一个元素并打印结果 
	printf("\n********************DelValue Testing********************\n");
	delValue(p, 2);
	printf("The List print:\n");
	printList(p);
	
	//尾插一个元素并打印结果 
	printf("\n********************InsertTail Testing********************\n");
	insertTail(p, 100); 
	printf("The List print:\n");
	printList(p);
	
	//给定位置插入一个元素并打印结果 
	printf("\n********************InsertValue Testing********************\n");
	insertValue(p, 4, 200); 
	printf("The List print:\n");
	printList(p);
	
	//销毁链表 
	delList(&p); 
	printf("\nDelete LinkNode!\n");
	
	return 0;
}
 

