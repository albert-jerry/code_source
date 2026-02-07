#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct tree {
    int value, l;
    tree *wh[100];
} a[100000];

int find(int u, int z, int s) {
    int f = 0;
    int s1 = s;
    for (int i = 0; i < a[z].l; i++) {
        if (a[z].wh[i]->value != u) {
            f++;
            s = max(s, find(a[z].value, a[z].wh[i]->value, s));
        }
    }
    s++;
    return s;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        a[i].value = i;
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].wh[a[x].l] = &a[y];
        a[y].wh[a[y].l] = &a[x];
        a[x].l++, a[y].l++;
    }
    int ret1 = -1;
    ret1 = find(1, 1, ret1);
    cout << ret1;
    return 0;
}