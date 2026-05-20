#include <iostream>
using namespace std;

long long fib(long long n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    long long n;
    scanf("%lld", &n);
    printf("%lld\n", fib(n));
    return 0;
}