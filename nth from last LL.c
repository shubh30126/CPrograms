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
	int a=5,pos,count;

	node *head=(node*)malloc(sizeof(node));
	node *temp,*temp2;
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
	printf("\n\nList is\n");
	
	for(temp=head;temp!=NULL;temp=temp->next)
	printf(" %d ",temp->item);
	
	printf("\nNow search.......");
	while(1)
	{
		printf("Enter the position from end    ");
		scanf("%d",&pos);
	temp2=head;
	count=0;
	for(temp=head;temp!=NULL;temp=temp->next)
	{
	count++;
	if(count>pos)
	temp2=temp2->next;	
	}
	printf("\nNo. at pos %d is %d ",pos,temp2->item);
	}
}
