#include <cstdio>
using namespace std;
#define N 1000005

int n, k;
int a[N];
int maxq[N], minq[N];  // maxq递减，min递增
int ans1[N], ans2[N];

int main() {
    scanf("%d%d", &n, &k);
    int maxh = 0, maxt = -1;
    int minh = 0, mint = -1;
    int tot = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        while (a[maxq[maxt]] < a[i] && maxt >= maxh) {
            --maxt;
        }
        maxq[++maxt] = i;
        while (maxq[maxh] < i - k + 1)
            maxh++;

        while (a[minq[mint]] > a[i] && mint >= minh) {
            --mint;
        }
        minq[++mint] = i;
        while (minq[minh] < i - k + 1)
            minh++;

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