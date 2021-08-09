//输入一组数（不超过20个数），完成折半查找，并计算查找该数所花费的比较次数
//第1、3、5、7行为提示信息，第2行输入总元素个数，第4行输入各元素的值，第6行输入需要查找的数据，第8行为输出（标点使用半角逗号）。
#include <stdio.h>
#define max 20

int binary(int x, int list[], int n)/*从list[]中查找x*/
{
	int low, high, mid, time;
	time = 0;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;/*折半*/
		if (x < list[mid])/*在前半部分查找*/
		{
			high = mid - 1;
			time = time + 1;
		}
		else if (x > list[mid])/*在后半部分查找*/
		{
			low = mid + 1;
			time = time + 1;
		}
		else
		{
			time = time + 1;
			printf("Output:\n");
			printf("找到了,在data[%d]上,比较了%d次\n", mid, time);
			return (0);
		}
	}
	return (time);
}

int main()
{
	int list[max], index, x, num, i;
	printf("Input Number:\n");
	scanf("%d", &num);
	printf("Input Values:\n");
	for (i = 0; i < num; i++)
	{
		//printf("data[%d]=", i);
		scanf("%d", &list[i]);
	}
	printf("Search Value:\n");
	/*输入待查找数据*/
	scanf("%d", &x);
	index = binary(x, list, num);
	if (index != 0)
	{ 
		printf("Output:\n");
		printf("没找到,比较了%d次\n", index);
	}
	return 0;
}
