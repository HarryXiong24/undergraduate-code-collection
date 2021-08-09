/*
    适用于标准C， 全局数组版本
	SeqList.c
	V1.0
	2019.9.9 wangx
	这个版本的顺序表，因为顺序表是全局变量，这种情况不符合工业编程规范，
	所以只作为编程学习参考（可以和静态数组版本比较学习），不能作为顺序表的标准写法！
*/
#include <stdio.h>
#include <stdlib.h>
#define INIT_SIZE 10000  // 实际工业编程中，这个数字会很大！！

typedef struct 
{
	int data[INIT_SIZE];  // 10000个元素，40000个字节。
	int length;           // 4个字节
	int listsize;         // 4个字节
}SeqList;

// list1是全局变量，存于全局静态区，函数调用结束后依然存在，但和工业编程的“高内聚，低耦合”精神违背，慎用
// VC会自动对全局静态区的数据自动清零
SeqList list1;

void InitList()
{
	list1.length = 0;  // 这种写法，如果有第二个顺序表，那是没办法搞的。
	list1.listsize = INIT_SIZE;
	return;
}

// 本例中，i表示下标位置，从0开始编号的。如果要从1开始编号，下面代码都需要微调
int listInsert(int i, int value)
{
	int j;
	// 3.参数校验
	if (i > list1.length || i < 0 )
		return -1;  // 参数有误，返回错误码 -1
	// 4.考虑极端情况
	if (list1.length >= list1.listsize)
		return -2;  // 表满，出现上溢，返回错误码 -2 （静态数组版本的线性表，没法进行表空间扩充，这一点和用指针来表示的动态数组版本的不一样）
	// 5.到现在才处理常规套路
	for(j= list1.length; j>i; j--)
		list1.data[j] = list1.data[j-1];

	list1.data[j] = value;
	list1.length++;  // 这句千万别忘了！
	return 0;
}

// 本函数虽然没有改变线性表实参，但是因为线性表实在是太大了，为节省栈空间，提高效率，建议用指针来操作原件，而不是操作栈区中的结构体变量复印件
int getValue(int i)
{
	// 3. 参数校验
	if (i<0 || i> list1.length-1 )
		return -1;
	// 4. 考虑极端情况，本函数没有极端情况，不写
	// 5. 常规套路，顺序存储结构可以直接提取第i个元素，很简单，就一句话
	return list1.data[i];
}

void printAll()
{
	int i;
	for(i=0; i<list1.length; i++)
		printf("%d  ", getValue(i));
	return;
}

// 删除值为x的元素



// 删除第i个元素（i从0开始编号）


// 返回表长


// 合并无序表(因为静态数组版本不能扩充空间，所以需要先检验AB两表有效数据个数，不能超过INIT_SIZE，否则只能罢工)

int main()
{
	InitList();
	listInsert(0, 10);
	listInsert(1, 20);
	listInsert(2, 40);
	listInsert(2, 30);
	listInsert(0, 5);             // 头插
	listInsert(list1.length, 50); // 尾插
	printAll();
	return 0;
}
