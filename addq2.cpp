#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

void printTree(Node* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int build(int start, int end, Node* result[], int index) {
    if (start > end) {
        result[0] = NULL;
        return 1;
    }

    int count = 0;

    for (int root = start; root <= end; root++) {
        Node* leftList[50];
        Node* rightList[50];

        int leftCount = build(start, root - 1, leftList, 0);
        int rightCount = build(root + 1, end, rightList, 0);

        for (int i = 0; i < leftCount; i++) {
            for (int j = 0; j < rightCount; j++) {
                Node* node = new Node(root);
                node->left = leftList[i];
                node->right = rightList[j];
                result[count] = node;
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    Node* allTrees[200];
    int total = build(1, n, allTrees, 0);

    cout << total << "\n";

    for (int i = 0; i < total; i++) {
        printTree(allTrees[i]);
        cout << "\n";
    }

    return 0;
}
