#include<iostream>
using namespace std;

class Node {
    public:
        int data, height;
		Node *left, *right;

    Node(int value) {
        data = value;
        height = 1;
        left = right = NULL;
    }
};
int getheight(Node *root){
        if (!root) 
        return 0;
        return root -> height;//height of leaf node is 1
    }
//most important functions
    Node * rightRotation(Node * root){
        Node * child = root -> left;
        Node * childRight = child -> right;

        child -> right = root;
        root -> left = childRight;

        //Update the height
        root -> height=1 + max(getheight(root -> left),getheight(root -> right));
        child -> height=1 + max(getheight(child -> left) , getheight(child -> right));

        return child;
    }
    Node * leftRotation(Node * root){
        Node *child = root -> right;
        Node *childLeft = child -> left;

        child -> left = root;
        root -> right = childLeft;

        root -> height=1 + max(getheight(root -> left), getheight(root -> right));
        child -> height=1 + max(getheight(child -> left), getheight(child -> right));
        return child;
    }
    int getbalance(Node * root){
        return getheight(root -> left) - getheight(root -> right);
    }
void preorder(Node * root){
    if (!root)
        return;

    cout <<root ->data<<" ";
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(Node *root){
	if(!root)
		return;
	
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
Node* findMin(Node* root) {
while (root->left != NULL) {
    root = root->left;
}
return root;
}

Node *deleteNode(Node* root, int key){
	if(root==NULL)
		return NULL;
	
	if(key<root->data){
		root->left = deleteNode(root->left,key);
	}
	else if(key>root->data){
		root->right=deleteNode(root->right,key);
	}
	else{
		//No child
		if(root->left==NULL&root->right==NULL){
			delete root;
			return NULL;
		}
		//left child exist
		else if(root->right==NULL){
			Node *temp = root->left;
			delete root;
			return temp;
		}
		//right child exist
		else if(root->left==NULL){
			Node *temp = root->right;
			delete root;
			return temp;
		}
		// two child
		else{
			Node *temp = findMin(root->right);
			root->data = temp->data;
			root->right=deleteNode(root->right,temp->data);
		}
	}
	
	root->height=1+max(getheight(root->left),getheight(root->right));
	//check the balance
	int balance = getbalance(root);
	
	if(balance>1){
		//left rotation
		if(getbalance(root->left)>=0){
			return rightRotation(root);
		}
		// Left right rotation
		else
		{
			root->left = leftRotation(root->left);
			return rightRotation(root);
		}
	}
	else if(balance<-1){
		if(getbalance(root->right)<=0){
			return leftRotation(root);
		}
		else{
			root->right = rightRotation(root->right);
			return leftRotation(root);
		}
	}
	else
	return root;
}
Node * insert(Node * root, int key){
    if (!root) {
        return new Node(key);
    }
    else if (key < root -> data) {
        root -> left=insert(root -> left, key);
    }
    else if (key > root -> data) {
        root -> right = insert(root -> right, key);
    }
    else {
        return root;
    }

    root->height = 1 + max(getheight(root -> left), getheight(root -> right));
	
	//Balancing check
	int balance = getbalance(root);

    //left left case
    if (balance > 1 && key < root -> left -> data){
        return rightRotation(root);
    }
    //Right Right case
    else if (balance < -1 && root -> right -> data < key) {
        return leftRotation(root);
    }
    //left right case
    else if (balance > 1 && key > root -> left -> data) {
        root -> left=leftRotation(root -> left);
        return rightRotation(root);
    }
    //Right left case
    else if (balance < -1 && root -> right -> data > key) {
        root -> right=rightRotation(root -> right);
        return leftRotation(root);
    }
    //if tree is balance
    else {
        return root;
    } 	
}
int main()
{
    //Dublicate element not allowed
    Node * root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 50);
    root = insert(root, 100);
    root = insert(root, 95);
	
	cout<<"Before Deletion: "<<endl;
    cout << "preorder: " << endl;
    preorder(root);
    cout<<endl;
    
    cout << "inorder: "<<endl;
    inorder(root);
    
    
    deleteNode(root,10);
    cout<<endl;
    
    cout<<"After Deletion: "<<endl;
    cout << "preorder: " << endl;
    preorder(root);
    cout<<endl;
    
    cout << "inorder: "<<endl;
    inorder(root);
}
