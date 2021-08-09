/*
赫夫曼编码：
给出n个有权值的结点，构造赫夫曼树，
输出所有这n个结点的权值与其赫曼编码长度(即该结点在所构造的赫曼树中的深度)的乘积的总和。　　

程序输入：
第一行是一个正整数n，表示一共有n个结点。
第二行为n个整数，分别表示这n个结点的权值。　　

程序输出：
输出所有这n个结点的权值与其赫曼编码长度的乘积的总和。　　
*/
#include <stdio.h>

void sort(int arr[], int low, int high);

int main(void)
{
	int i, j, n, sum = 0;
	int arr[101];
	printf("Input:");
	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	for (i = 0; i < n - 1; i++)
	{
		sort(arr, i, n);
		/*
		for (j = 0; j < n; j++)
		{
			printf("%d ", arr[j]);
		}
		printf("sum=%d\n", sum);
		*/
		arr[i + 1] = arr[i] + arr[i + 1];
		sum = sum + arr[i + 1];
	}
	printf("Output: %d\n", sum);
	return 0;
}

void sort(int arr[], int low, int high)
{
	int i, j, te;
	
	for (i = low; i < high; i++)
	{
		for (j = low; j < high + low - i - 1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				te = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = te;
			}
		}
	}
}
