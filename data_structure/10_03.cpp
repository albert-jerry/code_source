#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    string s[50000];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n - 1; i++) {
        string mi = s[i];
        int w = i;
        for (int j = i + 1; j < n; j++) {
            if (s[j] < mi) {
                mi = s[j];
                w = j;
            }
        }
        string s1 = mi;
        mi = s[i];
        s[i] = s1;
    }
    for (int i = 0; i < n; i++) {
        cout << s[i] << "\n";
    }
    return 0;
}