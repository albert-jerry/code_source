#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long a[200000];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long ret = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            long long z = min(a[i], a[j]);
            long long b[200000] = {0}, k = i + 1;
            b[0] = z;
            while (k < j) {
                b[k - i] = a[k];
                if (b[k - i] >= b[0]) {
                    k = -1;
                    break;
                }
                k++;
            }
            if (k != -1) {
                ret++;
            }
        }
    }
    cout << ret;
    return 0;
}