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
    int a[n], ret[1000] = {0}, p[100000], where[100000] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        p[++tail] = a[i];
        where[a[i]] = i;
    }
    for (int i = 0; head != tail; i++) {
        where[p[head]]--;
        for (int j = head; j <= tail; j++) {
            ret[where[p[j]]]++;
        }
        if (where[p[head]] != 0) {
            p[++tail] = p[head];
            where[tail] = where[p[head]];
        }
        head++;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", ret[i]);
    }
    return 0;
}