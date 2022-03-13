// 拓展中国剩余定理可以解决模数不互质的问题
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long lt;

lt read() {
    lt f = 1, x = 0;
    char ss = getchar();
    while (ss < '0' || ss > '9') {
        if (ss == '-')
            f = -1;
        ss = getchar();
    }
    while (ss >= '0' && ss <= '9') {
        x = x * 10 + ss - '0';
        ss = getchar();
    }
    return f * x;
}

const int maxn = 100010;
int n;
lt ai[maxn], bi[maxn];

lt mul(lt a, lt b, lt mod) {
    lt res = 0;
    while (b > 0) {
        if (b & 1)
            res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}

lt exgcd(lt a, lt b, lt& x, lt& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    lt gcd = exgcd(b, a % b, x, y);
    lt tp = x;
    x = y;
    y = tp - a / b * y;
    return gcd;
}

lt excrt() {
    lt x, y, k;
    lt M = bi[1], ans = ai[1];  //第一个方程的解特判
    for (int i = 2; i <= n; i++) {
        printf("i = %lld\n",i-1);
        lt a = M, b = bi[i], c = (ai[i] - ans % b + b) % b;  // ax≡c(mod b)
        printf("%lld %lld %lld %lld %lld\n", M, b,ans,ai[i],c);
        lt gcd = exgcd(a, b, x, y), bg = b / gcd;
        if (c % gcd != 0)
            return -1;  //判断是否无解，然而这题其实不用
        printf("%lld %lld %lld\n",gcd,x,y);
        x = mul(x, c / gcd, bg);
        ans += x * M;  //更新前k个方程组的答案
        printf("%lld  %lld  %lld\n",x,bg,M);
        M *= bg;       // M为前k个m的lcm
        ans = (ans % M + M) % M;
        printf("%lld\n",ans);
    }
    return (ans % M + M) % M;
}

int main() {
    freopen("in.in","rw",stdin);

    n = read();
    for (int i = 1; i <= n; ++i)
        bi[i] = read(), ai[i] = read();
    printf("%lld", excrt());
    return 0;
}