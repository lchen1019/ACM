#include <cstdio>
using namespace std;
#define N 100005
typedef long long ll;

ll n;
ll a[N], m[N];


ll extgcd(ll a, ll b ,ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll ans = extgcd(b, a % b, x, y);
    ll temp_y = y;
    y = x - y * (a / b);
    x = temp_y;
    return ans;
}

// 慢速乘,否则容易溢出
ll mul(ll a, ll b, ll mod) {
    ll res = 0, x = a;
    while(b) {
        if (b & 1) {
            res = (res + x) % mod;
        }
        x = (x + x) % mod;
        b >>= 1;
    }
    return res;
}

// ll mul(ll a, ll b, ll mod) {
//     ll res = 0;
//     while (b > 0) {
//         if (b & 1)
//             res = (res + a) % mod;
//         a = (a + a) % mod;
//         b >>= 1;
//     }
//     return res;
// }

ll extctr() {
    ll pre_m = m[0], pre_a = a[0];
    ll x, y;
    ll pre_k;
    for (int i = 1; i < n; i++) {
        // printf("i = %d\n",i);
        // printf("%lld %lld %lld %lld\n",pre_a, pre_m, a[i], m[i]);
        // 求出一组解
        ll cur_m = m[i], cur_a = a[i];
        ll c = ((cur_a - pre_a) % cur_m + cur_m) % cur_m;
        ll gcd = extgcd(pre_m, cur_m, x, y), bg = cur_m / gcd;
        // printf("gcd = %lld  x = %lld  y = %lld c = %lld\n",gcd,x,y,c);
        if (c % gcd != 0)  return -1;  // 不整除，无解
        // printf("asd  %lld  %lld\n",x,c/gcd); 
        x = mul(x, c / gcd, bg);
        pre_a += x * pre_m;
        pre_m *= bg;
        // printf("%lld  %lld  %lld\n",x,bg,pre_m);
        pre_a = (pre_a % pre_m + pre_m) % pre_m;
    }
    return pre_a;
}

int main() {
    // freopen("in.in","rw",stdin);
    scanf("%lld",&n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld",&m[i], &a[i]);
    }
    printf("%lld",extctr());
    return 0;
}