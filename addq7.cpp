#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

void bstToDLL(Node* root, Node*& head, Node*& tail) {
    if (!root) return;
    bstToDLL(root->left, head, tail);
    if (!head) {
        head = root;
        tail = root;
    } else {
        tail->right = root;
        root->left = tail;
        tail = root;
    }
    bstToDLL(root->right, head, tail);
}

Node* mergeDLL(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* head = NULL;
    Node* tail = NULL;

    while (a && b) {
        Node* pick;
        if (a->val < b->val) {
            pick = a;
            a = a->right;
        } else {
            pick = b;
            b = b->right;
        }

        if (!head) {
            head = pick;
            tail = pick;
            tail->left = NULL;
            tail->right = NULL;
        } else {
            tail->right = pick;
            pick->left = tail;
            tail = pick;
        }
    }

    Node* rem = (a ? a : b);
    while (rem) {
        tail->right = rem;
        rem->left = tail;
        tail = rem;
        rem = rem->right;
    }

    return head;
}

void printDLL(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->right;
    }
    cout << "null\n";
}

int main() {
    Node* T1 = new Node(20);
    T1->left = new Node(10);
    T1->right = new Node(30);
    T1->left->left = new Node(25);
    T1->right->right = new Node(100);

    Node* T2 = new Node(50);
    T2->left = new Node(5);
    T2->right = new Node(70);

    Node* h1 = NULL; 
    Node* t1 = NULL;
    bstToDLL(T1, h1, t1);

    Node* h2 = NULL; 
    Node* t2 = NULL;
    bstToDLL(T2, h2, t2);

    Node* merged = mergeDLL(h1, h2);

    printDLL(merged);

    return 0;
}
