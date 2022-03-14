#include <cstdio>
using namespace std;
typedef long long ll;

int main() {
    ll a, b, ans;
    scanf("%lld%lld",&a,&b);
    ans = a * b - a -b;
    printf("%lld\n",ans);    
}