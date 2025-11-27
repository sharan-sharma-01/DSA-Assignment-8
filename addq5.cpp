#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++)
        if (inorder[i] == value) return i;
    return -1;
}

Node* build(int preorder[], int inorder[], int& pIndex, int start, int end) {
    if (start > end) return NULL;

    Node* root = new Node(preorder[pIndex]);
    pIndex++;

    int mid = findIndex(inorder, start, end, root->val);

    root->left = build(preorder, inorder, pIndex, start, mid - 1);
    root->right = build(preorder, inorder, pIndex, mid + 1, end);

    return root;
}

void printPost(Node* root) {
    if (!root) return;
    printPost(root->left);
    printPost(root->right);
    cout << root->val << " ";
}

int main() {
    int n;
    cin >> n;

    int preorder[2000], inorder[2000];
    for (int i = 0; i < n; i++) cin >> preorder[i];
    for (int i = 0; i < n; i++) cin >> inorder[i];

    int pIndex = 0;
    Node* root = build(preorder, inorder, pIndex, 0, n - 1);

    printPost(root);
    cout << "\n";

    return 0;
}
