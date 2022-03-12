#include <cstdio>
using namespace std;
#define N 55
typedef unsigned long long ull;

int n, a, b;
ull c[N][N];

void init() {
    c[0][0] = 1;
    for (int i = 1; i <= N - 5; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &a, &b);
    init();
    long long sum = 0;
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            sum += c[n + i - 1][n - 1] * c[n + j - 1][n - 1];
        }
    }
    printf("%llu",sum);
}