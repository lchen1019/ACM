#include<cstdio>
using namespace std;
#define N 100005
typedef long long ll;

int dat[N], n;
ll tree[N << 2];
ll lazy[N << 2];
int m;

void build(int l, int r, int pos) {
    if (l == r) {
        tree[pos] = dat[l];
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(l, mid, pos << 1);
    build(mid + 1, r, pos << 1 | 1);
    tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];    
}

void pushdown(int pos, int nl, int nr) {
    if (!lazy[pos])
        return;
    lazy[pos << 1] += lazy[pos];
    lazy[pos << 1 | 1] += lazy[pos];
    tree[pos << 1] += nl * lazy[pos];
    tree[pos << 1 | 1] += nr * lazy[pos];
    lazy[pos] = 0;
}

void update(int l ,int r, int x, int y, int pos, int val) {
    if (y < l || x > r)
        return;
    // 标记下放
    if (x <= l && y >= r) {
        tree[pos] += (r - l + 1) * val;
        lazy[pos] += val;
        return;
    }
    int mid = l + ((r - l) >> 1);
    pushdown(pos, mid - l + 1, r - mid);
    if (mid >= x)   update(l, mid, x, y, pos << 1, val);
    if (mid < y)    update(mid+1, r, x, y, pos << 1 | 1, val);
    tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];
}

ll query (int l, int r, int x, int y, int pos) {
    if (y < l || x > r)
        return 0;
    if (l >= x && y >= r) 
        return tree[pos];
    int mid = l + ((r - l) >> 1);
    pushdown(pos, mid - l + 1, r - mid);
    ll ans_l = query(l, mid, x, y, pos << 1);
    ll ans_r = query(mid + 1, r, x, y, pos << 1 | 1);
    return ans_l + ans_r;
}

int main() {
    scanf("%d%d",&n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d",dat + i);
    }
    build(1, n, 1);
    int order;
    int l, r, k;
    while(m--) {
        scanf("%d",&order);
        if(order == 1) {
            scanf("%d%d%d",&l,&r,&k);
            update(1, n, l, r, 1, k);
        } else {
            scanf("%d%d",&l,&r);
            printf("%lld\n",query(1, n, l, r, 1));
        }
    }
}