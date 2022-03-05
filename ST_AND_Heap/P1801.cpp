#include<cstdio>
#include<queue>
using namespace std;
#define N 200005

int n,m;
int a[N];
int b[N];

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)    scanf("%d",&a[i]);
    for(int i=0;i<m;i++)    scanf("%d",&b[i]);
    priority_queue<int,vector<int>, greater<int> > minq;
    priority_queue<int,vector<int>,less<int> > maxq;
    maxq.push(a[0]);
    int pos = 1;
    int cur = 0;
    for(int i=0;i<m;i++){
        while(pos < b[i]) {
            if(maxq.top() < a[pos]) {
                minq.push(a[pos]);
            } else {
                maxq.push(a[pos]);
            }
            ++pos;
        }
        ++cur;
        while(maxq.size() > cur) {
            minq.push(maxq.top());
            maxq.pop();
        }
        while(maxq.size() < cur) {
            maxq.push(minq.top());
            minq.pop();
        }
        printf("%d\n",maxq.top());
    }
}