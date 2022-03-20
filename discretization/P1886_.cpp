// 单调队列的模板题目，可以线性时间复杂度维护一段区间内的最大、最小值
// 单调增序列，左侧是最小值
#include <cstdio>
using namespace std;
#define N 1000005

int n, k;
int a[N];
int minq[N], maxq[N];
int ans1[N], ans2[N];

void out(int maxh, int maxt) {
    printf("l = %d, r = %d\n", maxh, maxt);
    for (int i = maxh; i <= maxt; i++) {
        printf("%d ", a[maxq[i]]);
    }
    printf("\n");
}

int main() {
    scanf("%d%d", &n, &k);
    int maxh = 0, maxt = -1;
    int minh = 0, mint = -1;
    int tot = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        while (maxt >= maxh && a[maxq[maxt]] < a[i])
            --maxt;
        maxq[++maxt] = i;
        while (maxq[maxh] < i - k + 1)
            ++maxh;

        while (mint >= minh && a[minq[mint]] > a[i])
            --mint;
        minq[++mint] = i;
        while (minq[minh] < i - k + 1)
            ++minh;

        if (i >= k - 1) {
            ans1[tot] = a[minq[minh]];
            ans2[tot] = a[maxq[maxh]];
            ++tot;
        }
    }
    for (int i = 0; i < tot; i++) {
        if (i)
            printf(" ");
        printf("%d", ans1[i]);
    }
    printf("\n");
    for (int i = 0; i < tot; i++) {
        if (i)
            printf(" ");
        printf("%d", ans2[i]);
    }
}