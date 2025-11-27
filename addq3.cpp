#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node* buildTree(int arr[], int n, int index) {
    if (index >= n || arr[index] == -1) return NULL;
    Node* root = new Node(arr[index]);
    root->left = buildTree(arr, n, 2*index + 1);
    root->right = buildTree(arr, n, 2*index + 2);
    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + (lh > rh ? lh : rh);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int arr[2000];
        for (int i = 0; i < n; i++) cin >> arr[i];

        Node* root = buildTree(arr, n, 0);

        cout << maxDepth(root) << "\n";
    }

    return 0;
}
