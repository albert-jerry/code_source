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
    int x, k, head = 0, tail = -1;
    scanf("%d%d", &x, &k);
    vector<int> a;
    a.push_back(x);
    tail++;
    for (int i = 0; i < k; i++) {
        a.push_back(2*a[head]);
        tail++;
        a.push_back(2*a[head] + 1);
        tail++;
        printf("%d\n", a[head]);
        head++;
    }
    return 0;
}