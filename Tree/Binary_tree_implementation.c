#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *createNode()
{
	int x;
	struct node *newNode;
	newNode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data & Enter -1 for no node:\n");
	scanf("%d",&x);
	if(x==-1)
	{
		return NULL; 
	}
	newNode->data=x;
	printf("\nEnter the left child of %d\n",x);
	newNode->left=createNode();
	printf("\nEnter the Right child of %d",x);
	newNode->right=createNode();
	return newNode;
}

void inOrder(struct node *root)
{
	if(root==NULL)
	{
		return;
	}
	inOrder(root->left);
	printf("%d ",root->data);
	inOrder(root->right);
}
void preOrder(struct node *root)
{
	if(root==NULL)
	{
		return;
	}
	printf("%d ",root->data);
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(struct node *root)
{
	if(root==NULL)
	{
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ",root->data);
}
void main()
{
	struct node *root;
	root=createNode();
	printf("Preorder is:");
	preOrder(root);
	
	printf("Inorder is: ");
	inOrder(root);
	
	printf("PosfOrder is: ");
	postOrder(root);
}
