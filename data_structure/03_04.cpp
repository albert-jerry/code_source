#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
} a[1000];

int main() {
    int n;
    scanf("%d", &n);
    Node *head = &a[0], *tail = head;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].data);
        a[i].next = (i == 0) ? nullptr : tail;
        tail = &a[i];
    }
    for (Node* p = tail; p != nullptr; p = p->next) {
        printf("%d\n", p->data);
    }
    return 0;
}