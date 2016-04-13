#include<stdio.h>
#include<malloc.h>

struct CLL
{
	int item;
	struct CLL *next;
};

typedef struct CLL node;

void main()
{
	int a,b,i=5;
	node *head;
	head=(node *)malloc(sizeof(node));
	head->next = head;
	head->item=5;
	while(i--)
	{
	printf("\nEnter the value and 1 for first 2 for last");
	scanf("%d %d",&a,&b);
	CLLinsert(&head,a,b);
	display(head);
	}	
	
}

void CLLinsert(node **head,int item,int pos)
{
	node *newnode=(node*)malloc(sizeof(node));
	node *current;
	current=*head;
	newnode->item=item;
	
	if(!newnode)
	{
	printf("\nMemory Error ");
	return;
	}
	if(pos==1)
	{
	while(current->next!=*head)
	current=current->next;
	current->next=newnode;
	newnode->next=*head;
	*head=newnode;
	}
	if(pos==2)
	{
	while(current->next!=*head)
	current=current->next;
	current->next=newnode;
	newnode->next=*head;
	}	
}

void display(node *head)
{
	node *current=head;
	do
	{
		printf(" %d ",current->item);
		current=current->next;
	}while(current!=head);
	
	printf("\n\n");
}
