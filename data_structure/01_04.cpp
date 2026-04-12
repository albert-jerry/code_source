#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int n, top = -1;
    scanf("%d\n", &n);
    char c[n];
    for (int i = 0; i < n; i++) {
        char ch;
        scanf("%c", &ch);
        if (ch == '[' || ch == '(') {
            c[++top] = ch;
        } else if (ch == ']' && top >= 0 && c[top] == '[') {
            top--;
        } else if (ch == ')' && top >= 0 && c[top] == '(') {
            top--;
        } else {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}