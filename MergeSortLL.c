#include<stdio.h>
#include<stdlib.h>
  
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 
/* function prototypes */
struct node* SortedMerge(struct node* a, struct node* b);
void Split(struct node* source,
          struct node** front, struct node** back);
 
/* sorts the linked list by changing next pointers (not data) */
void MergeSort(struct node** head)
{
	struct node *a,*b;
	
	if(*head==NULL || (*head)->next==NULL)
	return;
	
	Split(*head,&a,&b);
	
	MergeSort(&a);
	MergeSort(&b);
	
	*head= SortedMerge(a,b);
	
}
 
struct node* SortedMerge(struct node* a, struct node* b)
{
	if(a==NULL)
	return b;
	if(b==NULL)
	return a;
	
	if(a->data<=b->data)
	{
		a->next=SortedMerge(a->next,b);
		return a;
	}
	else
	{
		b->next=SortedMerge(a,b->next);
		return b;
	}
}
 

void Split(struct node* source,
          struct node** front, struct node** back)
{
	struct node *slowptr,*fastptr;
	if(source==NULL || source->next==NULL)
	{
	*front=source;
	*back=NULL;	
	return;
	}
	
	slowptr=source;
	fastptr=source->next;
	
	
	while(fastptr->next!=NULL)
	{
		fastptr=fastptr->next;
		if(fastptr->next!=NULL)
		{
			slowptr=slowptr->next;
			fastptr=fastptr->next;
		}
	}
	
	*front=source;
	*back=slowptr->next;
	slowptr->next=NULL;
	
}
 
/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
}
 
/* Function to insert a node at the beginging of the linked list */
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
  
/* Drier program to test above functions*/
int main()
{
  /* Start with the empty list */
  struct node* res = NULL;
  struct node* a = NULL;
  
  /* Let us create a unsorted linked lists to test the functions
   Created lists shall be a: 2->3->20->5->10->15 */
  push(&a, 15);
  push(&a, 10);
  push(&a, 5); 
  push(&a, 20);
  push(&a, 3);
  push(&a, 2); 
  
  /* Sort the above created Linked List */
  MergeSort(&a);
  
  printf("\n Sorted Linked List is: \n");
  printList(a);           
  
  getchar();
  return 0;
}
