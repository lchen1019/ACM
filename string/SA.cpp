// 后缀数组 suffix array
// 后缀数组sa[i]表示第i小的前缀，是从sa[i]开始的前缀
// 可以认为空串和全部都是前缀
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 1000005

int n, k;  // k 表示倍增
char t[N];
int sa[N];
int r[N];
int temp[N];

// 比较r(i, 2k) 与 r(j, 2k)
bool cmp(int i, int j) {
    if (r[i] != r[j])
        return r[i] < r[j];
    // 较短的在前面
    int ri = i + k <= n ? r[i + k] : -1;
    int rj = j + k <= n ? r[j + k] : -1;
    return ri < rj;
}

void SA() {
    // k = 1, 初始化
    n = strlen(t);
    for (int i = 0; i < n; i++) {
        sa[i] = i;
        r[i] = t[i];
    }
    for (k = 1; k < n; k *= 2) {
        sort(sa, sa + n, cmp);
        temp[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            temp[sa[i]] = temp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        }
        for (int i = 0; i < n; i++) {
            r[i] = temp[i];
        }
    }
}

int main() {
    scanf("%s", t);
    SA();
    for (int i = 0; i < n; i++) {
        if (i)  printf(" ");
        printf("%d", sa[i] + 1);
    }
}