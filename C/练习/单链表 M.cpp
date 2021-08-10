#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *creat()
{
	int n;
	struct Node *head,*p1,*p2;
	p1=(struct Node*)malloc(sizeof(struct Node));
	p2=(struct Node*)malloc(sizeof(struct Node));
	head=NULL;
	printf("请输入第1个数:");
	scanf("%d",&p1->data);
	while(p1->data!=0)
	{
		n=n+1;
		if(n==1)
		    head=p1;
		else
		    p2->next=p1; 
		p2=p1;
		p1=(struct Node*)malloc(sizeof(struct Node));
		printf("请输入第%d个数:",n);
		scanf("%d",&p1->data);
	}
	p2->next=NULL;
	return head;
}

void print(struct Node *head)
{
	struct Node *p;
	p=head;
	printf("您输入的数据为:");
	while(head!=0)
	{
		do
		{
			printf("%-4d",p->data);
			p=p->next;
		}while(p!=NULL);
	}
}



int main()
{
	struct Node *head;
	head=creat(); 
	print(head);
}
