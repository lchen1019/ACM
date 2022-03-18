#include <cstdio>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
#define N 100
#define max(a,b) (((a) > (b))? (a) : (b))

const ull mod = 1280397863;
const ull base = 233;
char *s, *t;
int len_s, len_t;
ull aft[N], pre[N];

ull calc(int left, int right, char *p, ull &ans) {
    for (int i = left; i <= right; i++) {
        ans = (ans + p[i] * base) * base % mod;
    }
}

int main() {
    t = new char[N];
    s = new char[N];
    scanf("%s", t);
    scanf("%s", s);
    len_s = strlen(s);
    len_t = strlen(t);
    int len = len_s > len_t ? len_t : len_s;
    for (int i = 0; s[i]; i++)  calc(i, len_s - 1, s, aft[i]);
    for (int i = 0; t[i]; i++)  calc(0, i, t, pre[i]);
    int ans = -1;
    for (int i = 0; i < len; i++) {
        if(aft[len_s - 1 -i] == pre[i])
            ans = max(ans, i + 1);
    }
    memset(aft, 0, sizeof(aft));
    memset(pre, 0, sizeof(pre));
    char *temp = s;
    s = t;
    t = temp;
    len_s = strlen(s);
    len_t = strlen(t);
    len = len_s > len_t ? len_t : len_s;
    for (int i = 0; s[i]; i++)  calc(i, len_s - 1, s, aft[i]);
    for (int i = 0; t[i]; i++)  calc(0, i, t, pre[i]);
    for (int i = 0; i < len; i++) {
        if(aft[len_s - 1 -i] == pre[i])
            ans = max(ans, i + 1);
    }
    printf("%d\n",ans);
}