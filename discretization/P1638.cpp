#include<cstdio>
using namespace std;
#define N 1000005
#define M 2005

int n, m;
int a[N];
int f[M];

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)    scanf("%d",&a[i]);
    int tot = 0;
    int head = 1, tail = 0;
    int res = N, left, right;
    while(true) {
        // tail移动到tot = n
        while(tot < m && tail < n) {
            if(f[a[++tail]] == 0){
                tot++;
            }
            f[a[tail]]++;
        }
        if(tot < m) break;
        // head向左移动,到第一个为0
        while(--f[a[head++]]);
        --tot;
        if(res > tail - head + 2) {
            res = tail - head + 2;
            left = head - 1;
            right = tail;
        }
    }
    printf("%d %d\n",left, right);
}