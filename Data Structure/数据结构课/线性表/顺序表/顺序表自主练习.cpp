#include <stdio.h>
#include <stdlib.h> 

#define LIST_INIT_SIZE 5                                                       //为了方便测试写的很小 
#define Elemtype int

typedef struct{
	Elemtype *pElem;
	int Count;
	int TotalCount;
}SeqList;

void initSeqList(SeqList **pList);                                             //创建一个顺序表

void enlargeSeqList(SeqList *pList);                                           //扩展空间的函数
/*可以任意的输入想扩展的空间，若空间没满此函数不会触发。*/
 
void addElem(SeqList *pList, Elemtype addCount); 			                   //给顺序表添加初值
void printSeqList(SeqList *pList);                                             //打印顺序表 
int lengthList(SeqList *pList);                                                //获取表的长度 

int *searchSeqList(SeqList *pList, Elemtype searchNum, Elemtype *pos);        //查找元素出现的位置
/*输入元素，获取该位置的值
采用了指针返回方法，解决了上课说的问题 
*/
 
int *getValue(SeqList *pList, Elemtype getpos);                                //获取某个元素位置的值
/*获取第一次出现元素的值*/

void insertElem(SeqList *pList, Elemtype inpos, Elemtype invalue);             //按指定位置插入元素 
/*没有讨论前插与后插,
而是想在哪个位置插入就输入哪个位置，然后直接在输入的位置完成插入,
支持插入顺序表长度再下一个位置的插入,
如果超过初始长度，此跳转到扩展空间函数， 
没有满足上述情况则有提示。*/ 

void delElem(SeqList *pList, Elemtype depos);                                  //按指定位置删除元素
/*输入那个位置则删除该位置的值，输入错误则有提示。*/ 



//创建一个顺序表
void initSeqList(SeqList **pList)
{
	SeqList *pTemp = NULL;
	int i = 0;
	
	pTemp = (SeqList *)malloc(sizeof(SeqList));
	
	pTemp->Count = 0;
	pTemp->TotalCount = LIST_INIT_SIZE;
	pTemp->pElem = (Elemtype *)malloc( LIST_INIT_SIZE * sizeof(Elemtype) );
	
	if(pTemp->pElem == NULL)
	{
		printf("ERROR!\n");
		exit(1);
	}
	
	*pList = pTemp;
	printf("The new empty SeqList is done!\nThe init size is %d.\n\n", LIST_INIT_SIZE);
}	

//扩展空间的函数
void enlargeSeqList(SeqList *pList)
{
	Elemtype enlargeNum;
	Elemtype *pLarge = NULL;
	
	printf("The size is overflow!\nPlease input the count you need to enlarge:\n");
	scanf("%d", &enlargeNum);
	
	pLarge = (Elemtype *)realloc(pList->pElem, (LIST_INIT_SIZE + enlargeNum)*sizeof(Elemtype) );
	
	if(pLarge == NULL)
	{
		printf("ERROR!\n");
		exit(1);
	}
	
	pList->pElem = pLarge;
	
	printf("Enlarge successfully!\n\n");
} 

//给顺序表添加元素
void addElem(SeqList *pList, Elemtype addCount) 
{
	Elemtype i = 0;
	
	if(addCount > pList->TotalCount)
	{
		enlargeSeqList(pList);
	}
	
	pList->Count = addCount;
	
	for(i = 0; i < pList->Count; i++)
	{
		printf("Please input the No.%d number:\n", i+1);
		scanf("%d", &(pList->pElem[i]) );
	}
	
	printf("Creation is done!\n\n");
}

//打印顺序表
void printSeqList(SeqList *pList)
{
	Elemtype i = 0;
	
	for(i = 0; i < pList->Count; i++)
	{
		printf("The NO.%d is %d.\n", i+1, pList->pElem[i]);
	} 
}

//获取表的长度 
int lengthList(SeqList *pList)
{
	return pList->Count; 
}

//查找元素 
int *searchSeqList(SeqList *pList, Elemtype searchNum, Elemtype *pos)
{
	static Elemtype i = 0;
	
	if (pList==NULL)
	{
		printf("ERROR!\n");	
		exit(1);
	}

	while(i < pList->Count && pList->pElem[i] != searchNum)
	{
		i++;
	}
	
	if ( i < pList->Count ) 
	{
		i = i+1;
		pos = &i;
		return pos; 
	}
	else
	{
		return NULL;
	}
}

//获取位置值
int *getValue(SeqList *pList, Elemtype getpos)
{
	
	if (pList == NULL || pList->pElem == NULL || getpos < 1 || getpos > pList->Count)
	{
		return NULL;
	}
	                
	return &(pList->pElem[getpos-1]);
}
 
//按指定位置插入元素 
void insertElem(SeqList *pList, Elemtype inpos, Elemtype invalue) 
{
	int i;
	
	if(inpos <= 0 || inpos > pList->Count+1 )
	{
		printf("Please check the position you inserted.\n\n");		
	}	
	else
	{
		pList->Count++;
		
		if(pList->Count >= pList->TotalCount)
		{
			enlargeSeqList(pList);
		}
		
		if(inpos == pList->Count)
		{
			pList->pElem[pList->Count-1] = invalue;
		}
		else
		{
			for(i = pList->Count-1; i >= inpos; i--)
			{
				pList->pElem[i] = pList->pElem[i-1];
			}
			
			pList->pElem[inpos-1] = invalue;
		}
		
		printf("Insert successfully!\n\n");
		printf("Here are the all number which were printed:\n");
		printSeqList(pList);
	}
}

//按指定位置删除元素
void delElem(SeqList *pList, Elemtype depos)
{
	int i;
	
	if(pList == NULL )
	{
		printf("The empty SeqList!\n\n");
	}
	else if(depos < 1 || depos > pList->Count)
	{
		printf("Overflow!\n\n");
	} 
	else
	{
		for(i = depos-1; i < pList->Count; i++)
		{
			pList->pElem[i] = pList->pElem[i+1];
		}
		
		pList->Count--;
		
		printf("Delete successfully!\n\n");
		printf("Here are the all number which were printed:\n");
		printSeqList(pList);
	}
}

//销毁顺序表
void clearSeqList(SeqList **pList) 
{
	free( (*pList)->pElem );
	free(pList);
	
	*pList = NULL;
}

//测试函数 
int main()
{
	SeqList *pList = NULL;
	Elemtype addCount;
	
	Elemtype searchNum, *pos;
	Elemtype getpos, *value = NULL;
	
	Elemtype inpos, invalue;
	Elemtype depos;
	Elemtype lenth;
	
	//初始化 
	initSeqList(&pList);
	
	//添加元素 
	printf("Please input the count of your init SeqList:\n");
	scanf("%d", &addCount);
	printf("\n");
	addElem(pList, addCount); 
	
	//打印元素 
	printf("Here are the all number which were printed:\n");
	printSeqList(pList);
	
	//查找元素 
	printf("\nPlease input the value your need to search:\n");
	scanf("%d", &searchNum);
	pos = searchSeqList(pList, searchNum, pos);
	if(pos == NULL)
	{
		printf("No this element!\n\n");
	}
	else
	{
		printf("This is in the NO.%d.\n\n", *pos);
	}
	
	//获取某个元素位置的值
	printf("Please input the position your need to get value:\n");
	scanf("%d", &getpos);
	value = getValue(pList, getpos);
	if(value == NULL)
	{
		printf("This position has no value!\n\n");
	}
	else
	{
		printf("The value is %d.\n\n", *value);
	}
	
    //按指定位置插入元素 
	printf("Please input position and value:\n");
	scanf("%d %d", &inpos, &invalue); 
	insertElem(pList, inpos, invalue); 
	
	//按指定位置删除元素
	printf("\nPlease input position you need to delete:\n");
	scanf("%d", &depos); 
	delElem(pList, depos);
	
	//获取表的长度
	lenth = lengthList(pList);
	printf("\nThe lenth is %d", lenth);
	
	//销毁顺序表
	clearSeqList(&pList);
}

