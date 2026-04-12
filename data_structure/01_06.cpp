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
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        while (i < s.size() - 1 && (s[i] == s[i + 1] - 32 || s[i] == s[i + 1] + 32)) {
            s.erase(i, 2);
            i = 0;
        }
    }
    cout << s << endl;
    return 0;
}