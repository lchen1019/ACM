#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
#define N 105

int n, m;
vector<int> v1[N];
vector<int> v2[N];
stack<int> s;
int t;
bool vis[N];
int f[N];

void dfs1(int u) {
    ++t;
    vis[u] = true; 
    for (int to : v1[u]) {
        if (!vis[to]) {
            dfs1(to);
            t++;
        }
    }
    f[u] = t;
    s.push(u);
}

void dfs2(int u) {
    vis[u] = true; 
    for (int to : v2[u]) {
        if (!vis[to]) {
            dfs2(to);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    int from, to;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &from, &to);
        v1[from].push_back(to);
    }
    // 遍历标注结束时间
    for (int i = 1; i <= n; i++) {
        t++;
        if (!vis[i])
            dfs1(i);
    }
    for (int i = 1; i <= n; i++) {
        printf("%d  ", f[i]);
    }
    printf("\n");
    // 转置
    for (int i = 1; i <= n; i++) {
        for (int to : v1[i]) {
            v2[to].push_back(i);
        }
    }
    memset(vis, 0, sizeof(vis));
    int cnt = 0;
    while(!s.empty()) {
        int t = s.top();
        s.pop();
        if (!vis[t]) {
            dfs2(t);
            ++cnt;
        }
    }
    printf("total = %d\n", cnt);
}