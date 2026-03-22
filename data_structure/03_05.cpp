#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next, *prev;
} a[2000];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        a[i].data = i + 1;
        a[i].next = (i == n - 1) ? nullptr : &a[i + 1];
        a[i].prev = (i == 0) ? nullptr : &a[i - 1];
    }
    Node *head = &a[0], *tail = &a[n - 1];
    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        Node* left = &a[l - 1];
        Node* right = &a[r - 1];
        if (left == head) head = right->next;
        if (right == tail) tail = left->prev;
        if (left->prev) left->prev->next = right->next;
        if (right->next) right->next->prev = left->prev;
    }
    for (Node *p = head; p; p = p->next) {
        printf("%d ", p->data);
    }
    return 0;
}
// 1 2 3 4 5
// 1 4 3 2 5

// 1 2 3 4 5 6 7
// 1 5 4 3 2 6 7