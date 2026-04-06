#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n, top = -1, zh[200000] = {0}, a[200000] = {0}, c[200000] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        while (top >= 0 && a[i] < zh[top]) {
            if (ret < zh[top]*c[top]) {
                ret = zh[top]*c[top];
            }
            c[top] = 0;
            top--;
        }
        zh[++top] = a[i];
        for (int i = 0; i <= top; i++) {
            c[i]++;
        }
    }
    printf("%d\n", ret);
    return 0;
}