#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;
#define N 100005
typedef unsigned long long ull;

const int tag = 5;
int n, t, q, m;
int s[N];
int a[N][100];
int r[N];

struct Hash {
    ull h[tag];
} ha, re;

// 向队列中添加时计算hash
void add(Hash &ha, int k) {
    ha.h[0] += (ull)k;
    ha.h[1] += (ull)sqrt(k);
    ha.h[2] += (ull) k * k;
    ha.h[3] += (ull) k >> 1;
    ha.h[4] += (ull) k * k * k;
}

// 删除队首元素，更新hash
void update(int k) {
    ha.h[0] -= (ull)k;
    ha.h[1] -= (ull)sqrt(k);
    ha.h[2] -= (ull)k * k;
    ha.h[3] -= (ull)k >> 1;
    ha.h[4] -= (ull)k * k * k;
}

// 计算真实re hash 
void calc_real() {
    for (int i = 0; i < t; i++) {
        add(re, s[i]);
    }
}

// 比较hash值是否相等
bool cmp() {
    for (int i = 0; i < tag; i++) {
        if (re.h[i] != ha.h[i]) return false;
    }
    return true;
}

void out(Hash &ha) {
    printf("hash = %d,",ha.h[0]);
    printf("%d,",ha.h[1]);
    printf("%d,",ha.h[2]);
    printf("%d\n",ha.h[3]);
}

int main() {
    scanf("%d%d%d",&n, &t, &q);
    for (int i = 0; i < t; i++)     scanf("%d", &s[i]);
    int len;
    for (int i = 1; i <= n; i++) {
        scanf("%d",&len);
        for (int j = 0; j < len; j++) {
            scanf("%d",&a[i][j]);
        }
        a[i][len] = -1; // 结束标记
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)     scanf("%d", &r[i]);
    calc_real();
    // out(re);
    // 问题分解成两部分， 中间每一个部分 + 两侧的
    ull ans = 0;
    queue<int> que;
    bool arrive = false;
    for (int i = 1; i <= q; i++) {
        int k = (i - 1) % m + 1;
        for (int j = 0; a[r[k]][j] != -1; j++) {
            que.push(a[r[k]][j]);
            add(ha, a[r[k]][j]);
            if (arrive || que.size() > n) {
                update(que.front());
                que.pop();
                arrive = true;
            }
        }
        out(ha);
        if (arrive && cmp())  ++ans;
    }
    printf("%llu\n",ans);
}