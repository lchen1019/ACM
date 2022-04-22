#include <cstdio>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
#define N 10005
#define min(a,b) (((a) < (b)) ? (a) : (b))
typedef pair<int,int> P;

int n, m;
struct Node {
    int to, cost, next;
} node[N];
int head[N];
int cnt;
int d[N];
bool vis[N];
int pre[N];

void prim(int s) {
    memset(d, 0x3f, sizeof(d));
    d[0] = s;
    priority_queue<P, vector<P>, greater<P> > q;
    q.push(make_pair(0, s));
    while(!q.empty()) {
        P t = q.top();
        q.pop();
        int from = t.second;
        if (vis[from] || d[from] < t.first) continue;
        vis[from] = true;
        for (int i = head[from]; i; i = node[i].next) {
            int to = node[i].to;
            if (!vis[to]) {
                if (d[to] < node[i].cost) {
                    pre[to] = from;
                    d[to] = node[i].cost;
                    q.push(make_pair(d[to], to));
                }
            }
        }
    }

}

int main() {

}