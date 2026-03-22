#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next, *prev;
} a[100];

int main() {
    int n, m, c = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        a[i].data = i + 1;
        a[i].next = (i == n - 1) ? nullptr : &a[i + 1];
        a[i].prev = (i == 0) ? nullptr : &a[i - 1];
    }
    Node *head = &a[0], *tail = &a[n - 1];
    head->prev = tail;
    tail->next = head;
    while (head->next != head) {
        c++;
        if (c == m) {
            cout << head->data << " ";
            head->prev->next = head->next;
            head->next->prev = head->prev;
            c = 0;
        }
        head = head->next;
    }
    cout << head->data;
    return 0;
}