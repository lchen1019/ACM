#include<cstdio>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if(b == 0)  return a;
    return gcd(b, a%b);
}

int main() {
    ll a, b, c;
    scanf("%lld%lld%lld",&a,&b,&c);
    ll t = a * b / gcd(a, b);
    t = t * c / gcd(t, c);
    printf("%lld\n",t);
}