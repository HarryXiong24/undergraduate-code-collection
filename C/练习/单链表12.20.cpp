#include<stdio.h>
#include<stdlib.h>

typedef struct Node linkNode;

struct Node
{
	int data;
	struct Node *next;
};

linkNode *creat()
{
	linkNode *head;
	linkNode *p1=(linkNode *)malloc(sizeof(linkNode));
	linkNode *p2=(linkNode *)malloc(sizeof(linkNode));
	int n=0;
	head=NULL;
	printf("Input No.1 number:");
	scanf("%d",&p1->data);
	while(p1->data!=0)
	{
		n++;
		if(n==1)
			head=p1;
		else
			p2->next=p1;
		p2=p1;
		p1=(linkNode *)malloc(sizeof(linkNode));
		printf("Input No.%d number:",n+1);
        scanf("%d",&p1->data);
	}
	p2->next=NULL;
	return head;
}

void printNode(linkNode *head)
{
	linkNode *p=(linkNode *)malloc(sizeof(linkNode));
	p=head;
	if(head!=NULL)
	{
		do
		{
			printf("%-4d",p->data);
			p=p->next;
		}while(p!=NULL);
	}	
}

int insertNode(linkNode *head,int in,int i)
{
	if(head==NULL||i==1)
	{
		linkNode *newNode=(linkNode *)malloc(sizeof(linkNode));
	    newNode->data=in;
	    newNode->next=head;
	    head=newNode;
	}
	else
	{
		int k=1;
		linkNode *p;
		p=head;
		while(p!=NULL&&k<i-1)
		{
			p=p->next;
			k++;
		}
		if(p==NULL&&head!=NULL)
		{
			printf("找不到该位置！\n");
			return 0;
		}
		else
		{
			linkNode *newNode=(linkNode *)malloc(sizeof(linkNode));
			newNode->data=in;
			newNode->next=p->next;
			p->next=newNode;
		}
	}
}

int deleteNode(linkNode *head,int j)
{
	linkNode *p1,*p2;
	if(j<=1)
	{
		p1->next=head;
		p1=head;
	}
	else
	{
		int k=1;
		p2=head;
		while(p2!=NULL&&k<j-1)
		{
			p2=p2->next;
			k++;
		}
		if(p2==NULL&&head!=NULL)
		{
			printf("没找到该位置！\n");
			return 0;
		}
		else
		{
			p1=p2->next;
			p2->next=p1->next;
		}
	}
	free(p1);
	return 1;
}

int research(linkNode *head,int m)
{
	linkNode *p;
	p=head;
	while(p!=NULL)
	{
		if(p->data==m)
		{
			printf("找到了！\n");
			return 1;
		}
		p=p->next;
		if(p->next==NULL)
		{
			printf("没有找到！\n");
			return 0;
		}
	}
}

int main()
{
	linkNode *head;
	int i,in;
	int j;
	int m;
	
	head=creat();
	printNode(head);
	
	printf("\nInput a num and situation which you want to input:");
	scanf("%d %d",&in,&i);
	insertNode(head,in,i);
	printNode(head); 
	
	printf("\nInput a num's situation which you want to delete:");
	scanf("%d",&j);
	deleteNode(head,j);
	printNode(head); 
	
	printf("\n\nInput a num which you want to search:");
	scanf("%d",&m);
	research(head,m); 	
}

