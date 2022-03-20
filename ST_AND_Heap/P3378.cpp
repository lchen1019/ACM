#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int op, k;
    priority_queue<int,vector<int>,greater<int> > q;
    for (int i = 0; i < n; i++) {
        scanf("%d",&op);
        if (op == 1)    scanf("%d",&k),q.push(k);
        else if(op == 2)    printf("%d\n",q.top());
        else    q.pop();
    }

}