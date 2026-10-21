#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    bool lthread, rthread;
};

Node* create(int x) {
    Node* n = new Node;
    n->data = x;
    n->left = n->right = NULL;
    n->lthread = n->rthread = true;
    return n;
}

Node* leftmost(Node* p) {
    while (p != NULL && !p->lthread)
        p = p->left;
    return p;
}

void inorder(Node* root) {
    Node* p = leftmost(root);

    while (p != NULL) {
        cout << p->data << " ";

        if (p->rthread)
            p = p->right;
        else
            p = leftmost(p->right);
    }
}

int main() {
    Node* a = create(20);
    Node* b = create(10);
    Node* c = create(30);

    a->left = b;
    a->right = c;
    a->lthread = a->rthread = false;

    b->right = a;
    c->left = a;

    cout << "Inorder Traversal: ";
    inorder(a);

    return 0;
}
