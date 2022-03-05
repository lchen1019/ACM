#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define N 20005
#define max(a,b) (((a) > (b))?(a):(b))
typedef long long ll;

int n;
pair<int, int> p[N];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &p[i].first, &p[i].second);
    }
    sort(p, p + n);
    ll res = 0;
    for (int i = 0; i < n; i++) {
        ll left = p[i].first;
        ll right = p[i].second;
        // i++;
        while (right >= p[i + 1].first && i + 1 < n) {
            ++i;
            right = max(right, p[i].second);
        }
        res += right - left;
    }
    printf("%lld\n", res);
}