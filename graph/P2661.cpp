#include <cstdio>
using namespace std;
#define N 200005

int n;
int parent[N];
int depth[N];
int next[N];
struct Node {
    int to,next;
}node[N];
int head[N];
int cnt;

void add_edge(int from, int to) {
    node[++cnt].to = to;
    node[cnt].next = head[from];
    head[from] = cnt;
}

int find(int x) {
    if(x == parent[x])   return x;
    return x = parent[x];
}

void unint(int x, int y) {
    if (depth[x] > depth[y]) {
        parent[y] = x;
    } else if (depth[x] < depth[y]) {
        parent[x] = y;
    } else {
        parent[x] = y;
        depth[y]++;
    }
}

int ans, from;
bool first;
void dfs(int pos) {
    printf("%d\n",pos);
    if (first && pos == from) {
        printf("%d\n",ans);
        return;
    }
    first = true;
    for (int i = head[pos]; i; i = node[i].next) {
        ++ans;
        dfs(node[i].to);
        --ans;
    }
}

int main() {
    freopen("in.in","rw",stdin);
    scanf("%d",&n);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    int pos;
    for (int i = 1; i <= n; i++) {
        scanf("%d",&pos);
        int x = find(i);
        int y = find(pos);
        if (x == y) {
            add_edge(i,pos);
            from = i;
            printf("i = %d\n",from);
            break;
        }
        add_edge(i,pos);
        unint(x, y);
    }
    dfs(from);
    return 0;
}