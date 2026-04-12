#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = 1;
    }
    int r = n, c = 0;
    for (int i = 0; i < n && r > 0; i++) {
        if (a[i]) {
            c++;
            if (c == m) {
                printf("%d ", i + 1);
                r--;
                c = 0;
                a[i] = 0;
            }
        }
        if (i == n - 1) {
            i = -1;
        }
    }
    return 0;
}