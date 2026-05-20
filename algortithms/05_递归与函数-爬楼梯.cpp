#include <iostream>
using namespace std;

int up(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    return up(n - 1)+up(n - 2);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", up(n));
    return 0;
}