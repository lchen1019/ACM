#include<cstdio>
#include<cstring>
using namespace std;
#define N 1000005
typedef long long ll;

ll n, k;
int len;
char t[N], p[N << 1];
int ans[N << 1];
int a[N];
ll mod = 19930726;

void init() {
    p[0] = '~';
    p[1] = '#';
    int i;
    for (i = 1; t[i - 1] != '\0'; i++) {
        p[i << 1] = t[i - 1];
        p[i << 1 | 1] = '#';
    }
    len = i << 1;
    // printf("len = %d\n",len);
    // printf("%s\n",p);
}

// 求出每一个点开始的有多长
void Manacher() {
    int mid = 0, right = 0;
    for(int i = 1; i < len; i++) {
        if(i <= right) {
            int d = right - i + 1;
            ans[i] = d > ans[(mid << 1) - i] ? ans[(mid << 1) - i] : d;
        }
        while(p[i - ans[i]] == p[i + ans[i]]) {
            ++ans[i];
        }
        if (right <= i + ans[i] - 1) right = i + ans[i] - 1, mid = i;
        ++a[ans[i] - 1];
    }
}

ll  fast_pow(ll a, ll p) {
    ll res = 1, x = a;
    while(p) {
        if (p & 1) res = res * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return res;
}

int main() {
    // freopen("in.in","rw",stdin);
    scanf("%lld%lld",&n, &k);
    scanf("%s", t);
    init();
    Manacher();
    ll res = 1;
    ll cnt = 0;
    int i = (len >> 1) & 1 ? (len >> 1) : (len >> 1) - 1;
    ll sum = 0;
    for(; i >= 1; i-=2) {
        // printf("%d  %d\n",i, a[i]);
        sum += a[i];
        if(cnt + sum > k) {
            int d = k - cnt;
            res = res * fast_pow(i, d) % mod;
            cnt += d;
        } else {
            res = res * fast_pow(i, sum) % mod;
            cnt += sum;
        }
        if(cnt == k)    break;
    }
    if(k == cnt)    printf("%lld\n",res);
    else printf("-1\n");
    return 0;
}