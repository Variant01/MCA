#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* create(int);
struct node* insertBeginning(struct node*,int);
struct node* insertBetween(struct node*,int);
struct node* insertEnd(struct node*,int);
struct node* deleteBeginning(struct node*);
struct node* deleteBetween(struct node*);
struct node* deleteEnd(struct node*);
void display(struct node*);
void main()
{
    int n,choice;
    struct node *p;
    clrscr();
    printf("Operations on Linked List\n");
    printf("Enter no of nodes: ");
    scanf("%d",&n);
    p=create(n);
    do
    {
	clrscr();
	printf("1. Insert at Beginning");
	printf("\n2. Insert in Between");
	printf("\n3. Insert at End");
	printf("\n4. Delete from Beginning");
	printf("\n5. Delete from Between");
	printf("\n6. Delete from End");
	printf("\n7. Display");
	printf("\n8. Exit");
	printf("\nPress Enter after every operation");
	printf("\nEnter choice [1-8]: ");
	scanf("%d",&choice);
	switch(choice)
	{
	    case 1:
		    p=insertBeginning(p,n);
		    break;
	    case 2:
		    p=insertBetween(p,n);
		    break;
        case 3:
		    p=insertEnd(p,n);
		    break;
	    case 4:
		    p=deleteBeginning(p);
		    break;
	    case 5:
		    p=deleteBetween(p);
		    break;
        case 6:
		    p=deleteEnd(p);
		    break;
	    case 7:
		    display(p);
		    break;
	    case 8:
		    exit(0);
	    default:
		    printf("\nInvalid choice");
	}
	getch();
    }while(1);
}
struct node* create(int n)
{
    int i;
    struct node *p,*q,*r;
    p=NULL;
    for(i=1;i<=n;i++)
    {
	    r=(struct node*)malloc(sizeof(struct node));
	    printf("Enter node data %d: ",i);
	    scanf("%d",&r->data);
	    r->next=NULL;
	    if(p==NULL)
	    {
	        p=r;
	    }
	    else
	    {
	        q->next=r;
	    }
	    q=r;
    }
    return p;
}
struct node* insertBeginning(struct node *p,int n)
{
    struct node *r;
    r=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to insert at beginning: ");
    scanf("%d",&r->data);
    r->next=p;
    p=r;
    return p;
}
struct node* insertBetween(struct node *p,int n)
{
    int x;
    struct node *q,*r;
    printf("Enter data after which to insert: ");
    scanf("%d",&x);
    q=p;
    while(q!=NULL&&q->data!=x)
    {
	    q=q->next;
    }
    if(q==NULL)
    {
	    printf("\nData not found.");
	    return p;
    }
    r=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to insert: ");
    scanf("%d",&r->data);
    r->next=q->next;
    q->next=r;
    return p;
}
struct node* insertEnd(struct node *p,int n)
{
    struct node *q,*r;
    r=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to insert at end: ");
    scanf("%d",&r->data);
    r->next=NULL;
    if(p==NULL)
    {
        return r;
    }
    q=p;
    while(q->next!=NULL)
    {
	    q=q->next;
    }
    q->next=r;
    return p;
}
struct node* deleteBeginning(struct node *p)
{
    struct node *q;
    if(p==NULL)
    {
        printf("\nList is empty.");
        return p;
    }
    q=p;
    p=p->next;
    printf("\nDeleted data: %d",q->data);
    free(q);
    return p;
}
struct node* deleteBetween(struct node *p)
{
    int x;
    struct node *q,*r;
    if(p==NULL)
    {
    	printf("\nList is empty.");
	    return p;
    }
    printf("Enter data to delete: ");
    scanf("%d",&x);
    if(p->data==x)
    {
	    q=p;
	    p=p->next;
	    free(q);
	    return p;
    }
    q=p;
    while(q->next!=NULL&&q->next->data!=x)
    {
	    q=q->next;
    }
    if(q->next==NULL)
    {
	    printf("\nData not found.");
        return p;
    }
    r=q->next;
    q->next=r->next;
    printf("\nDeleted data: %d",r->data);
    free(r);
    return p;
}
struct node* deleteEnd(struct node *p)
{
    struct node *q,*r;
    if(p==NULL)
    {
	    printf("\nList is empty.");
	    return p;
    }
    if(p->next==NULL)
    {
	    printf("\nDeleted data: %d", p->data);
	    free(p);
	    return NULL;
    }
    q=p;
    while(q->next->next!=NULL)
    {
	    q=q->next;
    }
    r=q->next;
    printf("\nDeleted data: %d",r->data);
    q->next=NULL;
    free(r);
    return p;
}
void display(struct node *p)
{
    struct node *q;
    printf("\nOutput of Linked List\n");
    q=p;
    while(q!=NULL)
    {
	    printf("%d -> ",q->data);
	    q=q->next;
    }
    printf("NULL");
}