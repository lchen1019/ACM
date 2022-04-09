#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1005

int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main() {
    int n = 10;
    printf("%d\n", upper_bound(a, a + n, 11));
    printf("%d\n", &a[0]);
    printf("%d\n", &a[9]);
}