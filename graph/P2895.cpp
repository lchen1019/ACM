#include <cstdio>
#include <queue>
using namespace std;
#define N 305
int m;
bool vis[N][N];
bool final[N][N];
vector<int> s[N][N];
int d[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
struct Tag {
    int x, y, time;
};

inline bool check(int x, int y, int time) {
    bool check = false;
    for (int j : s[x][y]) {
        if (j <= time) {
            check = true;
            break;
        }
    }
    return check;
}

int bfs() {
    queue<Tag> q;
    int ans = -1;
    q.push({1, 1, 0});
    vis[1][1] = true;
    while(!q.empty()) {
        // 根据time更新vis
        Tag t = q.front();
        int x = t.x, y = t.y, time = t.time;
        // printf("x = %d, y = %d, time = %d\n", x, y, time);
        q.pop();
        // 结束条件
        if (!final[x][y]) {
            ans = t.time;
            break;    
        }
        ++time;
        // 向前一步
        for (int i = 0; i < 4; i++) {
            int t_x = x + d[i][0];
            int t_y = y + d[i][1];
            if (!vis[t_x][t_y]) {
                // 检查是否有time及其之前的会砸下来
                bool c = false;
                for (int j = 0; j < 4; j++) {
                    if (check(t_x + d[j][0], t_y + d[j][1], time)) {
                        c = true;
                        break;
                    }
                }
                if (c || check(t_x, t_y, time))  continue;
                vis[t_x][t_y] = true;
                q.push({t_x, t_y, time});
            }
        }
    }
    return ans;
}

int main() {
    freopen("in.in", "rw", stdin);
    scanf("%d", &m);
    int x, y, t;
    for (int i = 0; i <= 302; i++) {
        vis[0][i] = true;
        vis[i][0] = true;
        final[0][i] = true;
        final[i][0] = true;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &x, &y, &t);
        ++x, ++y;
        s[x][y].push_back(t);
        final[x - 1][y] = final[x + 1][y] = final[x][y - 1] = final[x][y + 1] = final[x][y] = true;
    }
    printf("%d", bfs());
    return 0;
}