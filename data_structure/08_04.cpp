#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct node {
    int value, l, h;
    node *wh[1000];
}a[1000000];

void LCA(int x, int y) {
    x--, y--;
    node *a1 = &a[x], *a2 = &a[y];
    while (a1->h != a2->h) {
        if (a1->h > a2->h) {
            for (int i = 0; i < a1->l; i++) {
                if (a1->wh[i]->h < a1->h) {
                    a1 = a1->wh[i];
                    break;
                }
            }
        } else {
            for (int i = 0; i < a2->l; i++) {
                if (a2->wh[i]->h < a2->h) {
                    a2 = a2->wh[i];
                    break;
                }
            }
        }
    }
    while (a1->value != a2->value) {
        for (int i = 0; i < a1->l; i++) {
            if (a1->wh[i]->h < a1->h) {
                a1 = a1->wh[i];
                break;
            }
        }
        for (int i = 0; i < a2->l; i++) {
            if (a2->wh[i]->h < a2->h) {
                a2 = a2->wh[i];
                break;
            }
        }
    }
    cout << a1->value << "\n";
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        a[i].value = i + 1;
    }
    a[0].h = 1;
    for (int i = 0; i < n - 1; i++ ) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--, y--;
        a[x].wh[a[x].l++] = &a[y], a[y].wh[a[y].l++] = &a[x];
        if (a[x].h != 0) {
            a[y].h = a[x].h + 1;
        } else {
            a[x].h = a[y].h + 1;
        }
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        LCA(x, y);
    }
    return 0;
}