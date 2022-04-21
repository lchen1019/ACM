#include <cstdio>
#include <cstring>
using namespace std;
#define N 105
#define min(a,b) (((a) < (b))? (a) : (b))

int n = 6;
int p[N] = {30, 35, 15, 5, 10, 20, 25};
int dp[N][N];

int dfs(int l, int r) {
    if (dp[l][r] != 0x3f3f3f3f)   return dp[l][r];
    if (l == r) return 0;
    for (int k = l; k < r; k++) {
        dp[l][r] = min(dp[l][r], dfs(l, k) + dfs(k + 1, r) + p[l - 1] * p[k] * p[r]);
    }
    return dp[l][r];
}

int main() {
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i <= n; i++)    dp[i][i] = 0;
    // 1. 记忆化搜索
    // printf("%d\n", dfs(1, n));
    // 2. 分析依赖关系
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            int l = j, r = i + j;
            printf("(%d, %d) ",l, r);
            for (int k = l; k < r; k++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + p[l - 1] * p[k] * p[r]);
            }
        }
        printf("\n");
    }
    printf("%d\n", dp[1][n]);
}