// Tire树解决问题
#include <cstdio>
#include <list>
using namespace std;
#define N 500005

int n, m;
struct  Node{
    int next[26];
    char k;
    list<int> ans;
}node[N];
int pos;

int main() {
    scanf("%d", &n);
    int len;
    char temp[1005];
    for(int l = 0; l < n; l++) {
        scanf("%d", &len);
        for (int i = 0; i < len; i++) {
            scanf("%s", temp);
            int cur = 0;
            for (int j = 0; temp[j]; j++) {
                if(node[cur].next[temp[j] - 'a'] != 0) {
                    cur = node[cur].next[temp[j] - 'a'];
                } else {
                    cur = node[cur].next[temp[j] - 'a'] = ++pos;
                }
                node[cur].k = temp[j];
            }
            if (*node[cur].ans.rbegin() != l + 1)
                node[cur].ans.push_back(l + 1);
        }
    }
    scanf("%d", &m);
    while(m--) {
        scanf("%s", temp);
        int cur = 0;
        bool find = true;
        for (int i = 0; temp[i]; i++) {
            cur = node[cur].next[temp[i] - 'a'];
            // printf("cur = %d  %c\n", cur, temp[i]);
            if (cur == 0) {
                find = false;
                break;
            }
        }
        if (find) {
            bool out = false;
            for (int it : node[cur].ans) {
                if (out)    printf(" ");
                printf("%d",it);
                out = true;
            }
        }
        printf("\n");
    }
}