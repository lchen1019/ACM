#include <cstdio>
using namespace std;
#define M 100005

int n,N;
int a[M];

int main() {
    scanf("%d%d",&n,&N);
    for(int i=1;i<=n;i++) {
        scanf("%d",a + i);
    }
    a[n+1] = N;
    int r = N / (n + 1);
    long long res = 0;
    for(int i=0;i<=n;i++) {
        int g = a[i] / r;
        int left = a[i];
        while(true) {
            int right = (g + 1) * r;
            if(right >= a[i + 1]) {
                int temp = (g - i) < 0 ? (i - g) : (g - i);
                res += temp * (a[i+1] - left);
                break;
            }
            int temp = (g - i) < 0 ? (i - g) : (g - i);
            res += temp * (right - left);
            ++g;
            left = right;
        }
    }
    printf("%lld\n",res);
}
