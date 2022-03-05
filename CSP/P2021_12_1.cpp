#include<cstdio>
using namespace std;
#define M 205
typedef long long ll;

int n,N;
int a[M];

int main() {
    scanf("%d%d",&n,&N);
    for(int i=1;i<=n;i++) {
        scanf("%d",a + i);
    }
    ll sum = 0;
    a[n + 1] = N;
    for(int i=0;i<=n;i++) {
        sum += (a[i + 1] - a[i]) * i;
    }
    printf("%lld\n",sum);
}