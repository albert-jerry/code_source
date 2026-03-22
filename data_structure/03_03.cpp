#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
} a[100000];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].data);
        a[i].next = (i == n - 1) ? nullptr : &a[i + 1];
    }
    Node *head = &a[0], *a = head;
    for (int i = 0; i + 1 < n/2; i++, a = a->next) {}
    printf("%d ", a->data);
    return 0;
}