#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void Inorder(struct Node* node) {
    if (node == NULL) return;
    Inorder(node->left);
    cout << node->data << " ";
    Inorder(node->right);
}

void Preorder(struct Node* node) {
    if (node == NULL) return;
    cout << node->data << " ";
    Preorder(node->left);
    Preorder(node->right);
}

void Postorder(struct Node* node) {
    if (node == NULL) return;
    Postorder(node->left);
    Postorder(node->right);
    cout << node->data << " ";
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    cout << "Inorder: "<< endl;
    Inorder(root);
    cout << endl;

    cout << "Preorder: "<< endl;
    Preorder(root);
    cout << endl;
    
    cout << "Postorder: "<< endl;
    Postorder(root);
    cout << endl;

    return 0;
}
