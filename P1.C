//Singly Linked List using functions
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node* create();
void display(struct node*);
void main()
{
	int n,i;
	struct node *p;
	clrscr();
	p=create();
	display(p);
	getch();
}
struct node* create()
{
	int n,i;
	struct node *p,*q,*r;
	printf("Enter no of nodes: ");
	scanf("%d",&n);
	r=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data 1: ");
	scanf("%d",&r->data);
	r->next=NULL;
	p=q=r;
	for(i=2;i<=n;i++)
	{
		r=(struct node*)malloc(sizeof(struct node));
		printf("Enter node data %d: ",i);
		scanf("%d",&r->data);
		r->next=NULL;
		q->next=r;
		q=r;
	}
	return(p);
}
void display(struct node *p)
{
	struct node *q;
	printf("Output of Linked List\n");
	q=p;
	while(q!=NULL)
	{
		printf("%d -> ",q->data);
		q=q->next;
	}
	printf("NULL");
}
/*//Singly Linked List without functions
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
void main()
{
	int n,i;
	struct node *p,*q,*r;
	clrscr();
	printf("Enter no of nodes: ");
	scanf("%d",&n);
	r=(struct node*)malloc(sizeof(struct node));
	printf("Enter node data 1: ");
	scanf("%d",&r->data);
	r->next=NULL;
	p=q=r;
	for(i=2;i<=n;i++)
	{
		r=(struct node*)malloc(sizeof(struct node));
		printf("Enter node data %d: ",i);
		scanf("%d",&r->data);
		r->next=NULL;
		q->next=r;
		q=r;
	}
	clrscr();
	printf("Output of Linked List\n");
	q=p;
	while(q!=NULL)
	{
		printf("%d ",q->data);
		q=q->next;
	}
	getch();
}*/
