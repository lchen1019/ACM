#include <cstdio>
using namespace std;
#define N 50005
typedef long long ll;

int prime[N];
int L, R;
bool vis[N];

void sieve() {
    vis[0] = vis[1] = true;
    int pos = 0;
    for (int i = 2; i <= N; i++) {
        if (!vis[i]) {
            prime[pos++] = i;
        }
        for (int j = 0; j < pos && prime[j] * i <= N; j++) {
            vis[prime[j] * i] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main() {
    sieve();
    scanf("%d%d", &L, &R);
    int ans = 0;
    for (ll i = L; i <= R; i++) {
        bool done = false;
        if(i == 0 || i == 1) {
            continue;
        }
        for (ll j = 0; (ll) prime[j] * prime[j] <= i; j++) {
            if (i % prime[j] == 0) {
                done = true;
                break;
            }
        }
        if (!done)  ans++;
    }
    printf("%d\n",ans);
}