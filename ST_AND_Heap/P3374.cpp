// 线段树
#include <cstdio>
using namespace std;
#define N 500005

int n, m;
int a[N];
int tree[N << 2];

void getup(int pos) {
    tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];
}

void build(int l, int r, int pos) {
    if (l == r) {
        tree[pos] = a[l];
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(l, mid, pos << 1);
    build(mid + 1, r, pos << 1 | 1);
    getup(pos);
}

void update(int l, int r, int k, int val, int pos) {
    if (l == r) {
        tree[pos] += val;
        return;
    }
    int mid = l + ((r - l) >> 1);
    if(k <= mid) update(l, mid, k, val, pos << 1);
    else update(mid + 1, r, k, val, pos << 1 | 1);
    getup(pos);
}

int query(int L, int R,int l,int r,int pos) {
    // printf("%d %d %d %d\n",L,R,l,r);
    if(L <= l && r <= R) {
        return tree[pos];
    }
    int mid = l + ((r - l) >> 1);
    int ansl = 0,ansr = 0;
    if(mid >= L)   ansl = query(L, R, l, mid, pos << 1);
    if(mid < R)    ansr = query(L, R, mid+1, r, pos << 1 | 1);
    return ansl + ansr;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    build(1,n,1);
    int op, x, y;
    while (m--) {
        scanf("%d%d%d", &op, &x, &y);
        if (op == 1) {
            update(1,n,x,y,1);
        } else {
            printf("%d\n",query(x,y,1,n,1));
        }
    }
}