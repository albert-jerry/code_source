#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

struct tree {
    tree *nt[26];
    char v;
    int z, l;
    bool end;
} root, a[500000];

int main() {
    int n;
    scanf("%d", &n);
    root.v = '\0', root.z = n, root.end = false;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int l = s.size();
        for (int i = 0; i < l; i++) {
            if (i == 0) {
                for (int j = 0; j < root.l; j++) {
                    
                }
            }
        }
    }
    return 0;
}