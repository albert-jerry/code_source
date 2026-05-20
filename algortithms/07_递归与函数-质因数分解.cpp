#include <iostream>
using namespace std;

void PF(int n, int p) {
    if (n == 1) return;
    if (n % p == 0) {
        printf("%d ", p);
        PF(n / p, p);
    } else {
        PF(n, p + 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    PF(n, 2);
    return 0;
}