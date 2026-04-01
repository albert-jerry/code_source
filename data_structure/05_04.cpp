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
        int v;
        scanf("%d", &v);
        hash[v]++;
    }
    int ret = 0;
    for (auto &p : hash) {
        ret += p.second/2*2;
        p.second -= p.second/2*2;
    }
    for (auto &p : hash) {
        if (p.second) {
            ret++;
            break;
        }
    }
    printf("%d", ret);
    return 0;
}