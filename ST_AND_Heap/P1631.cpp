#include<cstdio>
#include<queue>
using namespace std;
#define N 100005

int n;
int a[N];
int b[N];
priority_queue<int,vector<int>, greater<int> > q;

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a + i);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",b+i);
    }
    int add = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i * j > n) {
                break;
            }
            add = a[i] + b[j];
            q.push(add);
        }
    }
    for(int i=0;i<n;i++){
        if(i)   printf(" ");
        printf("%d",q.top());
        q.pop();
    }
}