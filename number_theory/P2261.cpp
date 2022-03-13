#include<cstdio>
using namespace std;
typedef long long ll;

ll n, k;

int main() {
    scanf("%lld%lld",&n,&k);
    ll left = 1, right;
    ll sum = 0;
    while (left <= n) {
        ll temp = k / left;
        if(temp == 0) break;
        right = k / temp <= n ? k / temp : n;
        sum += (left + right) * (right - left + 1) / 2 * temp;
        left = right + 1;
    }
    sum = n * k - sum;
    printf("%lld\n",sum);
}