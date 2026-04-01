#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    unordered_map<int, int[3]> hash;
    hash.clear();
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int sum = 0;
        for (int i = 0; i < s. size(); i++) {
            sum += (sum * 31 + (s[i] - 'a'))%999999937;
        }
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        hash[sum][0] = a;
        hash[sum][1] = b;
        hash[sum][2] = c;
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        int sum = 0;
        for (int i = 0; i < s. size(); i++) {
            sum += (sum * 31 + (s[i] - 'a'))%999999937;
        }
        if (hash.find(sum) == hash.end()) {
            printf("-1 -1 -1\n");
        } else {
            printf("%d %d %d\n", hash[sum][0], hash[sum][1], hash[sum][2]);
        }
    }
    return 0;
}