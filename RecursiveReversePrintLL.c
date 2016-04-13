#include<stdio.h>
#include<stdlib.h>
  
/* Link list node */
struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL;
  
  
/* Function to reverse the linked list */
void printReverse(struct node* p)
{
	
  if(p->next == NULL)
  {
  	head=p;
    return;
  }
 
  printReverse(p->next);
 	
 p->next->next=p;
 p->next=NULL;
}
  
/*UTILITY FUNCTIONS*/
/* Push a node to linked list. Note that this function
  changes the head */
void push(struct node** head_ref, char new_data)
{
    /* allocate node */
    struct node* new_node =
            (struct node*) malloc(sizeof(struct node));
  
    /* put in the data  */
    new_node->data  = new_data;
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);   
  
    /* move the head to pochar to the new node */
    (*head_ref)    = new_node;
} 
  
/* Drier program to test above function*/
int main()
{
 
     
  push(&head, 1);
  push(&head, 2);
  push(&head, 3);
  push(&head, 4);
   
  printReverse(head);
  while(head!=NULL)
  {
  printf(" %d",head->data);
  head=head->next;
  }
  getchar();
}
