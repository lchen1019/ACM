#include <cstdio>
#include <cstring>
#include <cstdlib>
#define N 1000005

int n;
char *pre, *next;
int prefix[N];
int len_p, len_t;

void init() {
    prefix[0] = 0;
    int pos = 0, i = 1;
    while (i < len_p) {
        if (next[pos] == next[i]) {
            prefix[i++] = ++pos;
        } else {
            if(pos > 0) {
                pos = prefix[pos - 1];
            } else {
                prefix[i++] = 0;
            }
        }
    }
    for (int i = len_p - 1; i >= 1; i--) {
        prefix[i] = prefix[i - 1];
    }
    prefix[0] = -1;
}

int KMP() {
    int pos_t = 0, pos_p = 0;
    while(pos_t < len_t) {
        if (pre[pos_t] == next[pos_p]) {
            pos_p++, pos_t++;
        } else {
            pos_p = prefix[pos_p];
            if(pos_p == -1) {
                pos_p++, pos_t++;
            }
        }
    }
    return pos_p;
}

int main() {
    scanf("%d",&n);
    scanf("%s", pre);
    pre = (char*) malloc(sizeof(char) * N);
    next = (char*) malloc(sizeof(char) * N);
    scanf("%s", pre);
    n--;
    len_t = strlen(pre);
    while(n--) {
        scanf("%s",next);
        len_p = strlen(next);
        init();
        char *temp = pre;
        char lent = len_t; // int lent = len_t;

        // printf("%d  %d\n",len_t,len_p);
        if (len_t > len_p) {
            pre = pre + len_t - len_p;
            len_t = len_t - (len_t - len_p);
        }
        int d = KMP();
        pre = temp;
        len_t = lent;
        for (int i = d; i <= len_p; i++) {
            pre[i - d + len_t] = next[i];
        }
        len_t += (len_p - d);
    }
    printf("%s\n",pre);
    return 0;
}