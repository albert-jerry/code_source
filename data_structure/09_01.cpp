#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct tree {
    int value, l;
    tree *wh[100];
} a[100000];
int s1;
void find(int y, int u, int v, int s) {
    s++;
    if (a[u].value == a[v].value) {
        s1 = s;
    }
    for (int i = 0; i < a[u].l; i++) {
        if (a[y].value != a[u].wh[i]->value) {
            find(a[u].value, a[u].wh[i]->value, v, s);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for  (int i = 1; i <= n; i++) {
        a[i].value = i;
    }
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].wh[a[x].l] = &a[y];
        a[y].wh[a[y].l] = &a[x];
        a[x].l++, a[y].l++;
    }
    int ret[100000] = {0}, r2 = 2147483647;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            find(-1, a[j].value, a[i].value, -1);
            ret[i] += s1;
        }
        r2 = min(r2, ret[i]);
    }
    cout << r2;
    return 0;
}