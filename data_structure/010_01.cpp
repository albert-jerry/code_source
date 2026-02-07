#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct zdtr {
    zdtr *nt[26];
    bool end;
} root;

int main() {
    int n;
    scanf("%d", &n);
    string s[50000] = {""};
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        string s1;
        cin >> s1;
        int f = 0;
        for (int j = 0; j < n; j++) {
            if (s1 == s[j]) {
                f++;
                break;
            }
        }
        cout << f << "\n";
    }
    return 0;
}