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
    hash.clear();
    string b, a;
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        if (i) {
            hash[i] = (hash[i - 1]*31 + (a[i] - 'a'))%999999937;
        }
    }
    int h = 0;
    for (int i = 0; i < b.size(); i++) {
            h += (h*31 + (b[i] - 'a'))%999999937;
    }
    int ret = 0;
    for (auto &p : hash) {
        ret++;
    }
    printf("%d", ret);
    return 0;
}