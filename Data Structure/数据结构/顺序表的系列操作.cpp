#include<stdio.h>
#include<stdlib.h>

//顺序表的系列操作

//创建一个顺序表
typedef double Datatype;           //自定义类型，也可以修改 
typedef struct{
	Datatype *list;                //顺序表声明  
	int len;                       //顺序表长度
	int MAX_SIZE;                  //顺序表最大空间 
}SeqList;

//顺序表初始化
void initList(SeqList *L)
{
	L->list = NULL;              //先令其为空指针 
	L->len = 0;                  //让其长度初始化为0  
	L->MAX_SIZE = 2000;          //给表一个上限 
}

//创建一个顺序表
void createList(SeqList *L)
{
	int i;
	
	printf("请输入顺序表的长度:");
	scanf("%d", &L->len);
	if(L->len > L->MAX_SIZE)
	{
		printf("溢出!\n");
		exit(1);
	}
	else
	{
		L->list = (Datatype *)malloc((L -> len) * sizeof(Datatype));  //开辟内存空间
		for(i = 0;i < L->len; i++)                                    //输入元素 
		{
			printf("请输入第%d个元素:",i+1);
			scanf("%lf" ,&L->list[i]);
		} 
	}
} 

//清空一个顺序表
void clearList(SeqList *L)
{
	L->len = 0;
	free(L->list);
	printf("清空成功!\n");
} 

//输出信息表的元素信息
void outputList(SeqList *L) 
{
	int i;
	for(i = 0;i < L->len; i++)                                    //输入元素 
	{
		printf("第%d个元素:",i+1);
		printf("%lf\n", L -> list[i]);
	} 
}

//查看顺序表长度
void getLength(SeqList *L) 
{
	printf("顺序表长度为:%d\n", L->len);
}

//判断顺序表是否为空
int isEmpty(SeqList *L) 
{
	return (L->len == 0);
}

//读取表中第i个元素
void getElement(SeqList *L, int i)
{
	if( i < 0 || i >= L->len)
	{
		printf("Error!");
		exit(1);
	}
	
	printf("第%d个元素为%lf\n", i, L -> list[i-1]);
} 

//在顺序表中查找关键字的数据
void searchList(SeqList *L, Datatype elem)
{
	int i;
	int flag = 0;
	
	for(i = 0;i < L->len; i++)                                    //输入元素 
	{
		if( L->list[i] == elem)
		{
			printf("为顺序表中第%d个元素\n", i+1);
			flag = 1;
		}
	} 
	if(flag == 0)
	{
		printf("没有找到!\n");
	}
} 

//在顺序表中第i个位置插入一个新数据
void insertList(SeqList *L, Datatype elem, int i)
{
	int k;
	if( L -> len == L->MAX_SIZE)        //检查空间是否已满 
	{
		printf("溢出,不能插入1\n");
		exit(1);
	}
	if(i<0)                               //调整不合理位置 
	{
		i = 0;	
	}
	else if( i > L->len - 1)           //调整不合理位置 
	{
		i = L->len;
	}
	
	for(k = L->len-1; k >= i-1; k--)    //k >= i-1在该位置插入， k >= i在该位置之后插入， k >= i-2在该位置之前插入 
	{
		L->list[k+1] = L->list[k];
	} 
	L->list[i-1] = elem;
	L->len++;
} 

//删除顺序表中第i个元素
void delList(SeqList *L, int i) 
{
	int k;
	if(L->len == 0)
	{
		printf("空表!\n");
		exit(1);
	}
	if(i < 0 || i > L->len)
	{
		printf("错误的删除位置!\n");
		exit(1);
	}
	
	for(k = i-1; k < L->len - 1; k++)                  //特别要注意位置 
	{
		L->list[k] = L->list[k+1];
	}
	L->len--;
}

//测试代码 
int main()
{
	SeqList L;
	
	initList(&L);
	createList(&L);
	outputList(&L);
	getLength(&L);
	//getElement(&L, 5);
	//searchList(&L, 4);
	insertList(&L, 20, 8);
	outputList(&L);
	getLength(&L);
	delList(&L, 8);
	outputList(&L);
	getLength(&L);
}



