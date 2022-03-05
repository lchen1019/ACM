#include<cstdio>
using namespace std;
#define N 100005

int n;
double a[N], sum[N];
int q[N]; 
int s, t, d;

bool check(double k) {
    // printf("k = %.3lf\n",k);
    for(int i=1;i<=n;i++)    sum[i] = a[i] - k;
    for(int i=2;i<=n;i++)    sum[i] += sum[i - 1];
    // 求最小值
    int head = 0, tail = -1;
    for(int i=0;i<=n;i++) {
        // 右侧入队
        while(head <= tail && sum[q[tail]] > sum[i]) --tail;
        q[++tail] = i;
        // 左侧出队
        while(q[head] < i - d + 1) ++head;
        if(i + s < n && sum[i + s] >= sum[q[head]]) return true;
    }
    return false;
}

int main() {
    scanf("%d",&n);
    scanf("%d%d",&s, &t);
    for(int i=1;i<=n;i++) {
        scanf("%lf",&a[i]);
    }
    d = t - s + 1;
    double left = -10000;
    double right = 10000;
    while(right - left >= 0.000001) {
        double mid = (left + right) / 2;
        if(check(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    printf("%.3lf\n",left);
}
