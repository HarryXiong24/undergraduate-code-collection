/*
    适用于标准C
	LinkList.c
	V1.1
	2016.9.20 wangx
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

//单链表结构定义
typedef struct node
{
	Elemtype	data;
	struct node *next;
}Node, *LinkList;

/*****************************************************************
 *  函数名字：SearchByPos
 *	函数功能：查询指定的单链表中指定位置的元素，获得其结点地址
 *	函数参数：pHead——指向某单链表表头节点的指针，要求非空
 *			  pos——需要插入的逻辑位置（之后），pos大于表长时视为“表尾追加元素”，pos<=0时视为“表头后插入元素”
 *			  ppNode——输出函数，传出该表的第pos个结点的地址（指针），故此处需要用二级指针
 *						如果没找到第pos个元素，则该参数返回NULL，即-2
 *	函数返回：int型，0表示操作正常结束
 *	备    注：同学们可以自己写SearchByValue函数
 *			  该函数如果在类中，可设为public权限，开放
******************************************************************/
//根据逻辑顺序值pos，在单链表pHead中，将第pos个元素结点的地址值以参数形式传出。
int SearchByPos(Node *pHead, int pos, Node **ppNode)
{
	int i;
	Node *p;
	//参数校验
	if (pHead==NULL)
	{
		return PARAM_ERROR;
	}
	i= 0;
	p= pHead;
	while ( i<pos && p->next!= NULL) //当没有数到逻辑顺序的第i个结点 并且 还没有到表尾的时候，则
	{
		p= p->next;          //一边将p指针指向下一个结点
		i++;				 //一边计数
	}

 
	if ( i==pos ) // 如果 i== pos，即p指向第pos个元素了
	{
		*ppNode= p;    //如果是以“找到第pos个元素”的姿态跳出while循环
		return 0;
	}
	else  //如果是p->next== NULL，即以“到表尾”的姿态跳出while循环
	{
		*ppNode= NULL;
		return NOTFIND;
	}

}


/*****************************************************************
 *  函数名字：Insert
 *	函数功能：插入一个元素到指定的单链表中的指定位置后
 *	函数参数：pHead——指向某单链表表头节点的指针，要求非空
 *			  value——需要添加或插入的元素的值，假定元素值是有效的; 可稍作改动，支持结构体变量类型
 *			  pos——需要插入的逻辑位置（之后），pos大于表长时视为“表尾追加元素”，pos<=0时视为“表头后插入元素”
 *	函数返回：int型，0表示操作正常结束
 *	备    注：其实，本函数并无实用。在无序表中，不需要指定插入的位置（因为无序表中元素具体的存储位置并不重要）；
 *			                        在有序表中，其该插入的位置由其值的大小而定，无须指定插入位置pos。
 *			  该函数如果在类中，可设为private权限，不开放
******************************************************************/
int Insert(struct node *pHead, Elemtype value, int pos)
{
	long len;
	int ret;
	struct node *pNew= NULL;
	struct node *pPre= NULL;
	//参数校验
	if (pHead==NULL)
	{
		return PARAM_ERROR;
	}
	//参数调整
	len= pHead->data.ID; //将表头节点中存放的元素个数信息读出来备用
	if (pos >= len)
		pos= len;
	if (pos <0)
		pos= 0;

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
	ret= SearchByPos(pHead, pos, &pPre);
	if (ret== NOTFIND)
	{
		free(pNew);
		return NOTFIND;
	}

	//插入第四步：插入结点
	pNew->next= pPre->next;
	pPre->next= pNew;
	
	//插入第五步：长度值别忘了+1
	pHead->data.ID++;

	return 0;
}

/*****************************************************************
 *  函数名字：AddToTail
 *	函数功能：往“无序”的线性“表尾”后面添加一个元素（即：在表尾追加一个元素结点）
 *	函数参数：pHead——指向某单链表表头节点的指针，要求非空
 *			  value——需要添加的元素的值，假定元素值是有效的; 可稍作改动，支持结构体变量类型
 *	函数返回：int型，0表示操作正常结束
 *	备    注：该函数如果在类中，可设为public权限，开放给上层程序员使用
******************************************************************/
int AddToTail(struct node *pHead, Elemtype value)
{
	int len;
	len = pHead->data.ID;
	return Insert(pHead, value, len);
}

/*****************************************************************
 *  函数名字：AddToHead
 *	函数功能：往“无序”的线性“表头”后面添加一个元素结点
 *	函数参数：pHead——指向某单链表表头节点的指针，要求非空
 *			  value——需要添加的元素的值，假定元素值是有效的; 可稍作改动，支持结构体变量类型
 *	函数返回：int型，0表示操作正常结束
 *	备    注：该函数如果在类中，可设为public权限，开放给上层程序员使用
******************************************************************/
int AddToHead(struct node *pHead, Elemtype value)
{
	return Insert(pHead, value, 0); //在第一个元素之前（即：第0个元素之后）插入元素结点
}


/*****************************************************************
 *   函数名字：createList
 *	函数功能：创建一个空的带表头节点的单向链表
 *	函数参数：HHead二级指针，调用结束后*HHead指向一个单链表结构变量
 *	函数返回：int型，0表示操作正常结束
 *  备    注：表长信息存放在表头节点的Data结构体成员的ID成员中
******************************************************************/
//创建一个带表头结点的链表，完成数据输入和串接
int createList(struct node **HHead)  //一般我们都将指向单链表第一个结点（或表头结点）的指针命名为head，这是习惯约定
{
	struct node *pNew;
	if (HHead==NULL)              //参数校验
		return PARAM_ERROR;
	//创建表头节点
	pNew = (struct node *)malloc(sizeof(struct node));  //申请空间
	if (pNew==NULL)
	{
		return MALLOC_ERROR;
	}
	memset(pNew, 0, sizeof(struct node));
	pNew->data.ID= 0;   //设置该空表头的表长值为0
	pNew->next = NULL;  //空表，没有后续结点。另，养成良好习惯，当结点的next成员指向何方尚不明朗时，先置为NULL以防患于未然，避免野指针。

	*HHead = pNew;      //给表头指针赋值为表头结点的地址。
						//这是套路，先用一个临时变量pNew去操作数据，然后交付给*HHead。
	return 0;     
	      //本函数是如何返回表头指针的？又如何调用本函数呢？思考这2个问题！能画出内存四区图来么？
}

/*****************************************************************
 *   函数名字：createList2
 *	函数功能：创建一个单向链表，并填入数据，以尾插法实现结点挂接
 *	函数参数：
 *	函数返回：struct node * （函数运行结束之后，返回该链表的第一个
 *	          结点的地址给主调函数，以便主调函数根据该地址找到所有
 *			  数据）
 *  备    注：以前学C语言程序设计的老版本，没学过模块化设计和数据结构的人才会这么写
******************************************************************/
//创建一个带表头结点的链表，并且完成数据输入和串接
int createList2(struct node **HHead)  //一般我们都将指向单链表第一个结点（或表头结点）的指针命名为head，这是习惯约定
{
	struct node *pNew;
	struct node *pTail;    
	Elemtype Data;
	if (HHead==NULL)              //参数校验
		return PARAM_ERROR;
	//创建表头节点
	pNew = pTail = (struct node *)malloc(sizeof(struct node));  //申请空间
	if (pNew==NULL)
	{
		return MALLOC_ERROR;
	}
	memset(pNew, 0, sizeof(struct node));

	*HHead = pNew;    //给表头指针赋值为表头结点的地址。后续工作只需要做好挂接，与表头指针再无直接关系。函数返回表头指针即可。
					  //而pNew也能腾出功夫来完成后续的自身任务工作
	(*HHead)->next = NULL;  //养成良好习惯，当结点的next成员指向何方尚不明朗时，先置为NULL以防患于未然，避免野指针。

	printf("请输入学生的5位证件号的值和姓名（空格隔开，ID值为0表示输入结束）：");
	scanf("%ld", &(Data.ID));
	scanf("%s", Data.name);
	//创建并挂接后续的各个结点
	while (Data.ID != END_ID)  //程序员和用户已约定：当用户输入的数据为0（END_ID）时，表示数据录入的结束（注意，此约定不是唯一方法，仅供学习时适用）
	{
		//创建新的结点并赋值
		pNew = (struct node *)malloc(sizeof(struct node));  //申请空间
		if (pNew==NULL)
		{
			return MALLOC_ERROR;
		}
		memset(pNew, 0, sizeof(struct node));

		pNew->data.ID= Data.ID;    //为新结点的data域填入数据
		memcpy(pNew->data.name, Data.name, strlen(Data.name));
		pNew->next = NULL;           //为新结点的next域填入数据，指向不行时填入NULL；或因为其是新的表尾结点，所以也应该将其next域填入NULL表示链表在结尾。

		//将新结点挂接到原链表中，此步骤很关键！
		pTail->next = pNew;          //pTail专门指向链表当前的最后一个结点，此行代码实现了将新结点连入链表尾部（还记得王老师曾经讲过的指针赋值的那句口诀不？务必想起来！）
		pTail = pNew;                //pTail指向的结点已经不是链表的表尾结点了（挂接之后，pNew指向的结点才是新的表尾结点），故而刷新pTail，让其指向新的表尾结点。
		printf("请输入学生的5位证件号的值和姓名（空格隔开，ID值为0表示输入结束）：");
		scanf("%ld", &(Data.ID));
		scanf("%s", Data.name);
	}
	return 0;     //本函数是如何返回表头指针的？思考这个问题！
}

/*****************************************************************
    函数名字：output
	函数功能：输出单链表的所有结点数据，在屏幕上显示打印
	函数参数：单链表的表头指针head（有了它，我们就能顺藤摸瓜，找出所有数据）
	函数返回：无（这是一个打印或显示类型的函数，不需要返回任何数据）
******************************************************************/
void output(struct node *head)
{
	struct node *p;
	if (head==NULL) //参数如果不正确，则直接罢工
		return;
	p = head->next;  //"顺藤"，从head->next开始，跳过表头节点的Data域不打印
	while (p != NULL)   //到尾。注意，单链表的最后一个结点的next域的值为NULL，本块代码也是读取单链表的标准模板
	{
		printf("%6d  ", p->data.ID);  //"摸瓜"
		printf("%s\n",  p->data.name);
		p = p->next;              //千万别忘记本行，否则死循环了
	}
	return ;
}

/*****************************************************************
 *  函数名字：DelByPos
 *	函数功能：删除指定单链表中指定逻辑顺序位置的元素结点，并将删除的元素的值提取出来
 *	函数参数：pHead——指向某单链表表头节点的指针，要求非空
 *			  pos——需要删除的结点的逻辑序号，pos大于表长或者pos<=0时视为“参数不合法”
 *			  pValue——指向被删除元素的值，以方便在有些应用场合中对其做死前最后可能的访问操作。
 *	函数返回：int型，0表示操作正常结束
 *	备    注：该函数如果在类中，可设为public权限，开放。同学们可以自行练习DelByValue函数。
 ******************************************************************/
int DelByPos(struct node *pHead, int pos, Elemtype *pValue)
{
	int ret;
	struct node *pDel= NULL;
	struct node *pPre= NULL;
	//参数校验
	if (pHead==NULL)
	{
		return PARAM_ERROR;
	}
	//删除第一步：找到第pos-1个结点的地址，顺带着也就校验了pos值是否过大
	ret= SearchByPos(pHead, pos-1, &pPre); //要删除第pos个元素，在链表这种结构中，需要获取到第pos-1个元素的地址，以方便删除操作
	if (ret== NOTFIND) //如果本来该表压根就没有第pos-1个元素，那无法完成删除，pos值过大！
	{
		return PARAM_ERROR;
	}

	//删除第二步：获取第pos个结点的地址并暂存该地址（函数的任务就是要删这个结点）
	pDel= pPre->next; 
	if (pDel==NULL)  //有第pos-1个结点，但恰好没有第pos个结点的情况，仍然归咎于pos参数传入错误
	{
		return PARAM_ERROR;
	}

	//删除第三步：将第pos个结点从链表中摘下来，使其脱离链表
	pPre->next= pPre->next->next;

	//删除第四步：（非必须的步骤）将该结点的值拷贝出来，以备上层函数使用
	pValue->ID= pDel->data.ID;
	memset(pValue->name, 0, strlen(pValue->name));
	memcpy(pValue->name, pDel->data.name, strlen(pDel->data.name));

	//删除第五步：释放pDel指针所指向的结点空间（在堆区），注意，并不是释放pDel指针变量本身这4个字节哦！
	free(pDel);
	pDel=NULL;  //指针复位操作。可以看出，pDel指针仍然存在，有值，但其指向的空间已被回收。为了避免误操作，特意将这4个字节的空间全部清0，即让pDel指针为NULL
	
	//删除第六步：长度值别忘了-1
	pHead->data.ID--;

	return 0;
}



int main(void)
{
	int ret, pos;
	struct node *pHead1;
	Elemtype value;

	//创建链表1，并填入数据
	ret= createList(&pHead1);
	value.ID= 10;
	memset(value.name, 0, 20);
	memcpy(value.name,"张三", 4);
	AddToTail(pHead1, value);

	value.ID= 20;
	memset(value.name, 0, 20);
	memcpy(value.name,"李四", 4);
	AddToTail(pHead1, value);

	value.ID= 30;
	memset(value.name, 0, 20);
	memcpy(value.name,"王麻子", 6);
	AddToTail(pHead1, value);

	value.ID= 40;
	memset(value.name, 0, 20);
	memcpy(value.name,"赵大膀子", 8);
	AddToTail(pHead1, value);
	

	output(pHead1);  //输出显示单链表的所有数据
	
	printf("=========下面演示删除=====================\n");
	pos= 2;
	ret= DelByPos(pHead1, pos, &value); //删除第5个
	if (ret== 0)
		printf("我删除了%s这个结点\n", value.name);
	else
		printf("我没法删除第%d个结点\n", pos);
	output(pHead1);  //输出显示单链表的所有数据

//	printf("=========下面用过时的创建函数演示一下========\n");
//	ret= createList2(&pHead2); //用老方法来创建，在创建的同时就在插入元素，模块的划分有点混乱
//	output(pHead2);
	return 0;
}
