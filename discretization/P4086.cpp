#include<cstdio>
#include<cstring>
using namespace std;
#define N 100005
#define abs(a) (((a) < 0) ? (-a) : (a))

int n;
int a[N];
int tree[N];    // 树状数组
int min[N];

// 向a[pos] + val
void add(int pos, int val) {
    while(pos <= n) {
        tree[pos] += val;
        pos += pos & -pos;
    }
}

int sum(int pos) {
    int res = 0;
    while(pos > 0) {
        res += tree[pos];
        pos -= pos & -pos;
    }
    return res;
}

void add_(int pos, int val) {
    while(pos <= n) {
        min[pos] = min[pos] < val ? min[pos] : val;
        pos += pos & -pos;
    }
}

int get(int pos) {
    int res = 0x3f3f3f3f;
    while(pos > 0) {
        res = min[pos] < res ? min[pos] : res;
        pos -= pos & -pos;
    }
    return res;
}

int main() {
    scanf("%d",&n);
    memset(min, 0x3f, sizeof(min));
    for(int i=n;i>=1;i--){
        scanf("%d",&a[i]);
        add(i, a[i]);
        add_(i, a[i]);
    }
    double max = -1;
    int k[100000];
    int pos = 1;
    for(int i=2;i<=n - 1;i++) {
        double temp = (double)(sum(i) - get(i)) / (i - 1);
        // printf("%lf  %lf\n",temp,max);
        double a = temp - max;
        // printf("%lf\n",abs(a));
        if(temp == max){
            // printf("asdad\n");
            k[pos++] = n - i;
        } else if(max < temp) {
            // printf("dfgdfg\n");
            max = temp;
            pos = 1;
            k[pos - 1] = n - i;
        }
    }
    for(int i=pos - 1;i>=0;i--) {
        printf("%d\n",k[i]);
    }
}