#include<stdio.h>
#include<malloc.h>

struct LL 
{
	int item;
	struct LL *next;
};

typedef struct LL node;

void main()
{
	int a,b;
	node *head;
	head=(node *)malloc(sizeof(node));
	head->item=6;
	head->next=NULL;
	while(1)
	{
	printf("Enter the position and item u want to insert --\n");
	scanf("%d %d",&a,&b);
	SLLinsert(&head,a,b);
	display(head);
	}
}

void SLLinsert(node **head,int pos,int item)
{
	int k=0;
	node *p,*q,*newnode;
	newnode=(node *)malloc(sizeof(node));
	if(!newnode)
	{
	printf("Memory Error !!!");
	exit(0);
	}
	newnode->item=item;	
	
	p=*head;
		
	if(pos==1)
	{
		newnode->next=p;
		*head=newnode;
	}
	else
	{
		while(p!=NULL && k<pos-1)
		{
		k++;
		q=p;
		p=p->next;
		}
		if(p==NULL)
		{
			q->next=newnode;
			newnode->next=NULL;
		}
		else
		{
			q->next=newnode;
			newnode->next=p;
		}
		
	}	
}


void display(node *head)
{
	node *p=head;
	while(p!=NULL)
	{
		printf(" %d ",p->item);
		p=p->next;
	}
printf("\n");
}
