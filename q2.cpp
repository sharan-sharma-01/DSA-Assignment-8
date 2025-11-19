#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int x) { data = x; left = right = NULL; }
};

Node* insertNode(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->data) root->left = insertNode(root->left, x);
    else root->right = insertNode(root->right, x);
    return root;
}

Node* searchRec(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

Node* searchNonRec(Node* root, int key) {
    while (root) {
        if (key == root->data) return root;
        root = key < root->data ? root->left : root->right;
    }
    return NULL;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* findMax(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, Node* x) {
    if (x->right) return findMin(x->right);
    Node* succ = NULL;
    while (root) {
        if (x->data < root->data) {
            succ = root;
            root = root->left;
        } else if (x->data > root->data) {
            root = root->right;
        } else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* x) {
    if (x->left) return findMax(x->left);
    Node* pre = NULL;
    while (root) {
        if (x->data > root->data) {
            pre = root;
            root = root->right;
        } else if (x->data < root->data) {
            root = root->left;
        } else break;
    }
    return pre;
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 20);
    root = insertNode(root, 10);
    root = insertNode(root, 30);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 25);
    root = insertNode(root, 35);

    int key = 15;

    cout << "Search Recursive: ";
    cout << (searchRec(root, key) ? "Found" : "Not Found") << endl;

    cout << "Search Non-Recursive: ";
    cout << (searchNonRec(root, key) ? "Found" : "Not Found") << endl;

    cout << "Minimum: " << findMin(root)->data << endl;
    cout << "Maximum: " << findMax(root)->data << endl;

    Node* succ = inorderSuccessor(root, searchRec(root, key));
    Node* pred = inorderPredecessor(root, searchRec(root, key));

    cout << "Inorder Successor of " << key << ": ";
    if (succ) cout << succ->data; else cout << "None";
    cout << endl;

    cout << "Inorder Predecessor of " << key << ": ";
    if (pred) cout << pred->data; else cout << "None";
    cout << endl;

    return 0;
}
