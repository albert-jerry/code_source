#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int data, dept;
    TreeNode *left, *right, *father;
}a[1025], *root = &a[1];

void PreOrder(TreeNode *node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    if (node->left != nullptr) {
        node->left->dept = node->dept + 1;
        PreOrder(node->left);
    }
    if (node->right != nullptr) {
        node->right->dept = node->dept + 1;
        PreOrder(node->right);
    }
}

void InOrder(TreeNode *node) {
    if (node == nullptr) return;
    if (node->left != nullptr) {
        node->left->dept = node->dept + 1;
        InOrder(node->left);
    }
    cout << node->data << " ";
    if (node->right != nullptr) {
        node->right->dept = node->dept + 1;
        InOrder(node->right);
    }
}

void PostOrder(TreeNode *node) {
    if (node == nullptr) return;
    if (node->left != nullptr) {
        node->left->dept = node->dept + 1;
        PostOrder(node->left);
    }
    if (node->right != nullptr) {
        node->right->dept = node->dept + 1;
        PostOrder(node->right);
    }
    cout << node->data << " ";
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        a[i].data = i;
        a[i].left = (i*2 <= n) ? &a[i*2] : nullptr;
        a[i].right = (i*2 + 1 <= n) ? &a[i*2 + 1] : nullptr;
        a[i].father = (i != 1) ? &a[i/2] : nullptr;
    }
    PreOrder(root);
    cout << endl;
    InOrder(root);
    cout << endl;
    PostOrder(root);
    cout << endl;
    return 0;
}