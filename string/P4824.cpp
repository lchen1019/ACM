#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
#define N 1000005

int lt, lp;
char t[N], p[N];
char ans[N];
int head, tail = -1;
stack<int> pre;
int nxt[N];

// 初始化next数组
void init() {
    int len = 0;
    for (int i = 2; i <= lp; i++) {
        while (len && p[len + 1] != p[i]) len = nxt[len];
        if (p[len + 1] == p[i])   len++;
        nxt[i] = len;
    }
}

int main() {
    scanf("%s", t + 1);
    scanf("%s", p + 1);
    lt = strlen(t + 1);
    lp = strlen(p + 1);
    init();
    // 遍历文本串
    int len = 0;
    for (int i = 1;i <= lt; i++) {
        while(len && p[len + 1] != t[i])    len = nxt[len];
        if (p[len + 1] == t[i]) ++len;
        if (len == lp) {
            len = nxt[len];
            printf("%d\n", i - lp + 1);
        }
    }
    for (int i = head; i <= tail; i++) {
        printf("%c", ans[i]);
    }
    printf("\n");
}