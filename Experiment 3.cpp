#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* insert(Node* r, int x) {
    if (r == NULL) {
        r = new Node{x, NULL, NULL};
        return r;
    }
    if (x < r->data)
        r->left = insert(r->left, x);
    else
        r->right = insert(r->right, x);
    return r;
}

void level(Node* r) {
    if (r == NULL) return;
    queue<Node*> q;
    q.push(r);

    while (!q.empty()) {
        Node* t = q.front();
        q.pop();
        cout << t->data << " ";
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
    }
    cout << endl;
}

int height(Node* r) {
    if (r == NULL) return 0;
    int l = height(r->left);
    int h = height(r->right);
    return 1 + max(l, h);
}

void leaf(Node* r) {
    if (r == NULL) return;
    if (r->left == NULL && r->right == NULL)
        cout << r->data << " ";
    leaf(r->left);
    leaf(r->right);
}

int main() {
    Node* root = NULL;
    int a[] = {50, 30, 70, 20, 40, 60, 80};

    for (int x : a)
        root = insert(root, x);

    cout << "Original BST: ";
    level(root);

    root = insert(root, 35);

    cout << "New BST: ";
    level(root);

    cout << "Height: " << height(root) << endl;

    cout << "Leaf nodes: ";
    leaf(root);

    return 0;
}
