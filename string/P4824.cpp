#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
#define N 1000005

char t[N], p[N];
int nxt[N];

void init() {
    int i = 1, len = 0;
    while(p[i]) {
        if (p[len] == p[i]) {
            nxt[i++] = ++len;
        } else {
            if (len > 0) {
                len = nxt[len - 1];
            } else {
                nxt[i++] = 0;
            }
        }
    }
    for (int j = i; j >= 1; j--) {
        nxt[j] = nxt[j - 1];
    }
    nxt[0] = -1;
}

void KMP() {
    int pos_t = 0, pos_p = 0;
    int len_t = strlen(t), len_p = strlen(p);
    stack<char> ans;
    while(pos_t < len_t) {
        ans.push(t[pos_t]);
        // 匹配成功
        if (pos_p == len_p - 1 && ans.top() == p[pos_p]) {
            ans.pop();
            pos_p = nxt[pos_p];
            if (pos_p == -1)    ++pos_p, ++pos_t;
        }
        if (t[pos_t] == p[pos_p]) {
            ++pos_p, ++pos_t;
        } else {
            pos_p = nxt[pos_p];
            if (pos_p == -1)    ++pos_p, ++pos_t;
        }
    }
}

int main() {
    scanf("%s%s",t,p);
    init();
    // 匹配

}