#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int a[], int target) {
    int left = 0;
    int right = sizeof(a) - 1;
    int mid = 0;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (a[mid] == target) {
            return mid;
        }
        if (a[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return mid;
}

int main() {
    int n, m, a[200000];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    for (int i = 0; i < m; i++) {
        int target;
        scanf("%d", &target);
        int index = binarySearch(a, target);
        printf("%d %d %d\n", a[target] == a[index] ? index : index + 1, a[target] == a[index] ? 1 : 0, a[target] == a[index] ? sizeof(a) - index : sizeof(a) - index + 1);
    }
    return 0;
}