#include <iostream>
using namespace std;

int digui(int n) {
    if (n == 0) return 1;
    return n * digui(n - 1);
}

int main() {
    int n, ret;
    scanf("%d", &n);
    ret = digui(n);
    printf("%d\n", ret);
    return 0;
}