#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int x) { val = x; left = NULL; right = NULL; }
};

int sumOfLeftLeaves(Node* root) {
    if (!root) return 0;

    int sum = 0;

    if (root->left && !root->left->left && !root->left->right)
        sum += root->left->val;

    return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}

int main() {
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << sumOfLeftLeaves(root);

    return 0;
}
