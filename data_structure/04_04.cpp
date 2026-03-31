#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int data, qz;
    TreeNode *left, *right, *father;
}a[1000000], *root = &a[0];

void Order(TreeNode *node) {
    if (node == nullptr) return;
    if (node->left != nullptr) {
        Order(node->left);
    }
    if (node->right != nullptr) {
        Order(node->right);
    }
    node->qz += (node->left != nullptr ? node->left->qz : 0) + (node->right != nullptr ? node->right->qz : 0);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        a[i].data = i;
        int l, r;
        scanf("%d%d", &l, &r);
        l--, r--;
        a[i].left = (l >= 0) ? &a[l] : nullptr;
        a[i].right = (r >= 0) ? &a[r] : nullptr;
        if (a[i].left != nullptr) a[i].left->father = &a[i];
        if (a[i].right != nullptr) a[i].right->father = &a[i];
    }
    for (int i = 0; i < n; i++) {
        int qz;
        scanf("%d", &qz);
        a[i].qz = qz;
    }
    Order(root);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i].qz);
    }
    return 0;
}