#include <cstdio>
#include <list>
using namespace std;
#define N 1005
#define max(a, b) (((a) > (b)) ? (a) : (b))
typedef pair<int, int> P;

int n, m;
list<P> w[N];
int dp[N][N];

int main() {
    scanf("%d%d", &m, &n);
    int a, b, c;
    int group =  -1;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &a, &b, &c);
        w[c].insert(w[c].end(), make_pair(a, b));
        group = max(group, c);
    }
    for (int i = 1; i <= group; i++) {
        for (auto &j : w[i]) {
            for (int k = m; k >= 0; k--) {
                if (k >= j.first) {
                    int t = max(dp[i - 1][k], dp[i - 1][k - j.first] + j.second);
                    dp[i][k] = max(dp[i][k], t);
                } else {
                    dp[i][k] = max(dp[i][k], dp[i - 1][k]);
                }
            }
        }
    }
    printf("%d\n", dp[group][m]);
    return 0;
}