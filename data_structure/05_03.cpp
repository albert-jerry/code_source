#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int n, a[1000000000];
    scanf("%d", &n);
    unordered_map<int, int> hash;
    hash.clear();
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        hash[a]++;
    }
    int x = 0, l = 0;
    for (auto &it : hash) {
        if (it.second > x) {
            x = it.second;
            l = 0;
        }
        if (it.second == x) {
            a[l++] = it.first;
        }
    }
    sort(a, a + l);
    for (int i = 0; i < l; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}