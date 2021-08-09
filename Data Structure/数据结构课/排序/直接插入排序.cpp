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

// Ö±½Ó²åÈëÅÅĞò 
void sort(int a[], int n)
{
	int i,j,temp;
	
	for(i = 1; i < n; i++)
	{
		temp = a[i];
		for(j = i-1; j>=0; j--)
		{
			if(a[j] > temp)
			{
				a[j+1] = a[j];
			}
			else
			{
				break;
			}
		}
		a[j+1] = temp;
	}
}









