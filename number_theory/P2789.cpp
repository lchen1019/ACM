#include<cstdio>
using namespace std;

int n;
bool dp[30][1005];

int main() {
    scanf("%d",&n);
    for (int i = 1;i <= n; i++) {
        dp[i][0] = true;

        for (int j = 1; j <= i - 1;j++) {
            int tot = j * (i - j);
            int max = j * (j - 1) / 2;
            for(int k = 0; k <= max; k++) {
                if(dp[j][k]){
                     dp[i][k + tot] = true;
                }
            }
        }
    }
    int ans = 0;
    int max = n * (n - 1) / 2;
    for(int i=0;i<=max;i++) {
        if(dp[n][i])    ans++;
    }
    printf("%d\n",ans);
}