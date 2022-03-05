#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
#define N 150005

int n;
struct Node{
    int need,end;
}node[N];
priority_queue<int,vector<int>,less<int> > q;

bool cmp(Node &a, Node &b) {
    if(a.end != b.end) {
        return a.end < b.end;
    }
    return a.need < b.need;
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&node[i].need,&node[i].end);
    }
    sort(node,node+n,cmp);
    int cur = 0;
    int res = 0;
    for(int i=0;i<n;i++) {
        if(cur + node[i].need <= node[i].end) {
            q.push(node[i].need);
            cur += node[i].need;
            ++res;
        } else if(!q.empty()) {
            if(q.top() > node[i].need) {
                cur += (node[i].need - q.top());
                q.pop();
                q.push(node[i].need);
            }
        }
    }
    printf("%d\n",res);
}