// 线性求出1-n的数中所有逆元
#include <cstdio>
using namespace std;
#define N 3000005
typedef long long ll;

ll n, p;
ll inv[N];

int main() {
    scanf("%lld%lld",&n,&p);
    inv[1] = 1;
    for (ll i = 2; i <= n; i++) {
        inv[i] = (-(p / i) * inv[p % i] % p + p) % p;
    }
    for (ll i = 1; i <= n; i++) {
        printf("%d\n",inv[i]);
    }
}