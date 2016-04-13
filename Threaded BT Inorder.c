#include<stdio.h>
#include<stdlib.h>
 
/* A binary tree tNode has data, pointer to left child
   and a pointer to right child */
struct tNode
{
   int data;
   struct tNode* left;
   struct tNode* right;
};
 
/* Function to traverse binary tree without recursion and 
   without stack */
void MorrisTraversal(struct tNode *root)
{
  struct tNode *curr,*prev;
 
 if(root==NULL)
 return;
 
 curr=root;
 
 while(curr!=NULL)
 {
 	if(curr->left==NULL)
 	{
 		printf(" %d ",curr->data);
 		curr=curr->right;
 	}
 	else
 	{
 	prev=curr->left;
 	while(prev->right!=NULL && prev->right!=curr)
 	prev=prev->right;
 	
 	if(prev->right==NULL)
 	{
 	prev->right=curr;
 	curr=curr->left;
	}
	else
 	{
 		prev->right=NULL;
 	printf(" %d ",curr->data);
	 curr=curr->right;	
 	}
	 
	 	
 	}
 	
 }
 
}
 
/* UTILITY FUNCTIONS */
/* Helper function that allocates a new tNode with the
   given data and NULL left and right pointers. */
struct tNode* newtNode(int data)
{
  struct tNode* tNode = (struct tNode*)
                       malloc(sizeof(struct tNode));
  tNode->data = data;
  tNode->left = NULL;
  tNode->right = NULL;
 
  return(tNode);
}
 
/* Driver program to test above functions*/
int main()
{
 
  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct tNode *root = newtNode(1);
  root->left        = newtNode(2);
  root->right       = newtNode(3);
  root->left->left  = newtNode(4);
  root->left->right = newtNode(5); 
 
  MorrisTraversal(root);
 
  getchar();
  return 0;
}
