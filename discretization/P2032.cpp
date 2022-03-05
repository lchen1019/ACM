#include<cstdio>
using namespace std;
#define N 2000005

int n,k;
int a[N];
int q[N];

int main() {
    scanf("%d%d",&n,&k);
    int d;
    int head = 0, tail = -1;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        // 队列为空直接加入
        if(tail < head) {
            q[++tail] = i;
            continue;
        }
        // 队列不为空，比较队尾和待加入的元素大小
        if (a[q[tail]] >= a[i]) {
            q[++tail] = i;
        } else {
            // 一直出队列，直到比它大或者为空
            while(a[q[tail]] < a[i] && head <= tail)    --tail;
            q[++tail] = i;
        }
        while(q[head] < i - k + 1) head++;
        if(i >= k - 1)
            printf("%d\n",a[q[head]]);
    }
    
}