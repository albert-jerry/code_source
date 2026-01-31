// 题目：给定长度为 n 的数列，从左到右求出每个长度为 m 的连续数列段中的最大值。
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int a[200000], ret = 0, f = 0, r = -1;
    r = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        r++;
        if (r - f + 1 > m) {
            f++;
        }
        int j = r;
        while (j >= f) {
            if (a[r] > a[j]) {
                a[j] = a[r];
            }
            j--;
        }
        if (r - f + 1 >= m) {
            cout << a[f] << " ";
        }

    }
    return 0;
}
