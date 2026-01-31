#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n, h, a[100000];
    scanf("%d%d", &n, &h);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int ret = 0, s[100000] = {0}, s2[100000], f = -1, r = -1;
    for (int i = 0; i < n; i++) {
        f++;
        for (int j = i; j < n; j++) {
            s[++r] = a[j];
            s2[r] = a[j];
            int k = j;
            while (k > f) {
                if (s[k] < s[k - 1]) {
                    s[k - 1] = s[k];
                }
                if (s2[k] > s2[k - 1]) {
                    s2[k - 1] = s[k];
                }
                k--;
            }
            if ((s2[f] - s[f] + 1) <= h) {
                ret = max(ret, (s2[f] - s[f] + 1));
            } else {
                break;
            }
        }
    }
    cout << ret;
    return 0;
}