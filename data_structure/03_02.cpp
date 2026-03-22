#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
} a[100000], b[100000], c[200000];

void Merge(Node* ha, Node* hb) {
    int l = 0;
    while (ha && hb) {
        if (ha->data < hb->data) {
            printf("%d ", ha->data);
            c[l++] = *ha;
            ha = ha->next;
        } else {
            printf("%d ", hb->data);
            c[l++] = *hb;
            hb = hb->next;
        }
    }
    while (ha) {
        printf("%d ", ha->data);
        c[l++] = *ha;
        ha = ha->next;
    }
    while (hb) {
        printf("%d ", hb->data);
        c[l++] = *hb;
        hb = hb->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].data);
        a[i].next = (i == n - 1) ? nullptr : &a[i + 1];
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i].data);
        b[i].next = (i == m - 1) ? nullptr : &b[i + 1];
    }
    Node *ha = &a[0], *hb = &b[0];
    Merge(ha, hb);
    return 0;
}