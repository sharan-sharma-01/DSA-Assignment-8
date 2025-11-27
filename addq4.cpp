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

void rightView(Node* root, int level, int used[], int& mx) {
    if (!root) return;
    if (!used[level]) {
        cout << root->val << " ";
        used[level] = 1;
        if (level > mx) mx = level;
    }
    rightView(root->right, level + 1, used, mx);
    rightView(root->left, level + 1, used, mx);
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

        int used[2000] = {0};
        int mx = -1;

        rightView(root, 0, used, mx);
        cout << "\n";
    }

    return 0;
}
