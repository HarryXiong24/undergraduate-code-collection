/*
    适用于标准C， 静态数组版本（这不是static的意思，而是data[]这种写法）
	SeqList.c
	V1.0
	2019.9.9 wangx
	后面的函数作为作业，让同学们去完成！
*/
#include <stdio.h>
#include <stdlib.h>
#define INIT_SIZE 10000  // 实际工业编程中，这个数字会很大！！

typedef struct 
{
	// 因为线性顺序表很大（10000只是教学范例），所以下面所有函数在传参时，如果要传表，都建议传指针，直接针对原件进行操作！不建议传结构体变量（容易会把栈区撑爆）
	// 如果是int *pdata; 这样的写法，则pdata只有4个字节，SeqList结构体变量的空间量大大缩小，就会方便很多，但就变成动态数组了（需要在堆区中开辟空间来存储数据）
	int data[INIT_SIZE];  // 10000个元素，40000个字节。
	int length;           // 4个字节
	int listsize;         // 4个字节
}SeqList;

SeqList InitList()
{
	SeqList tt; 
	tt.length = 0;
	tt.listsize = INIT_SIZE;
	return tt;
}

// 因为顺序表是通过传参进来的，其内部数据在插入操作中会被修改，所以此处形参应该设为指针，去操作main函数中对应的实参list1
// 如果第一个参数设为SeqList，而不是SeqList *，则pL就不再是一个指针，而变成了栈区中的一个结构体变量（408个字节），对它的修改操作根本不会影响到list1
// 本例中，i表示下标位置，从0开始编号的。如果要从1开始编号，下面代码都需要微调
int listInsert(SeqList *pL, int i, int value)
{
	int j;
	// 3.参数校验
	if (i > pL->length || i < 0 || pL == NULL)
		return -1;  // 参数有误，返回错误码 -1
	// 4.考虑极端情况
	if (pL->length >= pL->listsize)
		return -2;  // 表满，出现上溢，返回错误码 -2 （静态数组版本的线性表，没法进行表空间扩充，这一点和用指针来表示的动态数组版本的不一样）
	// 5.到现在才处理常规套路
	for(j= pL->length; j>i; j--)
		pL->data[j] = pL->data[j-1];

	pL->data[j] = value;
	pL->length++;  // 这句千万别忘了！
	return 0;
}

// 本函数虽然没有改变线性表实参，但是因为线性表实在是太大了，为节省栈空间，提高效率，建议用指针来操作原件，而不是操作栈区中的结构体变量复印件
int getValue(SeqList *pL, int i)
{
	// 3. 参数校验
	if (i<0 || i> pL->length-1 || pL == NULL)
		return -1;
	// 4. 考虑极端情况，本函数没有极端情况，不写
	// 5. 常规套路，顺序存储结构可以直接提取第i个元素，很简单，就一句话
	return pL->data[i];
}

void printAll(SeqList *pL)
{
	int i;
	if (pL == NULL)
		return;
	for(i=0; i<pL->length; i++)
		printf("%d  ", getValue(pL, i));
	return;
}

// 删除值为x的元素
int valueDelete(SeqList *pL, int x)
{
	int i = 0, n = 0;
	int flag = 0;                     // 用于判断是否找到值，找到为1，没找到为0
	
	if(pL->length == 0)
	{
		return -2;                    // 表为空，无法删除 
	}
	
	for(n = 0; n < pL->length; n++)   // 用于遍历顺序表，直到找到位置退出
	{
		if(pL->data[n] == x)
		{
			flag = 1;
			break;
		}
	}
	
	if(flag == 1)                    // 找到
	{
		for(i = n; i < pL->length; i++)
		{
			pL->data[i]= pL->data[i+1];
		}
		pL->length--;
		
		return 0;                   // 操作成功 
	}
	else                            // 没有找到
	{
		return 1;                   // 这个值没有存在于顺序表中 
	}
}

// 删除第i个元素（i从0开始编号）
int listDelete(SeqList *pL, int n)
{
	int i;
	
	if(pL->length == 0)
	{
		return -2;                 // 表为空，无法删除 
	}
	else if(n < 0 || n > pL->length)
	{
		return -1;                 // 位置参数有误，返回错误码 -1
	}
	else
	{
		for(i = n-1; i < pL->length; i++)
		{
			pL->data[i] = pL->data[i+1];
		}
		pL->length--;
		
		return 0; 
	}
}

// 返回表长
int getLength(SeqList *pL)
{
	return pL->length;
}

// 合并无序表(因为静态数组版本不能扩充空间，所以需要先检验AB两表有效数据个数，不能超过INIT_SIZE，否则只能罢工)
int mergeUnorderedList(SeqList *pL1, SeqList *pL2)
{
	int i = 0,j = 0;
	int flag = 1;                 // 用于判断被合并表(记作B)中的元素是否与合并表(记作A)中重复，不重复为1，重复为0
	 
	if(pL2 == NULL || pL1 == NULL)
	{
		return -2;                // 两表中至少有一个表为空，合并无意义，返回错误值 
	}

	for(j = 0; j < pL2->length; j++)          // 让每个B表中的元素与A表里所有元素进行比较
	{
		for(i = 0; i < pL1->length; i++)
		{
			if(pL1->data[i] == pL2->data[j]) 
			{
				flag = 0;
				break;
			}
		}
		
		if(flag == 1)
		{
			pL1->data[pL1->length] = pL2->data[j];
			pL1->length++;

			if(pL1->length > pL1->listsize)
			{
				return -1;      // 超过listsize，溢出 
			}
		}

		flag = 1;               // 还原值，进行B表中下一个元素的比较
		i = 0;
	} 

	return 0;       // 操作成功 
}

// 合并有序表(因为静态数组版本不能扩充空间，所以需要先检验AB两表有效数据个数，不能超过INIT_SIZE，否则只能罢工)
int mergeOrderedList(SeqList *pL1, SeqList *pL2, SeqList *pLnew)
{
	int i = 0, j = 0, k = 0;
	
	if(pL2 == NULL || pL1 == NULL)
	{
		return -2;                // 两表中至少有一个表为空，合并无意义，返回错误值 
	}
	
	while(i < pL1->length && j < pL2->length)
	{
		if(pL2->data[j] < pL1->data[i])
		{
			pLnew->data[k] = pL2->data[j];
			k++;
			j++;
		}
		else if(pL2->data[j] > pL1->data[i])
		{
			pLnew->data[k] = pL1->data[i];
			k++;
			i++;
		}
		else if(pL2->data[j] = pL1->data[i])
		{
			pLnew->data[k] = pL2->data[j];
			k++;
			i++;
			j++;
		}
	}
	
	while(i < pL1->length)
        pLnew->data[k++] = pL1->data[i++];

    while(j < pL2->length)
        pLnew->data[k++] = pL2->data[j++];

    pLnew->length = k;

	return 0;
}


// 测试代码	
int main()
{
	SeqList list1, list2;
	SeqList list3, list4, listnew;
	int len;
	
	SeqList *pList1 = &list1;
	SeqList *pList2 = &list2;
	
	// 创建list1 
	list1 = InitList();
	listInsert(&list1, 0, 10);
	listInsert(&list1, 1, 20);
	listInsert(pList1, 2, 40);    // 第一个参数，这种写法也是完全可以的！
	listInsert(&list1, 2, 30);
	listInsert(&list1, 0, 5);             // 头插
	listInsert(&list1, list1.length, 50); // 尾插
	printf("创建的List1:\n");
	printAll(&list1);
	
	// 删除值为x的元素
	printf("\n");
	valueDelete(&list1, 30); 
	printf("删除值所在的位置后:\n");
	printAll(&list1);

	//删除第i个元素（i从0开始编号）
	printf("\n");
	listDelete(&list1, 5);
	printf("删除位置上的值后:\n");
	printAll(&list1);
	
	// 返回表长
	len = getLength(&list1);
	printf("\n此时List1表长为:%d\n", len);

	// 创建list2 
	list2 = InitList();
	listInsert(&list2, 0, 10);
	listInsert(&list2, 1, 60);
	listInsert(pList2, 2, 40);    // 第一个参数，这种写法也是完全可以的！
	listInsert(&list2, 2, 70);
	listInsert(&list2, 0, 5);             // 头插
	listInsert(&list2, list2.length, 50); // 尾插
	printf("\n");
	printf("创建的List2:\n");
	printAll(&list2);
	
	printf("\n");
	mergeUnorderedList(&list1, &list2); 
	printf("去重复然后合并到List1后:\n");
	printAll(&list1);

	len = getLength(&list1);
	printf("\n此时List1表长为:%d\n", len);

	// 有序表的检验
	list3 = InitList();
	listInsert(&list3, 0, 1);
	listInsert(&list3, 1, 2);
	listInsert(&list3, 2, 4);    
	listInsert(&list3, 3, 5);
	listInsert(&list3, 4, 6);             
	printf("\n创建的List3:\n");
	printAll(&list3);
	
	list4 = InitList();
    listInsert(&list4, 0, 1);
	listInsert(&list4, 1, 2);
	listInsert(&list4, 2, 3);    
	listInsert(&list4, 3, 5);
	listInsert(&list4, 4, 6);
	listInsert(&list4, 5, 8);
	listInsert(&list4, 6, 9);     
	printf("\n创建的List4:\n");
	printAll(&list4);
	
	listnew = InitList();
	mergeOrderedList(&list3, &list4, &listnew);
	printf("\n有序合并后:\n");
	printAll(&listnew);
	
	return 0;
}
