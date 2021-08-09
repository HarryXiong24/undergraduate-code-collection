#include <stdio.h>
//输入一组数（不多于11个），组织一个哈希表，哈希函数是H（K）=Kmod7
//哈希表长度为11个单元，起始地址为0，要求用线性探测方法解决冲突。
int main()
{
	int i, j;
	int a[11] = {0};
	int num, value;
	
	printf("Input Number:\n");
	scanf("%d", &num);
	printf("Input Values:\n");
	for(i = 0; i < num; i++)
	{
		scanf("%d", &value);
		j = value % 7;
		while (a[j] != 0)
		{
		j = (j + 1) % 11;
		}
		a[j] = value;
	}
	printf("Output:\n");
	
	for(i = 0; i < 11; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
