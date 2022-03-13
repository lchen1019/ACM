// AC自动机是实现多模式匹配的算法，线性时间复杂度
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define N 1000005

int n;
int tr[N][26];  // 编号
int fail[N];    // 失配指针
int num[N];    // 是否标识着字符串结束，更一般的结果用来表示当前结尾的字符串数量个数
bool could[N];
int pos;
char t[N];
char temp[N];
int ans;

// 构建字典树
void build() {
    int cur = 0;
    for (int i = 0; temp[i]; i++) {
        if (tr[cur][temp[i] - 'a']) {
            cur = tr[cur][temp[i] - 'a'];
        } else {
            cur = tr[cur][temp[i] - 'a'] = ++pos;
        }
    }
    ++num[cur];
}

// BFS构建每个节点的失配指针
void get_fail() {
    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (tr[0][i])   q.push(tr[0][i]);
    }
    // 匹配当前节点的子节点的fail，而不是当前节点的
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int  i = 0; i < 26; i++) {
            if (tr[u][i]) {
                fail[tr[u][i]] = tr[fail[u]][i];
                q.push(tr[u][i]);
            } else {
                tr[u][i] = tr[fail[u]][i];
            }
        }
    }
}

// 查询
void query() {
    int u = 0;
    for (int i = 0; t[i]; i++) {
        u = tr[u][t[i] - 'a'];  // 转移
        for (int j = u; j && num[j] != -1; j = fail[j]) {
            ans += num[j], num[j] = -1;
        }
    }
}

int main() {
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%s", temp);
        build();
    }
    get_fail();
    scanf("%s", t);
    query();
    printf("%d\n",ans);
}