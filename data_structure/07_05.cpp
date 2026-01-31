#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);
    int a[100000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int s[100000];
    s[0] = a[0];
    for (int i = 1; i < n ; i++) {
        s[i] = s[i - 1] + a[i];
    }
    int q[100000], f = 0, r = -1;
    return 0;
}