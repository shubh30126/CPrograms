/* Program to split a circular linked list into two halves */
#include<stdio.h> 
#include<stdlib.h> 
 
/* structure for a node */
struct node
{
  int data;
  struct node *next;
}; 
 
/* Function to split a list (starting with head) into two lists.
   head1_ref and head2_ref are references to head nodes of 
    the two resultant linked lists */
void splitList(struct node *head, struct node **head1, 
                                            struct node **head2)
{

struct node *slowptr=head,*fastptr=head,*temp;

*head1=head;

do
{
temp=fastptr;
fastptr=fastptr->next;
if(fastptr==head)
break;
temp=fastptr;
fastptr=fastptr->next;
if(fastptr!=head)
slowptr=slowptr->next;
}while(fastptr!=head);


*head2=slowptr->next;
temp->next=*head2;

slowptr->next=*head1;
	
}
 
/* UTILITY FUNCTIONS */
/* Function to insert a node at the begining of a Circular 
   linked lsit */
void push(struct node **head_ref, int data)
{
  struct node *ptr1 = (struct node *)malloc(sizeof(struct node));
  struct node *temp = *head_ref; 
  ptr1->data = data;  
  ptr1->next = *head_ref; 
   
  /* If linked list is not NULL then set the next of 
    last node */
  if(*head_ref != NULL)
  {
    while(temp->next != *head_ref)
      temp = temp->next;        
    temp->next = ptr1; 
  }
  else
     ptr1->next = ptr1; /*For the first node */
 
  *head_ref = ptr1;     
} 
 
/* Function to print nodes in a given Circular linked list */
void printList(struct node *head)
{
  struct node *temp = head; 
  if(head != NULL)
  {
    printf("\n");
    do {
      printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != head);
  }
}
 
/* Driver program to test above functions */
int main()
{
  int list_size, i; 
   
  /* Initialize lists as empty */
  struct node *head = NULL;
  struct node *head1 = NULL;
  struct node *head2 = NULL;  
 
  /* Created linked list will be 12->56->2->11 */
  push(&head, 12); 
  push(&head, 56);   
  push(&head, 2);   
  push(&head, 11);   
  push(&head, 12);   
  push(&head, 13);   
  push(&head, 14);   
 
  printf("Original Circular Linked List");
  printList(head);      
  
  /* Split the list */
  splitList(head, &head1, &head2);
  
  printf("\nFirst Circular Linked List");
  printList(head1);  
 
  printf("\nSecond Circular Linked List");
  printList(head2);  
   
  getchar();
  return 0;
} 
