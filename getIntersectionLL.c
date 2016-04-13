#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
  int data;
  struct node* next;
};

int getLength(struct node *head)
{
	int count=0;
	
	while(head!=NULL)
	{
		count++;
		head=head->next;
	}
	return count;
}
 
int getIntesectionNode(struct node* head1, struct node* head2)
{
	int m,n,d;
	struct node *temp;	
	m=getLength(head1);
	n=getLength(head2);
	d=(m-n);
	
	if(d<0)
	{
		temp=head1;
		head1=head2;
		head2=temp;
	}
	
	d=abs(d);
	while(d--)
	head1=head1->next;
	
	while(head1->data!=head2->data)
	{
		head1=head1->next;
		head2=head2->next;
	}
	return head1->data;	
}
 
/* IGNORE THE BELOW LINES OF CODE. THESE LINES
   ARE JUST TO QUICKLY TEST THE ABOVE FUNCTION */
int main()
{
  /*
    Create two linked lists
 
    1st 3->6->9->15->30
    2nd 10->15->30
 
    15 is the intersection point
  */
 
  struct node* newNode;
    struct node* head2;
  struct node* head1 =
            (struct node*) malloc(sizeof(struct node));
  head1->data  = 10;
 
  head2 =
            (struct node*) malloc(sizeof(struct node));
  head2->data  = 3;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 6;
  head2->next = newNode;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 9;
  head2->next->next = newNode;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;
 
  newNode = (struct node*) malloc (sizeof(struct node));
  newNode->data = 30;
  head1->next->next= newNode;
 
  head1->next->next->next = NULL;
 
  printf("\n The node of intersection is %d \n",
          getIntesectionNode(head1, head2));
 
  getchar();
}
