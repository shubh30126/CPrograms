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
	int i=5;
	
	node *head=(node*)malloc(sizeof(node));
	node *head1=(node*)malloc(sizeof(node));
	node *temp=head;
printf("\nEnter List 1 \n");
	while(i--)
	{
		scanf("%d",&temp->item);
		if(i>0)
		{
		temp->next=(node*)malloc(sizeof(node));
		temp=temp->next;
		}
	}
printf("\nEnter List 2 \n");
	temp->next=NULL;
	temp=head1;
	i=5;
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
	temp=LLmerge(head,head1);
	display(temp);
}

node * LLmerge(node *a,node *b)
{
	node *temp;
if(a==NULL)
return b;
if(b==NULL)
return a;
if(a->item>=b->item)
{
	temp=b;
	temp->next=LLmerge(a,b->next);
}
else
{
	temp=a;
	temp->next=LLmerge(b,a->next);	
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

