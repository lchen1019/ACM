// 用链式前向星双向边的时候，容易开小规模
#include <cstdio>
using namespace std;
#define N 16005
#define max(a,b) (((a) > (b)) ? (a) : (b))

int n;
int a[N];
struct Node {
    int to, next;
} node[N * 2];
int head[N];
int cnt;
int dp[N];
bool vis[N];

void add_edge(int from, int to) {
    node[++cnt].to = to;
    node[cnt].next = head[from];
    head[from] = cnt;
}

int dfs(int pos) {
    vis[pos] = true;
    for (int i = head[pos]; i; i = node[i].next) {
        if (!vis[node[i].to]) {
            int t = dfs(node[i].to);
            dp[pos] = max(dp[pos], dp[pos] + t);
        }
    }
    return dp[pos];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int from, to;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &from, &to);
        add_edge(from, to);
        add_edge(to, from);
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = a[i];
    }
    dfs(1);
    int ans = -0x7ffffff;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}