#include<cstdio>
using namespace std;
typedef long long ll;

int tot;

int main() {
    scanf("%d",&tot);
    ll k;
    while(tot--) {
        scanf("%lld",&k);
        if(k == 4 || k == 10)   printf("%lld\n",k+1);
        else    printf("%lld\n",k-1);
    }
}