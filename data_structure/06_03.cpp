#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

struct Node {
    int num, v;
}a[10001], b[100001];

void up(int k) {
    while (k/2 != 0 && a[k/2].v > a[k].v) {
        swap(a[k/2], a[k]);
        k /= 2;
    }
}

void donw(int k, int len) {
    int x = a[k].v, y = a[len].v;
    swap(a[k], a[len]);
    len--;
    while (2*k <= len) {
        int j = 2*k;
        if (j + 1 <= len && a[j + 1].v < a[j].v) {
            j++;
        } 
        if (a[k].v <= a[j].v) {
            break;
        }
        swap(a[k], a[j]);
        k = j;
    }
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        a[i].v = 100, a[i].num = i;
        b[i].v = 100, b[i].num = i;
    }
    for (int i = 0; i < m; i++) {
        int fl;
        scanf("%d", &fl);
        if (fl == 1) {
            int num, m;
            scanf("%d%d", &num, &m);
            int wa, wb;
            for (int j = 1; j <= n; j++) {
                if (a[j].num == num) {
                    wa = j;
                }
                if (b[j].num == num) {
                    wb = j;
                }
            }
            a[wa].v += m, b[wb].v += m;
            if (m < 0) {
                up(wa);
                donw(wb, n);
            }
            if (m > 0) {
                donw(wa, n);
                up(wa);
            }
        } else {
            printf("%d %d\n", b[1].v, a[1].v);
        }
    }
    return 0;
}