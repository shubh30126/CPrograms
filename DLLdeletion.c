#include<stdio.h>
#include<malloc.h>

struct DLL
{
	struct DLL *prev;
	int item;
	struct DLL *next;	
};

typedef struct DLL node;

void main()
{
int a,b,i=5;

node *head;
head=(node *)malloc(sizeof(node));

if(!head)
{
	printf("Memory Error...");
}
head->prev=NULL;
head->item=5;
head->next=NULL;

while(i--)
{
printf("\nEnter the position nd item in Doubly Linked List....\n");
scanf("%d %d",&a,&b);

DLLinsert(&head,a,b);
Display(head);
}

printf("\n\nNow deleting.... \n");
i=5;
while(i--)
{
printf("\nEnter the position of item in Doubly Linked List....\n");
scanf("%d",&a);

DLLdeletion(&head,a);
Display(head);
}

}


DLLinsert(node **head, int pos, int item)
{
	int k=1;
	node *newnode,*temp;
	newnode=(node *)malloc(sizeof(node));
	temp=*head;
	
	if(!newnode)
		printf("Memory Error!!");
	else
	{
		newnode->item=item;
		if(pos==1)
		{
		newnode->prev=(*head)->prev;	
		newnode->next=*head;
		(*head)->prev=newnode;
		(*head)=newnode;	
		}
		else
		{
			while(temp->next!=NULL && k<pos-1)
			{
			k++;
			temp=temp->next;	
			}
			if(temp->next==NULL)
			{
			newnode->prev=temp;	
			newnode->next=temp->next;
			temp->next=newnode;		
			}
			else
			{
			newnode->prev=temp;	
			newnode->next=temp->next;
			temp->next->prev=newnode;
			temp->next=newnode;			
			}
		}
	}	
}

DLLdeletion(node **head,int pos)
{
int k=1;
node *temp,*temp2;
temp=*head;	

if(pos==1)
{
	*head=(*head)->next;
	if(*head!=NULL)
	(*head)->prev=NULL;
	free(temp);
}
else
{
while(temp->next!=NULL && k<=pos-1)	
{
	k++;
	temp=temp->next;
}
if(temp->next==NULL)
{
temp->prev->next=temp->next;
free(temp);	
}
else
{
temp2=temp->prev;
temp2->next=temp->next;
temp->next->prev=temp2;
free(temp);	
}
}

}

Display(node *head)
{
	node *temp=head;
while(temp!=NULL)
{
	printf(" %d ",temp->item);
	temp=temp->next;
}
printf("\n");
}
