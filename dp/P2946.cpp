#include <cstdio>
#include <cstring>
using namespace std;
#define N 2005

const int mod = 100000000;
int n, f;
int r[N];
int dp[N][1005];

int main() {
    scanf("%d%d", &n, &f);
    for (int i = 1; i <= n; i++)    scanf("%d", &r[i]);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < f; j++) {
            dp[i][j] = dp[i - 1][j];
        }
        // dp[i][r[i] % f]++;
        for (int j = 0; j < f; j++) {
            int next = (j + r[i]) % f;
            dp[i][next] = (dp[i][next] + dp[i - 1][j]) % mod;
        }
    }
    printf("%d\n", dp[n][0] - 1);
}