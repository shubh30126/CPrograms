#include<stdio.h>
#include<malloc.h>

struct LL
{
	int item;
	struct LL *next;
};

typedef struct LL node;


node *LLEvenOddSplit(node *head)
{
node *temp,*temp1=NULL,*temp2=NULL,*headeven=NULL,*headodd=NULL;
int flag=0,flag1=0;

temp=head;

while(temp!=NULL)
{
	if(temp->item%2==0)
	{
		if(!flag)
		{
			temp1=headeven=temp;
			flag=1;
		}
		else
		temp1->next=temp;
		temp1=temp;
	}
	else
	{
		if(!flag1)
		{
			temp2=headodd=temp;
			flag1=1;
		}
		else
		temp2->next=temp;
		temp2=temp;
	}

temp=temp->next;
}	
temp1->next=headodd;
	temp2->next=NULL;
	
return headeven;		
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
	int a=10,K;

	node *head=(node*)malloc(sizeof(node));
	node *temp;
	temp=head;
	
	while(a--)
	{
		scanf("%d",&temp->item);
		if(a>0)
		{
		temp->next=(node*)malloc(sizeof(node));
		temp=temp->next;
		}
	}
	temp->next=NULL;
	
	display(head);
	head=LLEvenOddSplit(head);
	display(head);
}
