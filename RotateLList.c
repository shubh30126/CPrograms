// Program to rotate a linked list counter clock wise
#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 
// This function rotates a linked list counter-clockwise and updates the head.
// The function assumes that k is smaller than size of linked list. It doesn't
// modify the list if k is greater than or equal to size
void rotate (struct node **head, int k)
{
	struct node *temp=*head,*temp2,*prev;
     if (k == 0)
       return;

while(temp!=NULL)
{
	prev=temp;
temp=temp->next;	

	if(--k==0)
	{
	temp2=temp;
	prev->next=NULL;
	}
}
prev->next=*head;
*head=temp2;
}
 
/* UTILITY FUNCTIONS */
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
}
 
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    struct node* head = NULL;
 int i;
    // create a list 10->20->30->40->50->60
    for ( i = 60; i > 0; i -= 10)
        push(&head, i);
 
    printf("Given linked list \n");
    printList(head);
    rotate(&head, 4);
 
    printf("\nRotated Linked list \n");
    printList(head);
 
    return (0);
}
