#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        hash[x] = x%999999937;
    }
    int ret = 0;
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        if (hash.find(x) != hash.end()) {
            ret++;
        }
    }
    if (ret >= n/2) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}