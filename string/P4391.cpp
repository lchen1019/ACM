#include <cstdio>
using namespace std;
#define N 1000005

int n;
char t[N];
int next[N];

void init() {
    next[0] = 0;
    int len = 0;
    int i = 1;
    while(i < n) {
        if (t[len] == t[i]) {
            next[i++] = ++len;
        } else {
            if (len > 0) {
                len = next[len - 1];
            } else {
                next[i++] = 0;
            }
        }
    }
}

int main() {
    scanf("%d",&n);
    scanf("%s",t);
    init();
    printf("%d\n",n - next[n - 1]);
}