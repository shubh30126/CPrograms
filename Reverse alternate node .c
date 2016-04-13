#include<stdio.h>
#include<stdlib.h>
 
/* A linked list node */
struct node
{
    int data;
    struct node *next;
};
 
/* Function to reverse all even positioned node and append at the end
   odd is the head node of given linked list */
struct node * reverse(struct node* head)
{
	struct node *prev=NULL,*nxt;
	while(head!=NULL)
	{
		nxt=head->next;
		head->next=prev;
		prev=head;
		head=nxt;
	}
	return prev;
}

void rearrange(struct node *odd)
{
	struct node	*even,*curr=odd,*temp,*temp1;
	int i=0;
	even=temp1=curr->next;
	temp=curr;
	curr=curr->next->next;
	while(curr!=NULL)
	{
	if(i==0)
	{
	temp->next=curr;
	temp=curr;	
	}
	else
	{
		temp1->next=curr;
		temp1=curr;
	}
	i=1-i;
	curr=curr->next;
	}
	temp1->next=NULL;
	temp->next=NULL;
	
	even=reverse(even);
	
	temp->next=even;	
}
 
/* Function to add a node at the beginning of Linked List */
void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
/* Druver program to test above function */
int main()
{
    struct node *start = NULL;
 
    /* The constructed linked list is:
     1->2->3->4->5->6->7 */
    push(&start, 8);
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
 
    printf("\n Linked list before calling  rearrange() ");
    printList(start);
 
    rearrange(start);
 
    printf("\n Linked list after calling  rearrange() ");
    printList(start);
 
    return 0;
}
