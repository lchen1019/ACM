// 仅仅是为了加深对BFS、DFS的理解
#include <cstdio>
#include <vector>
using namespace std;
#define N 1005

int n, m;
vector<int> v[N];
int color[N];

void dfs(int s) {
    // 节点s的颜色变成灰色
    color[s] = 2;
    // 递归出口
    // to-do something here
    // 遍历相邻节点
    for (int &it : v[s]) {
        // 如果关联的节点是白色，则遍历一次
        if (color[it] == 1) {
            // ...
            dfs(it);
            // 回溯操作
        }
    }
    // 遍历结束，置成黑色
    color[s] = 3;
}

// 这种写法的缺点在于起始点和BFS一样，需要独自加标签
void dfs_(int s) {
    // 出口
    // to-do something
    // 枚举所有关联的节点
    for (int &it : v[s]) {
        if (color[it] == 1) {
            color[s] = 2;
            dfs_(it);
        }
    }
    color[s] = 3;
}

int main() {
    scanf("%d%d", &n, &m);
    int from, to;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &from, &to);
        v[from].push_back(to);
    }
    // 所有节点的颜色都置为白色
    for (int i = 1; i <= n; i++) {
        color[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        // 如果遇到白色节点
        if (color[i] == 1) {
            dfs(i);
        }
    }

}