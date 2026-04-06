#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n, top = -1, zh[200000] = {0}, a[200000] = {0}, b[200000] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        while (top >= 0 && a[i] > zh[top]) {
            a[b[top]] = i + 1;
            top--;
        }
        zh[++top] = a[i];
        b[top] = i;
    }
    while (top >= 0) {
        a[b[top]] = 0;
        top--;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}