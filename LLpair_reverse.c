#include<stdio.h>
#include<malloc.h>


struct LL
{
	int item;
	struct LL *next;
};

typedef struct LL node;


node * LLpair_reverse(node *head)
{
node *temp=NULL;

if(head==NULL || head->next==NULL)
return head;
else
{
	temp=head->next;
	head->next=LLpair_reverse(temp->next);
	temp->next=head;
	return(temp);
}	
}

void display(node *head)
{
	printf("\nList is \n");	
	
	while(head!=NULL)
	{
	printf(" %d ",head->item);	
		head=head->next;
	}
}




void main()
{
	int i=5;
	
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
	head=LLpair_reverse(head);
	printf("\nList After ::::\n");
	display(head);
}

