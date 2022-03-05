#include <cstdio>
using namespace std;
#define N 1000005
#define M 22
#define min(a, b) (((a) < (b)) ? (a) : (b))

int n, m;
int st[M][N];
int lg[N];

void init() {
    for (int i = 1; i < M; i++) {
        int col = n - (1 << i) + 1;
        for (int j = 1; j <= col; j++) {
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }
}

inline int query(int left, int right) {
    int k = lg[right - left];
    return min(st[k][left],st[k][right-(1 << k) + 1]);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &st[0][i]);
    }
    init();
    for(int i=2;i<=n;i++){
        lg[i] = lg[i >> 1] + 1;
    }
    for(int i=1;i<=n-m+1;i++) {
        printf("%d\n",query(i,i+m-1));
    }
}