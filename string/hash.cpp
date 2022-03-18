// 双重Hash方式，有一定错误概率
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100005
typedef unsigned long long ull;

int n;
struct Node {
    ull hash1, hash2;
}node [N];

const ull mod1 = 1844674407370955615;
const ull mod2 = 1000000000000002493;
const ull base1 = 9923335656754;
const ull base2 = 112376756745;

inline ull calc(const char *p, ull mod, ull base) {
    ull ans = 0;
    for (int i = 0; p[i]; i++) {
        ans = (ans + p[i]) * base % mod;
    }
    return ans;
}

bool cmp(Node &a, Node &b) {
    if(a.hash1 != b.hash1) {
        return a.hash1 < b.hash1;
    }
    return a.hash2 < b.hash2;
}

int main() {
    // freopen("in.in","rw",stdin);
    scanf("%d", &n);
    int pos = 0;
    char temp[N];
    for (int i = 0; i < n; i++) {
        scanf("%s",temp);
        // printf("temp = %s\n",temp);
        ull hash1 = calc(temp, mod1, base1);
        ull hash2 = calc(temp, mod2, base2);
        // printf("%llu %llu\n",hash1, hash2);
        node[pos].hash1 = hash1;
        node[pos].hash2 = hash2;
        ++pos;
    }
    sort(node, node + n, cmp);
    int ans = 1;
    Node *pre = &node[0];
    for (int i = 1;i < n; i++) {
        if (pre->hash1 != node[i].hash1 || pre->hash2 != node[i].hash2) {
            ++ans;
        }
        pre = &node[i]; 
    }
    printf("%d\n",ans);
    return 0;
}