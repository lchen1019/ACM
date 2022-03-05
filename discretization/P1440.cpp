#include<cstdio>
using namespace std;
#define N 2000005

int n, k;
int a[N];
int q[N];

int main() {
    scanf("%d%d",&n,&k);
    int head = 0, tail = -1;
    printf("0\n");
    for(int i=0;i<n-1;i++) {
        scanf("%d",&a[i]);
        while(head <= tail && a[q[tail]] > a[i]) tail--;
        q[++tail] = i;
        while(q[head] < i - k + 1) head++;
        printf("%d\n",a[q[head]]);
    }
}