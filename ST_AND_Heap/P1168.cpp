#include<cstdio>
#include<queue>
// #include<vector>
using namespace std;
#define N 100005

int n;
int a[N];
priority_queue<int,vector<int>,greater<int> > minq;
priority_queue<int,vector<int>,less<int> > maxq;

int main() {
    scanf("%d",&n);
    int k;
    scanf("%d",&k);
    printf("%d\n",k);
    minq.push(k);
    for(int i=2;i<=n;i++) {
        scanf("%d",&k);
        if(k < minq.top()) {
            maxq.push(k);
        } else {
            minq.push(k);
        }
        if(i & 1) {
            int minl = minq.size();
            int maxl = maxq.size();
            if(maxl - minl == 3) {
                minq.push(maxq.top());
                maxq.pop();
                printf("%d\n",maxq.top());
            } else if(minl - maxl == 3) {
                maxq.push(minq.top());
                minq.pop();
                printf("%d\n",minq.top());
            } else if(maxl > minl) {
                printf("%d\n",maxq.top());
            } else {
                printf("%d\n",minq.top());
            }
        }
    }

}