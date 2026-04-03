#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int a[1000001];

void up(int k) {
    while (k/2 != 0 && a[k/2] > a[k]) {
        swap(a[k/2], a[k]);
        k /= 2;
    }
}

void donw(int k, int len) {
    int x = a[k], y = a[len];
    swap(a[k], a[len]);
    len--;
    while (2*k <= len) {
        int j = 2*k;
        if (j + 1 <= len && a[j + 1] < a[j]) {
            j++;
        } 
        if (a[k] <= a[j]) {
            break;
        }
        swap(a[k], a[j]);
        k = j;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        up(i);
    }
    for (int i = 1; i <= n; n--) {
        printf("%d ", a[i]);
        donw(i, n);
    }
    return 0;
}