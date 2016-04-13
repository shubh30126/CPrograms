// Not a Quick Sort

#include<stdlib.h>
#include<stdio.h>


struct node{	
	int data;
	struct node* left;
	struct node* right;
};
void insert(struct node** root,int n){
	struct node* temp=(struct node*)malloc(100);
	temp->left=NULL;
	temp->data=n;
	temp->right=(*root);
	if((*root)!=NULL)(*root)->left=temp;
	(*root)=temp;
}
void quick_sort(struct node** root,struct node* end){
	struct node *pivot=(*root);
	struct node *temp=(*root);
	struct node *temp1;
	if((*root)==end)
		return;
	while(temp->right!=end){
		if(temp->right->data < pivot->data){
			temp1=(*root);
			(*root)=temp->right;
			temp1->left=(*root);
			temp->right=temp->right->right;
			(*root)->right=temp1;
			(*root)->left=NULL;
		}
		else{
			temp=temp->right;
		}
	}
	quick_sort(root,pivot);
	quick_sort(&(pivot->right),end);
} 
int main(){
	struct node *root=NULL;
	insert(&root,8);
	insert(&root,36);
	insert(&root,2);
	insert(&root,18);
	insert(&root,12);
	insert(&root,3);
	quick_sort(&root,NULL);
	for(;root!=NULL;root=root->right)
		printf(" %d  ",root->data);
	return 0;
}
