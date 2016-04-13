#include<stdio.h>
#include<malloc.h>

struct LL
{
	int item;
	struct LL *next;
};

typedef struct LL node;


int HasKNodes(node *head,int k)
{
	int i;
	for(i=1;head!=NULL && (i<k);i++,head=head->next);
	
	if(i==k && head!=NULL)
	return 1;
	
	return 0;
}

node* GetKthNode(node *head,int k)
{
	int i;
	node *temp,*prev;
		
	if(!head)
	return 0;	

	for(i=1,temp=head;temp && i<k;i++,prev=temp,temp=temp->next);	
	if(i==k && temp!=NULL)
	return temp;
	else
	return (prev);	

}

node *LLKBlockReverse(node *head,int k)
{
	int i;
	node *temp,*nxt,*curr=head,*newnode;
	
	if(k==0 || k==1)
	return head;
	
	if(HasKNodes(curr,k))
	newnode=GetKthNode(curr,k);
	else 
	newnode=head;
	
	while(HasKNodes(curr,k) && curr!=NULL)
	{
		if(!HasKNodes(curr,k+1))
		temp=NULL;
		else
		temp=GetKthNode(GetKthNode(curr,k),k+1);
		i=0;
		while(i<k)
		{
			nxt=curr->next;
			curr->next=temp;
			temp=curr;
			curr=nxt;
			i++;			
		}
	}
	if(!HasKNodes(curr,k))
	{
		temp=NULL;
	while(curr!=NULL)
		{
			nxt=curr->next;
			curr->next=temp;
			temp=curr;
			curr=nxt;
		}	
	}
	return newnode;
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
	printf("\nEnter the value of K .... ");
	scanf("%d",&K);
	temp->next=NULL;
	display(head);
	head=LLKBlockReverse(head,K);
	display(head);
}
