// CTR
#include<cstdio>
using namespace std;
typedef long long ll;
#define N 105

ll n;
ll a[N], m[N];

ll extgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y= 0;
        return a;
    }
    ll gcd = extgcd(b, a % b, x, y);
    ll temp_y = y;
    y = x - a / b * y;
    x = temp_y;
    return gcd;
}

ll mul(ll a, ll b, ll mod) {
    ll res = 0;
    while(b) {
        if (b & 1) {
            res = (res + a) % mod;
        }
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}

ll ctr() {
    ll pre_m = m[0], pre_a = a[0];
    pre_a = (pre_a % pre_m + pre_m) % pre_m;
    ll x, y;
    for (int i = 1; i < n; i++) {
        ll cur_m = m[i], cur_a = a[i];
        cur_a = (cur_a % cur_m + cur_m) % cur_m;
        extgcd(pre_m, cur_m, x, y);
        ll mod = pre_m * cur_m;
        pre_a = mul(mul(y, pre_a, mod),cur_m , mod) + mul(mul(x, pre_m, mod), cur_a, mod);
        pre_m *= cur_m;
        pre_a = (pre_a % pre_m + pre_m) % pre_m;
    }
    return pre_a;
}

int main() {
    scanf("%lld",&n);
    for (int i = 0; i < n; i++) scanf("%lld",&a[i]);
    for (int j = 0; j < n; j++) scanf("%lld",&m[j]);
    printf("%lld",ctr());
}