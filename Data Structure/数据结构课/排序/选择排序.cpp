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

// Ñ¡ÔñÅÅĞò 
void sort(int a[], int n)
{
	int i, j, k, temp;
	
	for(i = 0; i < n; i++)
	{
		k = i;
		for(j = i+1; j < n; j++)
		{
			if(a[j] < a[k])
			{
				k = j;
			}
		}
		if(k != i)
		{
			temp = a[i];
			a[i] = a[k];
			a[k] = temp;
		}
	}	
}









 

