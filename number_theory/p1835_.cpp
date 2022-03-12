// p1835.cpp是一次失败的尝试，区间筛的性能是明显可以优于晒出根号以内的素数再进行判断滴
#include <cstdio>
using namespace std;
#define N 1000005
typedef long long ll;

int L, R;
bool vis_low[N];
bool vis_high[N];
int prime[N];

void sieve() {
    vis_low[0] = vis_low[1] = true;
    int pos = 0;
    if(L == 0)  vis_high[0] = vis_high[1] = true;
    if(L == 1)  vis_high[0] = true; 
    for (ll i = 2; (ll) i * i <= (ll) R; i++) {
        // 删除倍数
        if (!vis_low[i]) {
            prime[pos++] = i;
            int left = L / i, right = R / i;
            for (ll j = left - 1; j <= right + 1; j++) {
                ll pos = j * i;
                if (pos >= L && pos <= R && pos != i) {
                    vis_high[pos - L] = true;
                }
            }
        }
        for (ll j = 0; j < pos && (ll)(prime[j] * i) * (prime[j] * i) <= (ll) R; j++) {
            vis_low[prime[j] * i] =true;
            if (i % prime[j] == 0)  break;
        }
    }
}

int main() {
    scanf("%d%d", &L, &R);
    sieve();
    int ans = 0;
    for (int i = 0;i <= R - L; i++) {
        if (!vis_high[i])    ans++;
    }
    printf("%d",ans);
}