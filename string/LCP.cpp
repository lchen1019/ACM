// 高度数组是基于后缀数组的，与后缀数组一同使用是更强大的工具
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100005

int n, k;
char s[N];
int sa[N], lcp[N], r[N], temp[N];

bool cmp(int i, int j) {
    if (r[i] != r[j])   return r[i] < r[j];
    int ri = i + k <= n ? r[i + k] : -1;
    int rj = j + k <= n ? r[j + k] : -1;
    return ri < rj;
}

void SA() {
    for (int i = 0; i < n; i++) {
        sa[i] = i;
        r[i] = s[i];
    }
    for (k = 1; k <= n; k *= 2) {
        sort(sa, sa + n, cmp);
        temp[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            temp[sa[i]] = temp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        }
    }
}

void LCP() {
    for (int i = 0; i < n; i++) r[sa[i]] = i;
    int h = 0;
    // 计算S[i...]与S[sa[rank[i] - 1]...]的LCP
    for (int i = 0; i < n; i++) {
        int j = sa[r[i] - 1];
        if (h > 0)  h--;
        while(j + h < n && i + h < n && s[j + h] != s[i + h])   ++h;
        lcp[r[i] - 1] = h;
    }
}

int main() {
    scanf("%d", s);
    n = strlen(s);
    SA();
}