#include <cstdio>
using namespace std;
#define N 100005
#define min(a,b) (((a) > (b))? (b) : (a))

int n, m;
int st[1005][N];
int lg[N];

void init() {
    for (int i = 2; i <= N; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    for (int i = 1; i <= 25; i++) {
        int right = n - (1 << i) + 1;
        for (int j = 1; j <= right; j++) {
            // printf("%d  %d\n",i,j);
            st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]); 
        }
    }
}

inline int query(int l, int r) {
    int k = lg[r - l];
    return min(st[k][l], st[k][r - (1 << k) + 1]);
}

int main() {
    scanf("%d%d",&n,&m);
    // m = 10 * m;
    for(int i = 1; i <= n; i++)  scanf("%d",&st[0][i]);
    init();
    int l, r;
    bool first = false;
    for(int i = 0; i < m; i++) {
        scanf("%d%d",&l,&r);
        if(first)   printf(" ");
        printf("%d",query(l,r));
        first = true;
    }
}