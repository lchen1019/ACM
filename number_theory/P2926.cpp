#include<cstdio>
using namespace std;
#define N 1000005

int n;
int a[N];
int f[N];
int ans[N];

void Eratosthenes() {
    
    for(int i=1;i<=N;i++) {
        ans[i] += f[i] - 1;
        for(int j=2*i;j<=N;j+=i) {
            ans[j] += f[i];
        }
    }
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        ++f[a[i]];
    }
    Eratosthenes();
    for(int i=0;i<n;i++) {
        printf("%d\n",ans[a[i]]);
    }
    return 0;
}