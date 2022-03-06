#include <cstdio>
using namespace std;
#define N 1000005

int n;
int a[N];

void Eratosthenes() {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            a[j]++;
        }
    }
}

int main() {
    scanf("%d", &n);
    int ans = 0;
    Eratosthenes();
    for (int i = 1; i <= n; i++) {
        ans += a[i];
    }   
    printf("%d\n",ans);
}