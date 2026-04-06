#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

struct bcj {
    int fa, value, rz[100000], l;
} a[1000000];   

void bing(int x, int y) {
    x--, y--;
    int fx = x, fy = y;
    
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        a[i].value = i + 1;
        a[i].fa = i, a[i].l = -1;
    }
    char s;
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%c %d %d", &s, &x, &y);
        if (s == 'Q') {
            cout << ((a[x].fa == a[y].fa) ? 1 : 0);
        } else {
            bing(x, y);
        }
    }
    return 0;
}