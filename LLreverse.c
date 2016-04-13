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
	int i=6;
	
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
	display(head);
	head=LLreverse(head);
	display(head);	
return;
}


node* LLreverse(node *head)
{
node *temp=NULL,*nxtnode;

while(head)
{
nxtnode=head->next;	
head->next=temp;
temp=head;
head=nxtnode;
}
return temp;
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
