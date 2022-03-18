#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
using namespace std;
typedef unsigned long long ull;
#define N 100005

const ull mod1 = 1844674407370955615;
const ull mod2 = 1000000000000002493;
const ull base1 = 9923335656754;
const ull base2 = 112376756745;

int n, m, pos;
struct Node {
    bool a[1005];
}node[N];
map<pair<ull,ull>, Node > p;
char tmp[N][30];
char s[N][1005][30];
int len[N];

pair<ull,ull> calc(char *p) {
    ull ans1 = 0, ans2 = 0;
    for (int i = 0; p[i]; i++) {
        ans1 += (p[i] * base1 + ans1) * base1 % mod1;
    }
    for (int i = 0; p[i]; i++) {
        ans2 += (p[i] * base2 + ans2) * base2 % mod1;
    }
    return make_pair(ans1, ans2);
}

int main() {
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%d",&len[i]);
        for (int j = 0; j < len[i]; j++) {
            scanf("%s",s[i][j]);
        }
    }
    scanf("%d",&m);
    char temp[N];
    for(int i=0;i<m;i++) {
        scanf("%s",tmp[i]);
        pair<ull,ull> t = calc(tmp[i]);
        p[t] = node[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < len[i]; j++) {
            char *temp = s[i][j];
            pair<ull,ull> t = calc(temp);
            p[t].a[i] = true;
        }
    }
    for(int i=0;i<m;i++) {
        pair<ull,ull> t = calc(tmp[i]);
        auto &it = p[t].a;
        bool first = true;
        for(int j=0;j<n;j++) {
            if(first && it[j])  printf("%d",j + 1), first = false;
            else if(it[j]) printf(" %d",j+1);   
        }
        printf("\n");
    }
}