#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct tree {
    int value, l;
    tree *wh[100];
} a[100000];

inline string find(int u, int z, int v, string s) {
    string s1 = "";
    int l = 0, k = z;
    while (k) {
        l++;
        k /= 10;
    }
    k = z;
    for (int i = 0; i < l; i++) {
        s1 += (k%10) + '0';
    }
    s += s1;
    s += ' ';
    if (z == v) {
        return s;
    }
    int f = 0;
    for (int i = 0; i < a[z].l; i++) {
        if (a[z].wh[i]->value != u) {
            f++;
            return find(a[z].value, a[z].wh[i]->value, v, s);
        }
    }
    if (f == 0) {
        return "-1";
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
    int u, v;
    scanf("%d%d", &u, &v);
    string s = "";
    cout << find(u, u, v, s);
    return 0;
}