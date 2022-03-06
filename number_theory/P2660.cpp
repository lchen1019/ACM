#include<cstdio>
using namespace std;
typedef long long ll;

ll a, b;    

int main() {
    scanf("%lld%lld",&a,&b);
    ll ans = 0;
    while(true) {
        printf("%lld  %lld\n",a,b);
        ll num = a / b;
        ans += num * 4 * b;
        if(a % b == 0)  break;
        ll temp = b;
        b = a % b;
        a = temp;
    }
    printf("%lld",ans);
}