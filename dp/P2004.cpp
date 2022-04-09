#include <cstdio>
using namespace std;
#define N 105
#define max(a, b) (((a) > (b))? (a) : (b))
#define min(a, b) (((a) < (b))? (a) : (b))

int n;
int a[N];
int l[N], r[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        l[i] = 1;
        for (int k = 0; k < i; k++) {
            if (a[i] > a[k]) 
                l[i] = max(l[i], l[k] + 1);
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        r[i] = 1;
        for (int k = i + 1; k < n; k++) {
            if (a[i] > a[k]) 
                r[i] = max(r[i], r[k] + 1);
        }
    }
    int res = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
        res = min(res, n + 1 - (l[i] + r[i]));
    }
    printf("%d\n", res);
}