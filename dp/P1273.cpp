// 一道树形的DP，对动态规划的理解又有的提升呢
#include <cstdio>
#include <cstring>
using namespace std;
#define N 3005
#define max(a,b) (((a) > (b)) ? (a) : (b))

int n, m;
struct Node {
    int to, next;
} node[N];
int head[N];
int cnt;
int dp[N][N];

void add_edge(int from, int to) {
    node[++cnt].to = to;
    node[cnt].next = head[from];
    head[from] = cnt;
}

void dfs(int pos) {
    // 如果遇到用户节点，就直接返回
    if (pos > n - m)    return;
    // 如果是广播站就更新广播站
    for (int i = head[pos]; i; i = node[i].next) {
        int to = node[i].to;
        dfs(to);
        int l  = 0;
        for (l = 0; dp[pos][l] != -1061109568; l++);
        for (int k = l - 1; k >= 0; k--) {
            for (int j = 1; dp[to][j] != -1061109568; j++) {
                dp[pos][k + j] = max(dp[pos][k] + dp[to][j], dp[pos][k + j]);
            }
        }
    }

    // for (int k = 1; dp[pos][k] != -1061109568; k++) {
    //     dp[pos][k] = dp[pos][k] + dp[pos][0];
    // }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = -1061109568;
        }
    }
    int k, c, a;
    for (int i = 1; i <= n - m; i++) {
        scanf("%d", &k);
        while(k--) {
            scanf("%d%d", &a, &c);
            add_edge(i, a);
            dp[a][0] = -c;
        }
    }
    for (int i = n - m + 1; i <= n; i++) {
        scanf("%d", &c);
        dp[i][1] = dp[i][0] + c;
    }
    dp[1][0] = 0;
    dfs(1);
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        if (dp[1][i] >= 0) {
            ans = max(ans, i);
        }
    }
    printf("%d", ans);
}