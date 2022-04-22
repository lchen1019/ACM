#include <cstdio>
#include <algorithm>
using namespace std;
#define N 10005

int n, m;
int head[N], cnt;
struct Edge {
    int x, y, cost;
} edge[N];

bool cmp(Edge &e1, Edge &e2) {
    return e1.cost < e2.cost;
}

int parent[N], depth[N];

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(x);
}

void unint(int x, int y) {
    if (depth[x] < depth[y]) {
        parent[x] = y;
    } else if (depth[x] > depth[y]) {
        parent[y] = x;
    } else {
        parent[x] = y;
        ++depth[y];
    }
}

void kruskal (int s) {
    sort(edge, edge + m, cmp);
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int x = find(edge[i].x);
        int y = find(edge[i].y);
        if (x == y) continue;
        unint(x, y);
        ++cnt;
        ans += edge[i].cost; 
    }
}

int main() {
    for (int i = 1; i <= n; i++) {
        depth[i] = i;
    }
}