// 惊讶的发现原来我之前做过，可是没啥印象了，大一的时候原来我这么强
#include <cstdio>
#include <stack>
#include <queue>
using namespace std;
#define N 10005
#define M 100005
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define max(a,b) (((a) > (b)) ? (a) : (b))

int n, m;
int val[N], rval[N];
struct Node {
    int to, next;
} node[M], node2[M];
int head[N], head2[N];
int cnt, cnt2;
int dp[N];

void add_edge(int from, int to) {
    node[++cnt].to = to;
    node[cnt].next = head[from];
    head[from] = cnt;
}

int t;
stack<int> s;
bool ins[N];            // 是否在栈中
int dnf[N], low[N];    // 真实时间，可追溯到最小时间
int col[N];
int tot;
int deg[N];

void tarjan(int pos) {
    s.push(pos);
    ins[pos] = true;
    dnf[pos] = low[pos] = ++t;
    // 遍历所有节点
    for (int i = head[pos]; i; i = node[i].next) {
        int to = node[i].to;
        if (dnf[to] == 0) {
            // 该节点没有访问过
            tarjan(to);
            low[pos] = min(low[pos], low[to]);
        } else if (ins[to]) {
            // 在栈中
            low[pos] = min(low[pos], low[to]);
        }
    }
    if (low[pos] == dnf[pos]) {
        ++tot;
        int v = s.top();
        while(v != pos) {
            s.pop();
            col[v] = tot;
            v = s.top();
            ins[v] = false;
        }
        col[pos] = tot;
        ins[pos] = false;
        s.pop();
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &val[i]);
    }
    int from, to;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &from, &to);
        add_edge(from, to);
    }
    for (int i = 1; i <= n; i++) {
        if (dnf[i] == 0) {
            tarjan(i);
        }
    }
    // 更新节点权值
    for (int i = 1; i <= n; i++) {
        rval[col[i]] += val[i];
    }
    // printf("asdasd\n");
    // 更新边
    for (int i = 1; i <= n; i++) {
        int from = col[i];
        for (int j = head[i]; j; j = node[j].next) {
            int to = col[node[j].to];
            if (from != to) {
                node2[++cnt2].to = to;
                node2[cnt2].next = head2[from];
                head2[from] = cnt2;
                ++deg[to];
            }
        }
    }
    for (int i = 1; i <= tot; i++) {
        dp[i] = rval[i];
    }
    // 从入读为0的节点开始遍历
    queue<int> q;
    for (int i = 1; i <= tot; i++) {
        if (deg[i] == 0) {
            q.push(i);            
        }
    }
    while(!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = head2[t]; i; i = node2[i].next) {
            int to = node2[i].to;
            dp[to] = max(dp[to], dp[t] + rval[to]);
            --deg[to];
            if (deg[to] == 0) {
                q.push(to);
            }
        }
    }
    int ans = dp[1];
    for (int i = 2; i <= tot; i++) {
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
}