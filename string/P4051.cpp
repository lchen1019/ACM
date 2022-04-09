#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 1000005

int n, k;
char s[N];
int r[N << 1], sa[N << 1], temp[N << 1];

bool cmp(int i, int j) {
    if (r[i] != r[j])   return r[i] < r[j];
    int ri = i + k < 2 * n ? r[i + k] : -1;
    int rj = j + k < 2 * n ? r[j + k] : -1;
    return ri < rj;
}

void SA() {
    for (int i = n; i < 2 * n; i++) {
        s[i] = s[i - n];
    }
    s[2 * n] = '\0';
    for (int i = 0; i < 2 * n; i++) {
        sa[i] = i;
        r[i] = s[i];
    }
    for (k = 1; k <= n; k *= 2) {
        sort(sa, sa + 2 * n, cmp);
        temp[sa[0]] = 0;
        for (int i = 1; i < 2 * n; i++) {
            temp[sa[i]] = temp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        }
        for (int i = 0; i < 2 * n; i++) {
            r[i] = temp[i];
        }
    }
}

int main() {
    scanf("%s", s);
    n = strlen(s);
    SA();
    int cnt = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (sa[i] < n) {
            printf("%c", s[sa[i] + n - 1]);
        }
    }
}