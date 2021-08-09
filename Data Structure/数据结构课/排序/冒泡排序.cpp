//使用起泡排序算法（升序）完善此程序。


#include <stdio.h>
#define N 10
void input(int a[], int n);
void output(int a[], int n);
void sort(int a[], int n);

int main(void)
{
	int a[N];
	input(a, N);
	sort(a, N);
	output(a, N);
	return 0; 
}

void input(int a[], int n)
{
	int i;
	printf("input:\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
}

void output(int a[], int n)
{
	int i;
	printf("Output:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void sort(int a[], int n)
{
	int i, j, temp;
	for (i = 0; i < n; i++)
	/*注：该排序算法跑三趟，将3改为n即为完全排序算法*/
	{
		/******start******/
		for(j = 0; j < n-i; j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
		/******end******/ 
	}
}





















