#include <cstdio>
using namespace std;
#define N 11000005

int n;
char a[N];
char p[N << 1];
int ans[N << 1];
int len, res;

// 加上特殊标记解决奇偶数问题
void pre() {
    p[0] = '~';
    p[1] = '#';
    int i;
    for (i = 1; a[i - 1]; i++) {
        p[i << 1] = a[i - 1];
        p[i << 1 | 1] = '#';
    }
    len = i << 1;
}

void Manacher() {
    int mid = 0, right = 0;
    for (int i = 1; i < len; i++) {
        int cos = (mid << 1) - i;   // 寻找对称点
        if (i <= right) 
            ans[i] = ans[cos] > right - i + 1 ? right - i + 1 : ans[cos];
        while(p[i - ans[i]] == p[i + ans[i]])   ++ans[i];
        if (ans[i] + i > right) right = ans[i] + i - 1, mid = i;
        if(ans[i] > res) res = ans[i];
    }
}

int main() {
    scanf("%s", a);
    pre();
    Manacher();
    printf("%d",res - 1);
        // for(int i = 2; i <= len; i++) {
        // printf("%d  %d\n",i, ans[i]);
        // if((i ^ 1) && (a[i] & 1)) {
        //     res = res * a[i] % mod;
        // }
    // }
}