#include <cstdio>
using namespace std;
typedef long long ll;
#define N 1000005

int n;
char s[N];
int next[N];

void init() {
    int i = 1, len = 0;
    while(i < n) {
        if (s[len] == s[i]) {
            next[i++] = ++len;
        } else {
            if (len > 0) {
                len = next[len - 1];
            } else {
                next[i++] = 0;
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        next[i] = next[i - 1];
    }
}

int main() {
    // freopen("in.in","rw",stdin);
    scanf("%d",&n);
    scanf("%s",s);
    init();
    // for(int i = 0 ;i <= n;i++) {
        // printf("%d\n",next[i]);
    // }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int j = i;
        while(next[j])  j = next[j];
        if(next[i] != 0) next[i] = j;
        // printf("i = %d, ans = %d\n",i, j);
        ans += (i - j);
    }
    printf("%lld\n",ans);
}