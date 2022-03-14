#include<cstdio>
using namespace std;
#define N 40005

int n;
bool vis[N];
int mu[N];
int prime[N];
int ans;

void sieve() {
    mu[1] = 1;
    vis[0] = vis[1] = true;
    int pos = 0;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            mu[i] = -1;
            prime[pos++] = i;
        }
        for (int j = 0; j < pos && prime[j] * i <= n; j++) {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0){
                mu[i * prime[j]] = 0;
                break;
            } else {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
}
   
int main() {
    scanf("%d",&n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    sieve();
    --n;
    // 整除分块
    int ans = 0;
    int left = 1, right;
    while(left <= n) {
        int d = n / left;
        right = n / d >= n ? n : n / d;
        int temp = 0;
        for (int i = left; i <= right; i++) {
            temp += mu[i];
        }
        ans += temp * d * d;
        left = right + 1;
    }
    printf("%d\n",ans + 2);
}