#include <cstdio>
using namespace std;
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define N 45
#define max(a,b) (((a) > (b)) ? (a) : (b))

int n, m; 
int dp[N][N][N][N];
int w[355], t[5];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    int temp;
    for (int i = 0; i < m; i++) {
        scanf("%d", &temp);
        ++t[temp];
    }
    // DP
    dp[0][0][0][0] = w[1];
    for (int a = 0; a <= t[1]; a++) {
        for (int b = 0; b <= t[2]; b++) {
            for (int c = 0; c <= t[3]; c++) {
               for (int d = 0; d <= t[4]; d++) {
                    int k = a + b * 2 + c * 3 + d * 4;
                    if (a > 0) {
                        dp[a][b][c][d] = max(dp[a][b][c][d], dp[a - 1][b][c][d] + w[k + 1]);
                    }
                    if (b > 0) {
                        dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b - 1][c][d] + w[k + 1]);
                    }
                    if (c > 0) {
                        dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c - 1][d] + w[k + 1]);
                    }
                    if (d > 0) {
                        dp[a][b][c][d] = max(dp[a][b][c][d], dp[a][b][c][d - 1] + w[k + 1]);
                    }
                }
            }
        }   
    }
    printf("%d\n", dp[t[1]][t[2]][t[3]][t[4]]);
}