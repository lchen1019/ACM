#include <cstdio>
#include <queue>
using namespace std;
#define N 3005

int n, m;
int head[N];
struct Node {
    int next, to, cost;
} node[N];
int cnt;
int c[N], deg[N], u[N];
bool out[N];

void add_edge(int from, int to, int cost) {
    node[++cnt].to = to;
    node[cnt].cost = cost;
    node[cnt].next = head[from];
    head[from] = cnt;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &c[i], &u[i]);
    }
    int from, to, cost;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &from, &to, &cost);
        add_edge(from, to, cost);
        deg[to]++;
        out[from] = true;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] != 0) {
            // c[i] -= u[i];
        } else {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        for (int j = head[i]; j; j = node[j].next) {
            // 可向前传递，则更新一次
            if (c[i] > 0) {
                c[node[j].to] += node[j].cost * c[i];
            }
            if (--deg[node[j].to] == 0) {
                c[node[j].to] -= u[node[j].to];
                q.push(node[j].to);
            }
        }
    }

    bool all = true;
    for (int i = 1; i <= n; i++) {
        if (!out[i] && c[i] > 0) {
            all = false;
            printf("%d %d\n", i, c[i]);
        }
    }
    if (all)
        printf("NULL\n");
}