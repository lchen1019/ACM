#include<cstdio>
using namespace std;
typedef long long ll;

ll tot;
ll l, r;

ll mul(ll a, ll b, ll mod) {
    ll res = 0;
    while(b) {
        if (b & 1) {
            res = (res + a) % mod;
        }
        a = a * 2 % mod;
        // printf("a = %lld\n",a);
        b >>= 1;
    }
    return res;
}

int main() {
    scanf("%lld",&tot);
    while (tot--) {
        scanf("%lld%lld",&l,&r);
        if(l == r) {
            printf("%lld\n",l % 9);
            continue;
        }
        ll t = l + r;
        ll s = r - l + 1;
        // printf("%lld  %lld\n",t,s);
        if(t & 1) s >>= 1;
        else t >>= 1;
        // printf("%lld  %lld\n",t,s);
        printf("%lld\n",mul(t,s,9) % 9);
    }

}