#include <cstdio>
using namespace std;
#define max(a,b) (((a) > (b))? (a) : (b))

int n = 10;
int v[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 10};
int w[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int dp[20];

int dfs(int k) { 
    if (dp[k])  return dp[k];
    if (k == 0) return 0;
    for (int i = 1; i <= k; i++) {
        dp[k] = max(dp[k], dfs(k - i) + v[i - 1]);
    }
    return dp[k];
}

int main() {
    // 1. 无限背包的解决方案
    // for (int i = 0; i < n; i++) {
    //     for (int j = w[i]; j <= n; j++) {
    //         dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    //     }
    // }
    // printf("%d\n", dp[n]);

    // 2. 记忆化搜索的形式
    // dfs(n);
    // for (int i = 0; i <= n; i++) {
    //     printf("%d\n", dp[i]);
    // }

    //3. 通过拓扑分析依赖关系的形式
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = max(dp[i], dp[j] + v[i - j - 1]);
        }
    }
    for (int i = 0; i <= n; i++) {
        printf("%d\n", dp[i]);
    }

}