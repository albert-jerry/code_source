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
    int n, head = 0, tail = -1;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "push") {
            int x;
            scanf("%d", &x);
            tail++;
            a[tail] = x;
        } else if (s == "pop") {
            if (head <= tail) {
                head++;
            }
        } else {
            int x;
            scanf("%d", &x);
            if (head <= tail) {
                printf("%d\n", a[head + x - 1]);
            }
        }
    }
    return 0;
}