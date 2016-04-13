// Program to sort a linked list 0s, 1s or 2s
#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 
// Function to sort a linked list of 0s, 1s and 2s
struct node* sortList(struct node *head)
{
struct node *temp0=NULL,*temp1=NULL,*temp2=NULL,*curr=head;
struct node *head0,*head1,*head2;
while(curr!=NULL)
{
if(curr->data==0)
{
	if(temp0==NULL)
	head0=temp0=curr;
	else
	{
	temp0->next=curr;
	temp0=curr;
	}
}
if(curr->data==1)
{
	if(temp1==NULL)
	head1=temp1=curr;
	else
	{
	temp1->next=curr;
	temp1=curr;
	}
}
if(curr->data==2)
{
	if(temp2==NULL)
	head2=temp2=curr;
	else
	{
	temp2->next=curr;
	temp2=curr;
	}
}

curr=curr->next;	
}

temp0->next=head1;
temp1->next=head2;
temp2->next=NULL;


return head0; 
}
 
/* Function to push a node */
void push (struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
    printf("\n");
}
 
/* Drier program to test above function*/
int main(void)
{
    struct node *head = NULL;
    push(&head, 0);
    push(&head, 1);
    push(&head, 0);
    push(&head, 2);
    push(&head, 1);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    push(&head, 2);
 
    printf("Linked List Before Sorting\n");
    printList(head);
 
    head=sortList(head);
 
    printf("Linked List After Sorting\n");
    printList(head);
 
    return 0;
}
