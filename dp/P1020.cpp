// 最长递增子序列（LIS），反过来的是最长递减子序列
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 100005

int n;
int a[N];
int dp[N];

int main() {
    int temp;
    while((scanf("%d", &temp) != EOF))  a[n++] = temp;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = n - 1; i >= 0; i--) {
        *(upper_bound(dp, dp + (n - i), a[i])) = a[i];
    }
    printf("%d\n", lower_bound(dp, dp + n, 0x3f3f3f3f) - dp);
}