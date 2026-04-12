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
    int n;
    cin >> n;
    stack<int> a;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s == "push") {
            int x;
            cin >> x;
            a.push(x);
        } else if (s == "pop") {
            if (!a.empty()) {
                a.pop();
            }
        } else {
            cout << a.top() << endl;
        }
    }
    return 0;
}