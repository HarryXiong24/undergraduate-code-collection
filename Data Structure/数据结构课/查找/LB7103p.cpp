#include <stdio.h>
#include <malloc.h>
//已知带头结点的链表head，删除其中值为n的结点。第一行输入用于建立链表的数据（0表示建立结束，不包含在链表）
//第二行为原始链表输出，第三行为输入需要删除的n值，若n值存在于链表则删除，若不存在则显示错误。
typedef struct _node
{
	int data;
	struct _node *next;
} node;

node *create(); //建立带头结点的链表
void out(node *head); //输出链表
int erase(node *head, int value); //删除链表head中值为value的结点

int main(void)
{
	int result, value;
	node *head;
	printf("Input:");
	head = create();
	printf("Original:");
	out(head); //输出原始链表
	printf("Input Erase Value:");
	scanf("%d", &value); //输入需要删除的元素值
	printf("Output:\n");
	result = erase(head, value);
	if (result == 0)
	{
		printf("Erase error!\n");
	}
	else
	{
		out(head);
	}
	return 0;
}

node *create()
{
	int n, i;
	node *head, *p, *q;
	head = (node*)malloc(sizeof(node));
	head->next = NULL;
	q = head;
	i = 0;
	scanf("%d", &n);
	while (n != 0)
	{
		p = (node*)malloc(sizeof(node));
		p->data = n;
		if (i % 2)
		{
			p->next = head->next;
			head->next = p;
		}
		else
		{
			p->next = q->next;
			q->next = p;
			q = q->next;
		}
		i++;
		scanf("%d", &n);
	}
	return head;
}

void out(node *head)
{
	node *p = head->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

/******start******/
int erase(node *head, int value) //删除链表head中值为value的结点
{
	node *temp1, *temp2;
	int flag;
	
	if(head == NULL)
	{
		flag = 0;
	} 
	
	temp1 = head;
	
	while(temp1->next != NULL)
	{
		if(temp1->next->data == value)
		{
			temp2 = temp1->next;
			temp1->next = temp1->next->next;
			free(temp2);
			flag = 1;
			break;
		}
		temp1 = temp1->next;
	}

	if(flag == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
} 

/******end******/
