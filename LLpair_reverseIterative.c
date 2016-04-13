#include<stdio.h>
#include<malloc.h>

struct LL
{
	int item;
	struct LL *next;
};

typedef struct LL node;


node * LLpair_reverseIterative(node *head)
{
node *curr=head,*prev=head,*nxt;

if(head==NULL || head->next==NULL)
return head;

head=nxt=head->next;

while(1)
{
	curr=nxt->next;
	nxt->next=prev;

	if(curr==NULL || curr->next==NULL)
	{
	prev->next=curr;
	break;
	}

	prev->next=curr->next;
	prev=curr;
	nxt=curr->next;
}
	return head;
}

void display(node *head)
{	
	while(head!=NULL)
	{
	printf(" %d ",head->item,head);	
		head=head->next;
	}
}



void main()
{
	int i=2;
	
	node *head=(node*)malloc(sizeof(node));
	node *temp=head;
	while(i--)
	{
		scanf("%d",&temp->item);
		if(i>0)
		{
		temp->next=(node*)malloc(sizeof(node));
		temp=temp->next;
		}
	}
	temp->next=NULL;
	printf("\nList Before ::::\n");
	display(head);
	head=LLpair_reverseIterative(head);
	printf("\nList After ::::\n");
	display(head);
}
