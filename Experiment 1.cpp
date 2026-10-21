#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node a, b, c;

    a.data = 1;
    b.data = 2;
    c.data = 3;

    a.left = &b;
    a.right = &c;
    b.left = b.right = NULL;
    c.left = c.right = NULL;

    cout << "Inorder: ";
    inorder(&a);

    cout << "\nPreorder: ";
    preorder(&a);

    cout << "\nPostorder: ";
    postorder(&a);

    return 0;
}

