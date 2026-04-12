#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[100000], top = -1;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "push") {
            int x;
            cin >> x;
            a[++top] = x;
        } else if (s == "pop") {
            if (top > -1) {
                top--;
            }
        } else {
            int x;
            cin >> x;
            cout << a[top - x + 1] << endl;
        }
    }
    return 0;
}