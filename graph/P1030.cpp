#include <cstdio>
#include <cstring>
using namespace std;
#define N 105

char post[N], mid[N];
char tree[N];

void recover(int sm, int em, int sp, int ep, int pos) {
    if (sm > em || sp > ep) return;
    if (sm == em) {
        tree[pos] = mid[sm];
        return;
    }
    int k;
    for (int i = sm; i <= em; i++) {
        if (mid[i] == post[ep]) {
            k = i;
            break;
        }
    }
    int len_l = k - sm;
    int len_r = em - k;
    recover(sm, k - 1, sp, sp + len_l - 1, pos << 1);
    recover(k + 1, em, sp + len_l, ep - 1, pos << 1 | 1);
    tree[pos] = mid[k];
}

void pre(int pos) {
    if (tree[pos] == 0) return;
    printf("%c", tree[pos]);
    pre(pos << 1);
    pre(pos << 1 | 1);
}

int main() {
    scanf("%s",mid);
    scanf("%s",post);
    int n = strlen(mid);
    recover(0, n - 1, 0, n - 1, 1);
    pre(1);
}