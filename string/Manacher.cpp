#include<cstdio>
#include<cstring>
using namespace std;
#define N 11000005

int n;
char a[N];
char p[N << 1];
int ans[N << 1];
int len = 0;
int res;

void pre() {
    p[0] = '~';
    p[1] = '#';
    int i;
    for(i = 1; a[i - 1] != '\0'; i++) {
        p[i << 1] = a[i - 1];
        p[i << 1 | 1] = '#';
    }
    len = i << 1;
    // printf("%s\n",p);
}

void manacher() {
    int mid = 0, right = 0;
    for (int i = 1; i < len; i++) {
        // printf("mid = %d,i = %d,right = %d\n",mid,i,right);
        // 一定是位于[mid, right]之间的
        // printf("index = %d\n",(mid << 1) - i);
        if(i <= right)   ans[i] = ans[(mid << 1) - i] > right - i + 1 ? right - i + 1 : ans[(mid << 1) - i];
        // 确定其对称点
        // ans[i], 表示i的右侧回文串的长度
        while(p[i - ans[i]] == p[i + ans[i]]) ++ans[i];
        if(ans[i] + i > right)  right = ans[i] + i - 1, mid = i;
        if(ans[i] > res) res = ans[i];
    }
}

int main() {
    scanf("%s",a);
    pre();
    manacher();
    printf("%d",res - 1);
        for(int i = 2; i <= len; i++) {
        printf("%d  %d\n",i, ans[i]);
        // if((i ^ 1) && (a[i] & 1)) {
        //     res = res * a[i] % mod;
        // }
    }
}