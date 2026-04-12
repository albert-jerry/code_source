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
    int n;
    scanf("%d", &n);
    int a[n];
    int ret[100000] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        for (int j = 0; j < i; j++) {
            if (a[j] >= a[i] - 5) {
                ret[i]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", ret[i]);
    }
    return 0;
}