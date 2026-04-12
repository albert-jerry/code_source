#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int n, top = -1, l = 0;
    int a[100000], b[100000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; i++) {
        printf("push %d\n", i);
        a[++top] = i;
        while (top >= 0 && a[top] == b[l]) {
            printf("pop\n");
            top--;
            l++;
        }
    }
    return 0;
}