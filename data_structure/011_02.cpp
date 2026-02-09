#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

struct {
    int fa, value;
    bool rz;
} a[1000000];

void hb(int x, int y) {
    x--, y--;
    a[x].fa = y;
    a[y].rz = true;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        a[i].value = i + 1, a[i].fa = i;
        a[i].rz = false;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        hb(x, y);
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].fa == i) {
            ret++;
        }
    }
    ret--;
    cout << ret;
    return 0;
}