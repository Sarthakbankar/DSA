#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

void inorder(Node* r) {
    stack<Node*> s;
    while (r != NULL || !s.empty()) {
        while (r != NULL) {
            s.push(r);
            r = r->left;
        }
        r = s.top();
        s.pop();
        cout << r->data << " ";
        r = r->right;
    }
}

void preorder(Node* r) {
    if (r == NULL) return;
    stack<Node*> s;
    s.push(r);

    while (!s.empty()) {
        r = s.top();
        s.pop();
        cout << r->data << " ";

        if (r->right) s.push(r->right);
        if (r->left) s.push(r->left);
    }
}

int main() {
    Node a = {1, NULL, NULL};
    Node b = {2, NULL, NULL};
    Node c = {3, NULL, NULL};

    a.left = &b;
    a.right = &c;

    cout << "Inorder: ";
    inorder(&a);

    cout << "\nPreorder: ";
    preorder(&a);

    return 0;
}

