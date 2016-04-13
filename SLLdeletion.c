#include<stdio.h>
#include<malloc.h>

struct LL 
{
	int item;
	struct LL *next;
};

typedef struct LL node;

int main()
{
	int a,b,n=5;
	node *head;
	head=(node *)malloc(sizeof(node));
	head->item=6;
	head->next=NULL;
	while(n--)
	{
	printf("Enter the position and item u want to insert --\n");
	scanf("%d %d",&a,&b);
	SLLinsert(&head,a,b);
	display(head);
	}
	n=5;
	printf("\n\nNow delete...........\n");
	while(n--)
	{
	printf("Enter the position  u want to delete --\n");
	scanf("%d",&a);
	SLLdeletion(&head,a);
	display(head);
	}
	return 0;
}

void SLLinsert(node **head,int pos,int item)
{
	int k=0;
	node *p,*q,*newnode;
	newnode=(node*)malloc(sizeof(node));
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

void SLLdeletion(node **head,int pos)
{
	int k=0;
	node *p,*q,*newnode;
	
	p=*head;
		
	if(pos==1)
	{
		*head=(*head)->next;
		free(p);
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
		printf("\nNo such Position exists.....\n");	
		}
		else
		{
			q->next=p->next;
			free(p);
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
