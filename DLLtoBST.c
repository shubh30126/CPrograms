#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
/* A Doubly Linked List node that will also be used as a tree node */
struct Node
{
    int data;
 
    // For tree, next pointer can be used as right subtree pointer
    struct Node* next;
 
    // For tree, prev pointer can be used as left subtree pointer
    struct Node* prev;
};

struct Node* getKthNode(struct Node* head,int k)
{
	while(--k>0)
		head=head->next;
	return head;
}
 
struct Node* sortedListToBST(struct Node *head, int n)
{
struct Node *root;
int mid;
if(n<=0)
return NULL;

mid=n/2+1;
root = getKthNode(head,mid);

root->prev=sortedListToBST(head,mid-1);
root->next=sortedListToBST(root->next,n-mid);

return root;	
}
 
/* UTILITY FUNCTIONS */
/* A utility function that returns count of nodes in a given Linked List */
int countNodes(struct Node *head)
{
    int count = 0;
    struct Node *temp = head;
    while(temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
 
/* Function to insert a node at the beginging of the Doubly Linked List */
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node =
            (struct Node*) malloc(sizeof(struct Node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* since we are adding at the begining,
      prev is always NULL */
    new_node->prev = NULL;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* change prev of head node to new node */
    if((*head_ref) !=  NULL)
      (*head_ref)->prev = new_node ;
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while(node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
/* A utility function to print preorder traversal of BST */
void preOrder(struct Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->prev);
    preOrder(node->next);
}
 
/* Drier program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;
 struct Node *root;
 int n;
    /* Let us create a sorted linked list to test the functions
     Created linked list will be 7->6->5->4->3->2->1 */
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2); 
    printf("\n Given Linked List ");
    printList(head);
 
    /* Convert List to BST */
 n=countNodes(head);   
    
    root = sortedListToBST(head,n);
    printf("\n PreOrder Traversal of constructed BST ");
    preOrder(root);
 
    return 0;
}
