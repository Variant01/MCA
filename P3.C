//Doubly Linked List with function
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *prev;
	struct node *next;
};
struct node* create();
void display(struct node*);
void main()
{
	int n,i;
	struct node *p,*q,*r;
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
	r->prev=NULL;
	r->next=NULL;
	p=q=r;
	for(i=2;i<=n;i++)
	{
		r=(struct node*)malloc(sizeof(struct node));
		printf("Enter node data %d: ",i);
		scanf("%d",&r->data);
		r->prev=q;
		r->next=NULL;
		q->next=r;
		q=r;
	}
	return(p);
}
void display(struct node* p)
{
	int n,i;
	struct node *q,*r;
	clrscr();
	printf("Output of Linked List: Front to Back\n");
	q=p;
	while(q!=NULL)
	{
		printf("%d ",q->data);
		q=q->next;
	}
	printf("\nOutput of Linked List: Back to Front\n");
	q=p;
	while(q->next!=NULL)
	{
		q=q->next;
	}
	while(q!=NULL)
	{
		printf("%d ",q->data);
		q=q->prev;
	}
}
/*//Doubly Linked List without function
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *prev;
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
	r->prev=NULL;
	r->next=NULL;
	p=q=r;
	for(i=2;i<=n;i++)
	{
		r=(struct node*)malloc(sizeof(struct node));
		printf("Enter node data %d: ",i);
		scanf("%d",&r->data);
		r->prev=q;
		r->next=NULL;
		q->next=r;
		q=r;
	}
	clrscr();
	printf("Output of Linked List: Front to Back\n");
	q=p;
	while(q!=NULL)
	{
		printf("%d ",q->data);
		q=q->next;
	}
	printf("\nOutput of Linked List: Back to Front\n");
	q=p;
	while(q->next!=NULL)
	{
		q=q->next;
	}
	while(q!=NULL)
	{
		printf("%d ",q->data);
		q=q->prev;
	}
	getch();
}*/
