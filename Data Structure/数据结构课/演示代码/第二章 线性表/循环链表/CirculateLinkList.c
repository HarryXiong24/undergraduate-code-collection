/*
    适用于标准C
	CirculateLinkList.c
	V1.0
	2016.9.22 wangx

	假定该循环链表没有表头结点。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //for memcpy

#define OK 1
#define OVERFLOW 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct  person
{
	long ID;
	char name[20];
}Elemtype;

//公共错误码，项目组成员之间的共同约定
#define MALLOC_ERROR  -1  
#define NOTFIND  -2
#define PARAM_ERROR -3
#define REALLOC_ERROR  -4  
#define END_ID  0  

//循环链表结构定义
typedef struct node
{
	Elemtype	data;
	struct node *next;
}Node, *CirculateLinkList;

/*****************************************************************
 *   函数名字：createList
 *	函数功能：创建一个空的带表头节点的单向链表
 *	函数参数：HHead二级指针，调用结束后*HHead为空
 *	函数返回：int型，0表示操作正常结束
 *  备    注：因为没有表头结点，所以空的循环链表非常简单，头指针为空即可
 *			  循环链表和普通单链表的重大区别在于：循环链表往往为了在循环的时候方便操作，从而去掉了表头结点，
 *			  这意味着在增或者删的子函数内部有可能会出现影响到实参的情况，例如从空表变成有数据的表时，或者从有数据的表变成空表时，
 *			  所以，在增删等可能涉及到结点增减的所有操作中，起始点地址参数应该是二级指针
******************************************************************/
int createList(struct node **HHead)  //本循环链表没有表头结点，
{
	*HHead= NULL;   //当一个结点都没有的时候，所谓的“头指针*HHead”只能指向NULL
	return 0;
}


/*****************************************************************
 *  函数名字：SearchByPos
 *	函数功能：查询循环链表中从指定结点开始往后数的第pos个元素，获得该结点地址
 *	函数参数：pStart——起始结点的地址
 *			  pos——需要插入的逻辑位置（之后），pos可以大于表长，因为是循环链表，大不了多转几圈得了，但是不支持<0的情况（因为是单向链表）
 *			  ppNode——输出函数，传出第pos个结点的地址（指针），故此处需要用二级指针
 *						如果没找到第pos个元素，则该参数返回NULL，即-2
 *	函数返回：int型，0表示操作正常结束
 *	备    注：同学们可以自己写SearchByValue函数
 *			  该函数如果在类中，可设为public权限，开放
 *			  该函数不会涉及到数据结点的变化，所以不需要二级指针
******************************************************************/
int SearchByPos(Node *pStart, int pos, Node **ppNode)
{
	int i;
	Node *p;
	//参数校验
	if (pStart==NULL)
	{
	//	return PARAM_ERROR;  pStart是起始点的地址，如果它为NULL，表示这是一个空表。向空表里搜索第pos个结点，必然不存在，所以该结点地址必会为NULL，但属于正常结束
		*ppNode= NULL;
		return 0;
	}

	i= 1;
	p= pStart;
	while ( i<pos ) //当没有数到逻辑顺序的第i个结点（注意，有可能重复转很多圈哦~有些项目经理认为这是合理的，有些则认为不合理，所以，具体情况具体分析。如果不允许重复转圈，则此处应加判断条件，判断其是否已转完一圈）
	{
		p= p->next;          //一边将p指针指向下一个结点
		i++;				 //一边计数
	}

	*ppNode= p;    //如果是以“找到第pos个元素”的姿态跳出while循环
	return 0;
}


/*****************************************************************
 *  函数名字：Insert
 *	函数功能：插入一个元素到指定的循环链表中的指定位置后
 *	函数参数：ppStart——指向某循环链表某起始结点的指针，空表时*ppStart的值为NULL
 *			  value——需要添加或插入的元素的值，假定元素值是有效的; 可稍作改动，支持结构体变量类型
 *			  pos——需要插入的逻辑位置（之后），pos大于表长时视为“表尾追加元素”，pos<=0时视为“表头后插入元素”
 *	函数返回：int型，0表示操作正常结束
 *	备    注：其实，本函数并无实用。在无序表中，不需要指定插入的位置（因为无序表中元素具体的存储位置并不重要）；
 *			                        在有序表中，其该插入的位置由其值的大小而定，无须指定插入位置pos。
 *			  该函数如果在类中，可设为private权限，不开放
******************************************************************/
int Insert(struct node **ppStart, Elemtype value, int pos)
{
	int ret;
	struct node *pNew= NULL;
	struct node *pPre= NULL;
	//参数校验
	if (ppStart==NULL)
	{
		return PARAM_ERROR;  
		//因为无表头结点，所以当向空表里插入第一个结点之前，*ppStart为NULL，但是ppStart不应为NULL，
		//因为ppStart是篮子，*ppStart是水果，还记得王老师上课时关于二级指针的举例么？
		//所以，此处不再需要对*ppStart的内容做判断，允许其为空（事实上在加入第一个结点之前，*ppStart的内容就是NULL）
		//想想内存四区图？
	}

	//插入第一步：申请新结点空间
	pNew= (struct node *)malloc(sizeof(struct node));
	if (pNew==NULL)
	{
		return MALLOC_ERROR;
	}

	//插入第二步：填值到新结点空间，准备就绪
	memset(pNew, 0, sizeof(struct node));
	pNew->data.ID= value.ID; //此处不能直接写成pNew->data= value;
	memcpy(pNew->data.name, value.name, strlen(value.name));
	pNew->next= NULL;

	//插入第三步：找到第pos个结点，以备在其后插入新结点
	ret= SearchByPos(*ppStart, pos, &pPre);
	if (ret== PARAM_ERROR)
	{
		free(pNew);
		return PARAM_ERROR;
	}

	if (pPre== NULL)  //如果循环链表中有数据，则不可能数不到第pos个结点，pPre指针也不可能为NULL。只有当循环链表为空表时，pPre才会为NULL
	{
		pNew->next= pNew;  //产生只有一个结点的循环链表
		*ppStart= pNew;    //将这个循环链表交付给主调函数带回
	}
	else
	{	//插入结点
		pNew->next= pPre->next;
		pPre->next= pNew;
	}
	return 0;
}

/*****************************************************************
    函数名字：GetLength
	函数功能：获得循环链表的元素个数
	函数参数：循环链表的起始指针pHead
	函数返回：无（这是一个打印或显示类型的函数，不需要返回任何数据）
	备    注：注意，在循环链表中，“到表尾最后一个结点”的判断条件不再是p->next==NULL，而是p->next==pHead
******************************************************************/
int GetLength(struct node *pHead)
{
	struct node *p;
	int count;
	if (pHead==NULL)  //空表的长度为0，直接返回0即可
		return 0; 

	p= pHead;
	count= 1;         //在pHead不为空的情况下，表中至少有一个结点，所以count不从0，而是从1开始计数
	while (p->next!= pHead)  //如果除了这个起始结点之外，还有后续结点
	{
		count++;
		p = p->next;              //千万别忘记本行，否则死循环了
	}
	return count;
}


/*****************************************************************
 *  函数名字：AddToTail
 *	函数功能：往“无序”的线性“表尾”后面添加一个元素（即：在表尾追加一个元素结点）
 *	函数参数：ppHead——指向某循环链表表头节点的指针，要求非空
 *			  value——需要添加的元素的值，假定元素值是有效的; 可稍作改动，支持结构体变量类型
 *	函数返回：int型，0表示操作正常结束
 *	备    注：该函数如果在类中，可设为public权限，开放给上层程序员使用
******************************************************************/
int AddToTail(struct node **ppHead, Elemtype value)
{
	int len;
	len= GetLength(*ppHead);
	return Insert(ppHead, value, len);
}


/*****************************************************************
 *  函数名字：AddToHead
 *	函数功能：往“无序”的线性“表头”后面添加一个元素结点
 *	函数参数：pHead——指向某循环链表表头节点的指针，要求非空
 *			  value——需要添加的元素的值，假定元素值是有效的; 可稍作改动，支持结构体变量类型
 *	函数返回：int型，0表示操作正常结束
 *	备    注：该函数如果在类中，可设为public权限，开放给上层程序员使用
******************************************************************/
int AddToHead(struct node **ppHead, Elemtype value)
{
	return Insert(ppHead, value, 0); //在第一个元素之前（即：第0个元素之后）插入元素结点
}


/*****************************************************************
    函数名字：output
	函数功能：输出循环链表的所有结点数据，在屏幕上显示打印
	函数参数：循环链表的表头指针head（有了它，我们就能顺藤摸瓜，找出所有数据）
	函数返回：无（这是一个打印或显示类型的函数，不需要返回任何数据）
******************************************************************/
void output(struct node *head)
{
	struct node *p;
	if (head==NULL) //参数如果不正确，则直接罢工
		return;
	p = head;  //从头，从第一个结点开始
	do         //到尾。注意，循环链表的最后一个结点的next域的值为NULL，本块代码也是读取循环链表的标准模板
	{
		printf("%6d  ", p->data.ID);  //"摸瓜"
		printf("%s\n",  p->data.name);
		p = p->next;              //千万别忘记本行，否则死循环了
	}while (p != head);   //因为该循环链表没有表头结点，所以先输出，再判断是否需要往下走，直到遇到起始点head
	return ;
}

int main(void)
{
	int ret;
	struct node *pHead1;
	Elemtype value;

	//创建链表1，并填入数据
	ret= createList(&pHead1);
	value.ID= 10;
	memset(value.name, 0, 20);
	memcpy(value.name,"张三", 4);
	AddToTail(&pHead1, value);

	value.ID= 20;
	memset(value.name, 0, 20);
	memcpy(value.name,"李四", 4);
	AddToTail(&pHead1, value);

	value.ID= 30;
	memset(value.name, 0, 20);
	memcpy(value.name,"王麻子", 6);
	AddToTail(&pHead1, value);

	value.ID= 40;
	memset(value.name, 0, 20);
	memcpy(value.name,"赵大膀子", 8);
	AddToTail(&pHead1, value);

	output(pHead1);  //输出显示循环链表的所有数据
	return 0;
}