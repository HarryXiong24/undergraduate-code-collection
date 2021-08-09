#include <stdio.h>
#define N 51
//试补充完成一个折半查找的程序，需要对输入序列是否有序（升序）进行判断，若输入序列无序，错误提示。
int main(void)
{
	int a[N];
	int i,n,num;
	int top,bottom,mid;
	int flag=1; //如果在表列中找到数字，则值为1，否则为0
	int loc=-1;//要查找的数在表列中的位置，如果loca=-1表示表列中没有这个数;如果有这个数,则它的值为所在的位置
	printf("请输入查找元素个数(1-50): ");
	scanf("%d",&n);
	while(n<1 || n>50)
	{
		printf("个数不正确,请重新输入!/n");
		printf("请输入查找元素个数(1-50): ");
		scanf("%d",&n);
	}
	printf("请输入表列元素: ");
	/******start******/
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for(i = 1; i < n; i++)
	{
		if(a[i+1] < a[i])
		{
			printf("输入序列无序!\n");
			return 0;
		}	
	}	
	/******end******/
	printf("请你输入要查找的数: ");
	scanf("%d",&num);
	flag=1; //假设输入的数在表列中
	top=n;
	bottom=1;
	mid= (top+bottom)/2;
	while(flag)
	{
		/******start******/
		mid = (top + bottom) / 2;
		if(top < bottom)
		{
			flag = 0;
			printf("没有找到!\n");
			break;
		}
		
		if(num < a[mid] )
		{
			top = mid - 1;
		}
		else if(num > a[mid])
		{
			bottom = mid + 1;
		}
		else
		{
			flag = 0;
			loc = a[mid];
			printf("找到了!   %d", loc);
			break;
		}
		/******end******/
	}
	return 0;
}
