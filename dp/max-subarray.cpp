#include <cstdio>
using namespace std;
#define N 100005
#define max(a,b) (((a) > (b)) ? (a) : (b))

int n;
int a[N];

int cross(int l, int mid, int r) {
    int max_l = 0, max_r = 0;
    int sum_l = 0, sum_r = 0;
    for (int i = mid + 1; i <= r; i++) {
        sum_r += a[i];
        if (sum_r > max_r) {
            max_r = sum_r;
        }
    }
    for (int i = mid; i >= l; i--) {
        sum_l += a[i];
        if (sum_l > max_l) {
            max_l = sum_l;
        }
    }
    return max_l + max_r;
}

int solve(int l, int r) {
    if (l >= r) return a[l];
    int mid = l + ((r - l) >> 1);
    int max_l = solve(l, mid);
    int max_r = solve(mid + 1, r);
    int across = cross(l, mid, r);
    int ans = max(max_l, max_r);
    ans = max(ans, across);
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("%d\n", solve(0, n-1));
}