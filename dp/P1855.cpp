#include <cstdio>
using namespace std;
#define N 205
#define M 105
#define max(a, b) (((a) > (b))? (a) : (b))

int m, s, t;
int dp[N][N];
struct Node {
    int s, t;
} node[N];

int main() {
    scanf("%d%d%d", &m, &s, &t);
    for (int i = 0; i < m; i++) scanf("%d%d", &node[i].s, &node[i].t);
    for (int k = 0; k < m; k++) {
        for (int i = s; i >= node[k].s; i--) {
            for (int j = t; j >= node[k].t; j--) {
                dp[i][j] = max(dp[i][j], dp[i - node[k].s][j - node[k].t] + 1);
            }
        }
    }
    printf("%d\n", dp[s][t]);
}