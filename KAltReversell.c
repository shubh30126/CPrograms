#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 
/* Reverses alternate k nodes and
   returns the pointer to the new head node */
struct node *kAltReverse(struct node *head, int k)
{
 struct node *prev=NULL,*nxt,*curr=head,*ret;
 int count=0;
 
 if(head==NULL)
 return NULL;
 
while(count++<k && curr)
{
nxt=curr->next;
curr->next=prev;
prev=curr;
curr=nxt;
}

ret=prev;

if(curr!=NULL)
head->next=curr;
count=0;
while(count++<k && curr)
	{
		prev=curr;
	curr=curr->next;
	}
if(curr!=NULL)
prev->next=kAltReverse(curr,k);

return ret;	
 
}
 
/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(struct node** head_ref, int new_data)
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
    int count = 0;
    while(node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
        count++;
    }
}    
 
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    struct node* head = NULL;
 int i;
    // create a list 1->2->3->4->5...... ->20
    for( i = 20; i > 0; i--)
      push(&head, i);
 
     printf("\n Given linked list \n");
     printList(head);
     head = kAltReverse(head, 3);
 
     printf("\n Modified Linked list \n");
     printList(head);
 
     getchar();
     return(0);
}
