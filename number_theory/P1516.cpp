#include <cstdio>
using namespace std;
typedef long long ll;

ll x, y, m, n, p;

ll extgcd (ll a, ll b, ll  &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll gcd = extgcd(b, a % b, x, y);
    ll temp_y = y;
    y = x - a / b * y;
    x = temp_y;
    return gcd;
}

int main() {
    scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&p);
    ll a = ((m - n) % p + p) % p;
    ll b = ((y - x) % p + p) % p;
    // ll a = m - n;
    // ll b = y - x;
    // if (a < 0)  a = -a, b = -b;
    ll gcd = extgcd(a, p, x, y);
    if (b % gcd) {
        printf("Impossible\n");
        return 0;
    }
    p /= gcd;
    ll ans = (x % p + p) % p;
    ans = (ans * (b / gcd) % p + p) % p;
    printf("%lld\n",ans);
}