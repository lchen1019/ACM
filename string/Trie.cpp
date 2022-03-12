#include<cstdio>
using namespace std;
#define N 500005

int n, m;
struct Node {
    int next[26];
    bool end;
    bool vis;
} node[N];
int pos;

int main() {
    freopen("in.in","rw",stdin);
    scanf("%d",&n);
    char temp[55];   
    for (int i = 0; i < n; i++) {
        scanf("%s",temp);
        // printf("temp = %s\n",temp);
        int cur = 0;
        for (int j = 0; temp[j] != '\0'; j++) {
            // printf("ans = %d\n",node[cur].next[temp[j] - 'a']);
            // printf("cur = %d  %c\n",cur,temp[j]);
            if(node[cur].next[temp[j] - 'a'] != 0) {
                cur = node[cur].next[temp[j] - 'a'];
            } else {
                cur = node[cur].next[temp[j] - 'a'] = ++pos;
            }
            // printf("%d\n",cur);
        }
        node[cur].end = true;
    }
    scanf("%d",&m);
    while(m--) {
        scanf("%s",temp);
        bool find = true;
        int cur = 0;
        for (int j = 0; temp[j] != '\0'; j++) {
            cur = node[cur].next[temp[j] - 'a'];
            if (!cur) {
                find = false;
                break;
            }
        }
        if (node[cur].end && find) {
            if (node[cur].vis) {
                printf("REPEAT\n");
            } else {
                node[cur].vis = true;
                printf("OK\n");
            }
        } else {
            printf("WRONG\n");
        }
    }
}