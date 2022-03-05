#include <cstdio>
#include <queue>
using namespace std;
#define N 10005

int n,m;
int a[N],b[N],c[N];
int start[N];
bool enough[N];

priority_queue<int,vector<int>,greater<int> > q;

inline int f(int i, int key) {
    return (a[i] * key + b[i]) *key + c[i];
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        int temp = -(b[i])/(2*a[i]);
        start[i] = temp > 0 ? temp : 1;
    }
    int need = m;
    int max = -1;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(enough[j])   continue;
            int temp = f(j,start[j] + i);
            if(temp >= max && q.size() >= need){
                enough[j] = true;
                continue;
            }
            q.push(temp);
            if(temp > max) max = temp;
        }
    }
    for(int i=0;i<m;i++){
        if(i)   printf(" ");
        printf("%d",q.top());
        q.pop();
    }
}