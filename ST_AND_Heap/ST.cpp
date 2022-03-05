#include<cstdio>
#include<cmath>
using namespace std;
#define N 100005
#define M 22
#define max(a,b) (((a) > (b))? (a) : (b))

int n,q;
int st[M][N];
int lg[N];

// 初始化st表
void init() {
    for(int i=1;i<=M;i++) {
        int col = n + 1 - (1 << i);
        int step = 1 << (i - 1);
        for(int j=1;j<=col;j++) {
            st[i][j] = max(st[i-1][j],st[i-1][j+step]);
        }
    }
}

inline int query(int a, int b) {
    int k = lg[b - a];
    return max(st[k][a],st[k][b - (1 << k) + 1]);
}

int main() {
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&st[0][i]);
    init();
    for(int i=2;i<=N;i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    int left,right;
    while(q--) {
        scanf("%d%d",&left,&right);
        printf("%d\n",query(left,right));
    }
}