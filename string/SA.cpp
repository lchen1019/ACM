// 后缀数组
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1000005

int n, k;       // k 表示倍增
char t[N];
int sa[N];
int r[N];
int temp[N];

// 比较r(i, 2k) 与 r(j, 2k)
bool cmp(int i, int j) {
    if (r[i] != r[j]) return r[i] < r[j];
    // 较短的在前面
    int ri = i + k < n ? r[i + k] : -1;
    int rj = j + k < n ? r[j + k] : -1;
    return ri < rj;
}

void SA() {
    // k = 1, 初始化
    int i = 0;
    for(i; t[i]; i++) {
        sa[i] = i;
        r[i] = t[i];
    }
    n = i;
    r[n] = -1, sa[n] = n;
    for (k = 1; k <= n; k++) {
        sort(sa, sa + n + 1, cmp);
    }
}

int main() {
    scanf("%d",t);

}