#include<cstdio>
#include<cstring>
using namespace std;
#define N 1000005

char t[N], p[N];
int len_t, len_p;
int prefix[N];

// 初始化前缀表
void init() {
    int i = 1;
    int pos = 0;
    prefix[0] = 0;
    while (i < len_p) {
            // printf("i = %d\n",i);
        if (p[pos] == p[i]) {
            ++pos;
            prefix[i++] = pos;
        } else {
            if (pos > 0) {
                pos = prefix[pos - 1];
            } else {
                prefix[i++] = 0;
            }
        }
    }
    // 方便编程向右挪一位
    for (int i = len_p; i >= 1; i--) {
        prefix[i] = prefix[i - 1];
    }
    prefix[0] = -1;
    for(int i = 0; i <= len_p; i++) {
        printf("%-3d", prefix[i]);
    }
    printf("\n");
}

// 匹配方法
void KMP() {
    int pos_t = 0, pos_p = 0;
    while(pos_t < len_t) {
        if (pos_p == len_p - 1 && t[pos_t] == p[pos_p]) {
            printf("%d\n", pos_t - pos_p + 1);
            pos_p = prefix[pos_p];
            if(pos_p == -1) pos_p++, pos_t++;
        }
        if (t[pos_t] == p[pos_p]) {
            pos_t++, pos_p++;
        } else {
            pos_p = prefix[pos_p];
            if(pos_p == -1) pos_p++, pos_t++;
        }
    }
}

// ABABCABAA
int main() {
    scanf("%s",t);
    scanf("%s",p);
    len_t = strlen(t), len_p = strlen(p);
    init();
    KMP();
    for (int i = 1; i <= len_p; i++) {
        printf("%d ",prefix[i]);
    }
}