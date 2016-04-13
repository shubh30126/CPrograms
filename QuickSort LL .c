#include<stdio.h>

struct node
{
    int data;
    struct node *next;
};
 
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
    printf("\n");
}
 
// Returns the last node of the list
struct node *getTail(struct node *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}
 
// Partitions the list taking the last element as the pivot
struct node *partition(struct node *head, struct node *end,
                       struct node **newHead, struct node **newEnd)
{
    struct node *pivot = end;
    struct node *prev = NULL, *cur = head, *tail = pivot,*temp;

 
 	while(cur!=pivot)
 	{
 		if(cur->data<pivot->data)
 		{
 		if((*newHead)==NULL)
		 (*newHead)=cur;
		 
		 prev=cur;
		 cur=cur->next;	
 		}
 		else
 		{
 			if(prev!=NULL)
 			prev->next=cur->next;
 			temp=cur->next;
 			tail->next=cur;
 			tail=cur;
			 tail->next=NULL;
 			cur=temp;	
 		}
 	}
 
 if((*newHead)==NULL)
 (*newHead)=pivot;
 
 (*newEnd)=tail;
 
  
    return pivot;
}
 
 
//here the sorting happens exclusive of the end node
struct node *quickSort(struct node *head, struct node *end)
{
struct node *pivot,*newHead=NULL,*newEnd=NULL,*temp,*tail;

if(!head || head==end)
return head;

pivot=partition(head,end,&newHead,&newEnd);

if(pivot!=newHead)
{
temp=newHead;
while(temp->next!=pivot)
temp=temp->next;

temp->next=NULL;

newHead=quickSort(newHead,temp);

temp=getTail(newHead);
temp->next=	pivot;
	
}

pivot->next=quickSort(pivot->next,newEnd);

return newHead;

}
 
 
// Driver program to test above functions
int main()
{
    struct node *a = NULL;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);
 
    printf("Linked List before sorting \n");
    printList(a);
 
    a=quickSort(a,getTail(a));
 
    printf("Linked List after sorting \n");
    printList(a);
 
    return 0;
}
