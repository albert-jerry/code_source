#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct tree{
    int value;
    vector<int> c;
}a[100000];

string DFS(int from, int x, int y, string s) {
    if (x == y) {
        return s;
    }
    for (int i = 0; i < a[x].c.size(); i++) {
        int next = a[x].c[i];
        if (next == from) {
            continue;
        }
        DFS(a[i].value, a[next].value, y, s);
        if (s != "error") {
            s = to_string(a[next].value + 1) + " " + s;
            return s;
        }
    }
    return "error";
}

void road(int x, int y) {
    string s = "";
    s = DFS(-1, x, y, s);
    cout << s << endl;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        a[i].value = i;
        int b, c;
        scanf("%d%d", &b, &c);
        b--, c--;
        a[b].c.push_back(c);
        a[c].c.push_back(b);
    }
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    road(u, v);
    return 0;
}