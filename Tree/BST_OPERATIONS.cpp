#include <iostream>
using namespace std;

class Node {
public:
int data;
Node *left, *right;

Node(int value) {
    data = value;
    left = NULL;
    right = NULL;
}

};

// 1. Insert a node
Node* insert(Node* root, int value) {


if (root == NULL) {
    return new Node(value);
}

if (value < root->data) {
    root->left = insert(root->left, value);
}
else {
    root->right = insert(root->right, value);
}

return root;


}

// 2. Inorder Traversal
void inorder(Node* root) {


if (root == NULL) {
    return;
}

inorder(root->left);

cout << root->data << " ";

inorder(root->right);


}

// 3. Search a node
bool search(Node* root, int value) {


if (root == NULL) {
    return false;
}

if (root->data == value) {
    return true;
}

if (value < root->data) {
    return search(root->left, value);
}

return search(root->right, value);


}

// Find the smallest node
Node* findMin(Node* root) {
while (root->left != NULL) {
    root = root->left;
}
return root;
}

// 4. Delete a node
Node* deleteNode(Node* root, int value) {

if (root == NULL) {
    return NULL;
}

if (value < root->data) {
    root->left = deleteNode(root->left, value);
}

else if (value > root->data) {
    root->right = deleteNode(root->right, value);
}

else {

    // No child
    if (root->left == NULL && root->right == NULL) {
        delete root;
        return NULL;
    }

    // Only right child
    if (root->left == NULL) {
        Node* temp = root->right;
        delete root;
        return temp;
    }

    // Only left child
    if (root->right == NULL) {
        Node* temp = root->left;
        delete root;
        return temp;
    }

    // Two children
    Node* temp = findMin(root->right);

    root->data = temp->data;

    root->right = deleteNode(root->right, temp->data);
}

return root;


}

int main() {


Node* root = NULL;

int arr[] = {6, 3, 17, 5, 11, 18, 2, 1, 20, 14};
int n = sizeof(arr) / sizeof(arr[0]);

for (int i = 0; i < n; i++) {
    root = insert(root, arr[i]);
}

cout << "Inorder: ";
inorder(root);

cout << "\nSearch 11: ";

if (search(root, 11)) {
    cout << "Found";
}
else {
    cout << "Not Found";
}

root = deleteNode(root, 17);

cout << "\nAfter deleting 17: ";
inorder(root);

return 0;


}
