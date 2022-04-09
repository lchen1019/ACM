#include <cstdio>
using namespace std;
#define N 30
#define M 30005
typedef long long ll;
#define max(a, b) (((a) > (b))? (a) : (b))

int n, m;
ll dp[M];
ll v[N];
int w[N];

int main() {
    scanf("%d%d", &n, &m);
    int g;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &w[i], &g);
        v[i] = w[i] * g;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    printf("%d\n", dp[n]);
}