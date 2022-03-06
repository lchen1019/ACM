#include<cstdio>
using namespace std;
#define N 2005
typedef long long ll;

int n, mod;
int c[N][N];
int prefix[N][N];

void init() {
    c[0][0] = 1;
    for (int i = 1; i <= N - 5; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
    }
    // 预处理前缀和
    for (int i = 0; i <= N - 5; i++) {
        for (int j = 0; j <= i; j++) {
            if (c[i][j] % mod == 0)   prefix[i][j] = 1;
        }
    }
    // 处理边界
    for (int i = 1; i <= N - 5; i++) {
        prefix[i][0] += prefix[i - 1][0];
    }
    for (int i = 1; i <= N - 5; i++) {
        for (int j = 1; j <= N - 5; j++) {
            prefix[i][j] += prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }
}

int main() {
    scanf("%d%d",&n,&mod);
    init();
    int x, y;
    while(n--) {
        scanf("%d%d",&x,&y);
        printf("%d\n",prefix[x][x < y ? x : y]);
    }
}