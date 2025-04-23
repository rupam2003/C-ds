#include <stdio.h> 

#include <stdlib.h> 

 

struct node { 

 int data; 

 struct node *left; 

 struct node *right; 

}; 

struct node* createnode(int x){ 

 struct node *temp; 

 temp=(struct node*)malloc(sizeof(struct node)); 

 temp->data=x; 

 temp->left=NULL; 

 temp->right=NULL; 

 return temp; 

} 

struct node* insert(struct node * root, int x){ 

 if(root==NULL) 

 return createnode(x); 

 else if(x > root->data) 

 root->right=insert(root->right,x); 

 else 

 root->left=insert(root->left, x); 

 return root; 

} 

void preorder(struct node *root){
if (root!=NULL) 

 { 

 printf(" %d ", root->data); 

 preorder(root->left); 

 preorder(root->right); 

 } 

} 

void inorder(struct node *root){ 

 if (root!=NULL) 

 { 

 inorder(root->left); 

 printf(" %d ", root->data); 

 inorder(root->right); 

 } 

} 

void postorder(struct node *root){ 

 if (root!=NULL) 

 { 

 postorder(root->left); 

 postorder(root->right); 

printf(" %d ", root->data); 

 } 

} 

int main() { 

 struct node *root=NULL;

 int x,choice;
while(1) {

 printf("\nPress\n1 to insert\n2 for preorder traverse\n3 for inorder traverse\n4 for 

postorder traverse\n5 for exit");

 printf("\nEnter your choice:");

 scanf("%d",&choice);

 switch(choice)

 {

 case 1: 

 printf("\nenter value of node to insert:");

 scanf("%d",&x);

 root=insert(root,x);

 break;

 case 2:

 preorder(root);

break;

case 3:

 inorder(root);

break;

case 4:

 postorder(root);

break;

case 5:

 exit(0);

default: printf("Invalid choice");

 }

	
}
return 0;

}
