#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define N 1005

int n, m;       // 定点数，边数
int d[N][N];    // 邻接矩阵
int pre[N][N];  // 前驱节点记录

void Floyd() {
    for(int k=1;k<=n;k++) {
        for(int i = 1;i <= n; i++) {
            for(int j=1;j<=n;j++) {
                if(d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    pre[i][j] = k;
                }
            }
        }
    }    
}
queue<int> path;
void real_path(int from, int to) {
    int mid = pre[from][to];
    // 直接到达，中间没有节点
    if(mid == 0) {
        path.push(to);
        return;
    }
    real_path(from,mid);
    real_path(mid,to);
}

void get_path(int from,int to) {
    printf("From %d to %d: ",from,to);
    path.push(from);
    real_path(from,to);
    while(!path.empty()) {
        int top = path.front();
        path.pop();
        printf("%d->",top);
    }
    printf("end\n");
}

int main() {
    scanf("%d%d",&n,&m);
    int x,y,cost;
    memset(d,0x3f,sizeof(d));
    for(int i=0;i<m;i++) {
        scanf("%d%d%d",&x,&y,&cost);
        d[x][y] = d[y][x] = cost;
    }
    for(int i=1;i<=n;i++)
        d[i][i] = 0;
    Floyd();
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            get_path(i,j);
        }
    }
}