// 求出字符串的每一个后缀与当前字符串的字长公共前缀(lcp)
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
#define N 20000005

char s[N], t[N];
int nxt[N], ext[N];

void get_next() {
    int k = 1, p = 0;
    int len = strlen(s);
    nxt[0] = len;
    for (int i = 1; i < len; i++) {
        // 不是p - i + 1的原因是，在边界也需要判断
        if (nxt[i - k] <= p - i) {
            nxt[i] = nxt[i - k];
        } else {
            nxt[i] = p - i + 1 > 0 ? p - i + 1 : 0;  // [k, p]不一定可以包含i
            while (s[nxt[i]] == s[i + nxt[i]])
                ++nxt[i];
            k = i;
            p = i + nxt[i] - 1;
        }
    }
}

void extcmp() {
    int k = 0, p = -1;
    int len_s = strlen(s);
    s[len_s] = '#';
    int len_t = strlen(t);
    t[len_t] = '~';
    // ext[0] = p = 4;
    for (int i = 0; i < len_t; i++) {
        if (nxt[i - k] <= p - i) {
            ext[i] = nxt[i - k];
        } else {
            ext[i] = p - i + 1 > 0 ? p - i + 1 : 0;
            while (s[ext[i]] == t[i + ext[i]])
                ++ext[i];
            k = i;
            p = i + ext[i] - 1;
        }
    }
}

// aaabaaaab
int main() {
    freopen("in.in", "rw", stdin);
    scanf("%s", t);
    scanf("%s", s);
    get_next();
    extcmp();
    ll la = strlen(t), lb = strlen(s), ans = 0;
    for (int i = 0; i < lb - 1; i++)  //要注意下标从 0 开始
    {
        ans ^= (ll)(i + 1) * (nxt[i] + 1);
    }
    printf("%lld\n", ans);
    ans = 0;
    for (int i = 0; i < la - 1; i++) {
        ans ^= (ll)(i + 1) * (ext[i] + 1);
    }
    printf("%lld", ans);
    return 0;
}