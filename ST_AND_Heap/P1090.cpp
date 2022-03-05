#include<cstdio>
#include<queue>
using namespace std;
#define N 10005

int n;
int heap[N];

int main() {
    priority_queue<int,vector<int>,greater<int> > q;
    long long res = 0;
    scanf("%d",&n);
    int d;
    for(int i=0;i<n;i++) {
        scanf("%d",&d);
        q.push(d);
    }
    while(q.size()>1) {
        int add = q.top();
        q.pop();
        int top = q.top();
        q.pop();
        add += top;
        res += add;
        q.push(add);
    }
    printf("%lld\n",res);
}