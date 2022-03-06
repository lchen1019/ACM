#include<cstdio>
using namespace std;
#define N 10005

int t, n;
int a[N];

int gcd(int a, int b) {
    if(b == 0)  return a;
    return gcd(b, a % b);
}

int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(int i = 0; i < n; i++) {
            scanf("%d",&a[i]);
        }
        int t = gcd(a[0], a[1]);
        t = a[1] / t;
        if(t == 1){
            printf("Yes\n");
            continue;
        }
        for (int i = 2; i < n; i++) {
            int k = gcd(a[i], t);
            printf("%d  %d  %d\n",a[i],t,k);
            t = t / k;
            if(t == 1){
                printf("Yes\n");
                continue;
            }
        }
        if(t != 1)  printf("No\n");
    }

}