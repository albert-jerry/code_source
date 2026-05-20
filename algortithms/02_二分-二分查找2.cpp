#include <iostream>
using namespace std;

int main() {
    int n, m, a[100000], num[100000];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        num[0] = a[0];
        num[i] = num[i - 1] + a[i];
    }
    for (int i = 0; i < m; i++) {
        int l, r, x, flag = 0;
        scanf("%d%d", &l, &x);
        r = l;
        while (l <= r) {
            int sum = num[r] - num[l - 1];
            if (sum < x && r < n) {
                l = r + 1;
                r = ((r + n) / 2) <= n ? ((r + n) / 2) : n;
            } else if (sum > x) {
                r = l - 1;
                l = (l + 1) / 2;
            } else {
                printf("%d\n", r);
                flag++;
                break;
            }
        }
        if (flag == 0) {
            printf("-1\n");
        }
    }
}