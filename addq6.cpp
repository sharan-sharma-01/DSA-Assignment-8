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

Node* build(int inorder[], int postorder[], int& pIndex, int start, int end) {
    if (start > end) return NULL;

    Node* root = new Node(postorder[pIndex]);
    pIndex--;

    int mid = findIndex(inorder, start, end, root->val);

    root->right = build(inorder, postorder, pIndex, mid + 1, end);
    root->left = build(inorder, postorder, pIndex, start, mid - 1);

    return root;
}

void printPre(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    printPre(root->left);
    printPre(root->right);
}

int main() {
    int n;
    cin >> n;

    int inorder[2000], postorder[2000];
    for (int i = 0; i < n; i++) cin >> inorder[i];
    for (int i = 0; i < n; i++) cin >> postorder[i];

    int pIndex = n - 1;
    Node* root = build(inorder, postorder, pIndex, 0, n - 1);

    printPre(root);
    cout << "\n";

    return 0;
}
