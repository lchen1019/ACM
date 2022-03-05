#include<cstdio>
using namespace std;
#define N 500005

int n,m;
int tree[N << 2];
int lazy[N << 2];
int a[N];

void getup(int pos) {
    tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];
}

void build(int l,int r,int pos) {
    if(l == r) {
        tree[pos] = a[l];
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(l,mid,pos << 1);
    build(mid+1,r,pos << 1 | 1);
    getup(pos);
}

void pushdown(int nl, int nr, int pos) {
    if(lazy[pos]) {
        lazy[pos << 1] += lazy[pos];
        lazy[pos << 1 | 1] += lazy[pos];
        tree[pos << 1] += nl * lazy[pos];
        tree[pos << 1 | 1] += nr * lazy[pos];
        lazy[pos] = 0;
    }
}

void update(int L, int R, int l, int r, int val, int pos) {
    if(L <= l && r <= R) {
        lazy[pos] += val;
        tree[pos] += val * (r - l + 1);
        return;
    }
    int mid = l + ((r - l) >> 1);
    pushdown(mid - l + 1, r - mid, pos);
    if(mid >= L)    update(L, R, l, mid, val, pos << 1);
    if(R > mid)     update(L, R, mid+1, r, val, pos << 1 | 1);
    getup(pos);
}

int query(int L, int R, int l, int r, int pos) {
    if(L <= l && r <= R) {
        return tree[pos];
    }
    int mid = l + ((r - l) >> 1);
    pushdown(mid - l + 1, r - mid, pos);
    int ansl = 0, ansr = 0;
    if(mid >= L)    ansl = query(L, R, l, mid, pos << 1);
    if(mid < R)     ansr = query(L, R, mid+1,r,pos << 1 | 1);
    return ansl + ansr;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    build(1, n, 1);
    int op, x, y, add; 
    while(m--) {
        scanf("%d",&op);
        if(op == 1) {
            scanf("%d%d%d",&x,&y,&add);
            update(x, y, 1, n, add, 1);
        } else {
            scanf("%d",&x);
            printf("%d\n",query(x, x, 1, n, 1));
        }
    }
}