#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
} a[80];

void PX(Node *head, int value) {
    Node *zj = head;
    if (value) {
        zj = zj->next;
        for (int i = 1; zj->next != NULL; i++) {
            zj = zj->next;
            for (Node *j = head; j != zj; j = j->next) {
                if (j->data > j->next->data) {
                    if (j == head) {
                        head = j->next;
                    }
                    j->next = j->next->next;
                    j->next->next = j;
                }
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Node *head = &a[0], *tail = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        a[i].data = value;
        a[i].next = &a[i + 1];
        tail = &a[i];
    }
    tail->next = NULL;
    PX(head, 1);
    for (Node *i = head; i != NULL; i = i->next) {
        printf("%d ", i->data);
    }
    return 0;
}