#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int data, depth;
    TreeNode *left, *right, *father;
}a[1000], *root = &a[0];

void PreOrder(TreeNode *node) {
    if (node == nullptr) return;
    if (node->left != nullptr) {
        node->left->depth = node->depth + 1;
        PreOrder(node->left);
    }
    if (node->right != nullptr) {
        node->right->depth = node->depth + 1;
        PreOrder(node->right);
    }
}

int main() {
    int n, u, v;
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
    scanf("%d%d", &u, &v);
    u--, v--;
    TreeNode *p = &a[u], *q = &a[v];
    PreOrder(root);
    while (p->depth > q->depth) p = p->father;
    while (q->depth > p->depth) q = q->father;
    while (p != q) {
        p = p->father;
        q = q->father;
    }
    printf("%d\n", p->data + 1);
    return 0;
}