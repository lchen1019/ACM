#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100005

const long long mod = 1e8 - 3;

int n;
struct Node {
    int key, order;
}node1[N], node2[N];
int a[N];
int l[N], r[N];
long long tot;

bool cmp(Node &a, Node &b) {
    return a.key < b.key;
}

void merge(int left, int right) {
    int mid = left + ((right - left) >> 1);
    int nl = mid - left + 1;
    int nr = right - mid;
    for(int i=0;i<nl;i++)   l[i] = a[i + left];
    for(int i=0;i<nr;i++)   r[i] = a[i + mid + 1];
    l[nl] = r[nr] = 0x7fffffff;
    int pos_l = 0, pos_r = 0, pos = 0;
    while(pos <= right - left) {
        if(l[pos_l] <= r[pos_r]) {
            a[pos + left] = l[pos_l++];
        } else {
            tot = (tot  + (nl - pos_l)) % mod;
            a[pos + left] = r[pos_r++];
        }
        pos++;
    }
}

void merge_sort(int left, int right) {
    if(left >= right)   return;
    int mid = left + ((right - left) >> 1);
    merge_sort(left ,mid);
    merge_sort(mid + 1,right);
    merge(left, right);
}

int main() {
    freopen("in.in","rw",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++)    scanf("%d",&node1[i].key), node1[i].order = i;
    for(int i=0;i<n;i++)    scanf("%d",&node2[i].key), node2[i].order = i;
    sort(node1,node1+n,cmp);
    sort(node2,node2+n,cmp);
    for(int i=0;i<n;i++)    a[node2[i].order] = node1[i].order;
    merge_sort(0, n - 1);
    printf("%lld\n",tot);
}