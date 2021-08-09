/*
    适用于标准C
	SeqList.c
	V1.2
	2016.9.28 wangx
*/
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define OVERFLOW 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

#define Elemtype char

//公共错误码，项目组成员之间的共同约定
#define MALLOC_ERROR  -1  
#define NOTFIND  -2
#define PARAM_ERROR -3
#define REALLOC_ERROR  -4  
//顺序表的结构定义
typedef struct 
{
	Elemtype *pElem;    //动态模式，只定义了一个指针，未分配数据的存储空间。本例假设每个元素都是char型，此处是实际应用中每个元素可能会是结构体变量或者结构体指针
	int iCount;         //当前长度
	int iTotalLength;   //线性表的总长度
}SeqList;               //定义一个新类型，顺序表的类型名称


//你这个菜鸟的任务，就是写这个InitList()函数。
//因为本子函数想通过子函数的操作，更改主调函数中某个指针的指向，则需要用到二重指针（要在子函数中修改实参的值，需要加一重指针，而这个实参变量还是个一重指针，所以这里累计是1+1=2重指针了！！）
//本函数假设要修改的实参指针只是一个指针变量（占4个字节，初始指向哪里不重要，为NULL也行），尚未指向任何结构体变量。
int InitList(SeqList **ppList)
 {
	SeqList *pTemp; //在子函数的栈区定义一个临时指针，以方便本函数中后续的建表过程中的各行代码的书写

	pTemp= (SeqList*)malloc(sizeof(SeqList));  //先申请12个字节，用于存放顺序表的基本结构，iCount，ITotalLength和pElem成员才会存在
	if(pTemp==NULL)
	{
		return MALLOC_ERROR;
	}
	pTemp->iCount=0; //初始时，一个元素都没有
	pTemp->iTotalLength= LIST_INIT_SIZE;  //初始时理论总长就是100个元素（假定值）
	pTemp->pElem= (Elemtype *)malloc( LIST_INIT_SIZE * sizeof(Elemtype));  //因为SeqList的定义中，elem只是一个指针，需要分配空间并让该指针指向这段空间。因为malloc可能迸发异常，所以实际中往往会放在try {} catch() {}结构中
	if (pTemp->pElem==NULL)
	{
		free(pTemp);    //将之前申请的基本表结构所占的空间（12个字节）释放
		return MALLOC_ERROR;   //  返回一个非0值（通常是一个负数），表示本子函数非正常结束，以供主调函数识别和采取对应措施
	}

	*ppList= pTemp; //做好顺序表的表结构和数据区域之后，将该结构（在堆区）交付给实参（一个指针）来指向，从而完成pTemp指针的使命。
					//ppList是子函数在栈区中的一个指针变量，它指向主调函数中的一个指针变量，所以*ppList就是主调函数中对应的那个指针（即实参）

	 return 0;      //一般情况下，在实际工程开发中，基本上都默认函数返回值为0表示该函数运行期间没有异常情况
 }

//根据元素的值x，在顺序表pList中，查找其第一次出现的位置下标，并返回(注意，下标可以为0)。如果没找到，则返回NOTFIND，即-2
int SearchByValue(SeqList *pList, Elemtype Value)
{
	int pos=0;
	//重要的步骤，参数校验！一定别忘了！如果Value有一定的现实含义，则还需要对其做参数有效性校验
	if (pList==NULL)
	{
		return PARAM_ERROR;
	}

	while ( pos<=pList->iCount-1 && pList->pElem[pos]!= Value) //一边比较，一边往后移pos的值，直到找到或者到达有效数据的末尾
		pos++;

	if ( pos <= pList->iCount-1 ) //如果是以“找到”的姿态跳出while循环
		return pos;
	else  
		return NOTFIND;    //如果是以“到末尾”的姿态跳出while循环

}

//功能：根据给定的逻辑位置值pos（假设从1开始），在pList指向的顺序表中提取其元素值，存放到pValue指针指向的空间中并返回给主调函数使用
//备注：pValue的写法，展示了C语言如何通过参数传递，将子函数内的数据传出来，给主调函数使用，注意形参写法和调用时的实参写法！
//      pValue指针，假定其已经指向某个存储空间，本函数不再校验它。问题是：这个空间，应该在主调函数中申请，还是在子函数中申请？一般做法是在主调函数中申请！
int GetValue(SeqList *pList, int pos, Elemtype *pValue)
{
	//重要的步骤，参数校验！一定别忘了！如果Value有一定的现实含义，则还需要对其做参数有效性校验
	if (pList==NULL || pList->pElem==NULL || pos<1 || pos >pList->iCount || pValue==NULL)
	{
		return PARAM_ERROR;
	}
	
	*pValue= pList->pElem[pos];                    //获得元素值
	return 0;
}

//功能：根据指定的逻辑位置pos值（假设从0开始），在pList指向的顺序表中，第pos个元素后面插入值为Value的元素
//备注：pos的值应>=0，当pos=0时，全体所有数据都需要后移一格；当pos>=iCount时，全体数据都不需要后移
int SeqListInsert(SeqList *pList, int pos, Elemtype Value)
{
	Elemtype *pNewBase, *p, *q;
	
	if (pList==NULL || pList->pElem==NULL || pos <0 )
	{
		return PARAM_ERROR;
	}
	if ( pos > pList->iCount )
		pos = pList->iCount ;

	//如果当前已经装满，则需要扩展存储空间
	if (pList->iCount == pList->iTotalLength)
	{
		pNewBase= (Elemtype *)realloc(pList->pElem, (pList->iTotalLength + LISTINCREMENT)*sizeof(Elemtype));  //请同学们进一步了解realloc的工作原理，当空间字节数较多时，该函数开销较大！
		if (pNewBase== NULL)
		{
			return REALLOC_ERROR;
		}

		pList->pElem= pNewBase;
		pList->iTotalLength= pList->iTotalLength + LISTINCREMENT;
	}

	q= &(pList->pElem[pos]); //q 指向的这个元素及其后面所有元素都需要后移一格
	for(p= &(pList->pElem[pList->iCount-1]) ; p>=q; p--)  //从后面往前，循环，每个元素后移一格，直到腾出要插入的内存空间。当pos=0时，全体所有数据都需要后移一格；当pos>=iCount时，全体数据都不需要后移
		*(p+1)= *p;

	*q= Value;  //实现插入操作
	pList->iCount++;  //元素增加，别忘了让有效长度值iCount加1——随时维护iCount值的准确性，以方便程序员即时读取，而不是在需要的时候才去数个数
	return 0;
}

//合并无序的顺序表  MergeOption:0 不允许重复  1允许重复
int DisorderSeqListMerge(SeqList *pListA, SeqList *pListB, int MergeOption, SeqList **pListC)
{
	int i, ret;

	if (pListA==NULL || pListA->pElem==NULL || pListB==NULL || pListB->pElem==NULL || MergeOption < 0 || MergeOption > 1 )
	{
		return PARAM_ERROR;
	}

	*pListC= (SeqList *)malloc( sizeof(SeqList));
	if (*pListC==NULL)
	{
		return MALLOC_ERROR;
	}

	(*pListC)->iTotalLength= pListA->iTotalLength + pListB->iTotalLength;
	(*pListC)->pElem= (Elemtype *)malloc( (*pListC)->iTotalLength * sizeof(Elemtype));  
	if ((*pListC)->pElem==NULL)
	{
		if ((*pListC) != NULL)
			free(*pListC);
		*pListC= NULL;
		return MALLOC_ERROR;
	}
	
	//将A表的数据依次复制到C表数据区
	for(i= 0; i<pListA->iCount; i++)
		(*pListC)->pElem[i]= pListA->pElem[i];
	(*pListC)->iCount= pListA->iCount;

	for (i=0; i<pListB->iCount; i++)
	{
		ret = SearchByValue(pListA, pListB->pElem[i]);
		if ( ret >= 0 && MergeOption==0) //现有重复的元素,且不允许重复
		{
			//什么都不做，不执行插入操作
		}
		else  //没找到，没有重复的元素
		{
			SeqListInsert(*pListC, (*pListC)->iCount, pListB->pElem[i]);  //将LB[i]插入到新表LC的末尾
		}
	}

	return 0;
}
 //测试代码，或者主程序代码，在测试InitList函数时，由你自己随意编写；在提交老板后，由项目经理或高级程序员负责编写
void main(void)
{
	int ret, i;
	Elemtype myValue;
	Elemtype *pmyValue= &myValue;
	SeqList *pList1= NULL;    //内存中为pList1这个结构体指针变量分配4个字节         
	//创建演示
	ret= InitList( &pList1 );  //注意，InitList只需要一个指向SeqList**的参数，pList1指针变量指向谁并不重要。
	if (ret==0)
		printf("创建空的顺序表成功！表的理论总长为%d,每次如果不够，自动增长值为%d\n", LIST_INIT_SIZE, LISTINCREMENT);
	else
	{
		printf("未能成功分配顺序表的数据存储空间，创建顺序表失败！");
		return;
	}

	// 给顺序表填入一些初值
	for (i= 0; i<5; i++)
	{
		SeqListInsert(pList1, i, (Elemtype)('H'-i));
	}

	// 遍历并打印顺序表的所有节点，这块也可以用单独的函数来实现
	for (i=0; i< pList1->iCount; i++)
	{
		myValue= pList1->pElem[i];
		printf("%d-->%C\n", i, myValue);
	}

	//访问演示，假设要访问第2个元素
	ret= GetValue(pList1, 2, pmyValue);  //注意在Debug状态下看看*pmyValue的变化，理解数据传递的方向（从子函数给主调函数）
	if (ret==0)
		printf("你要读取表中第%d个元素，其值是%c\n", 2, *pmyValue); //主调函数使用子函数传出来的数据
	else
		printf("你要读取表中第%d个元素，本表不存在这个元素！", 2);

	//无序表的合并
//	DisorderSeqListMerge(&List1, &List2, 1, &pList3);
	return;
}