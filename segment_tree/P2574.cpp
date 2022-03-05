#include <cstdio>
using namespace std;
#define N 200005

int n,m;
char a[N];
int dat[N];
int tree[N << 2], lazy[N << 2];

inline void getup(int pos) {
    tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];
}

void build(int l,int r,int pos) {
    // 到达叶子节点
    if(l == r) {
        tree[pos] = a[l - 1] - '0';
        return;
    }
    int mid = l + ((r - l) >> 1);
    build(l, mid,pos << 1);
    build(mid + 1,r,pos << 1 | 1);
    getup(pos);
}

void pushdown(int len, int pos) {
    if(lazy[pos]) {
        lazy[pos << 1] ^= 1;
        lazy[pos << 1 | 1] ^= 1;
        tree[pos << 1] =  (len - (len >> 1)) - tree[pos << 1];
        tree[pos << 1 | 1] =  (len >> 1) - tree[pos << 1 | 1];
        lazy[pos] = 0;
    }
}

int query(int L,int R,int l,int r,int pos) {
    if(L <= l && r <= R) {
        return tree[pos];
    }
    if(r < L || l > R) {
        return 0;
    }
    // 标记下放
    pushdown(r - l + 1, pos);
    int mid = l + ((r - l) >> 1);
    int left = query(L,R,l,mid,pos << 1);
    int right = query(L,R,mid+1,r,pos << 1 | 1);
    return left + right;
}

void update(int L,int R,int l,int r,int pos) {
    if(L <= l && r <= R){
        lazy[pos] ^= 1;
        tree[pos] = (r - l + 1) - tree[pos];
        return;
    }
    pushdown(r - l + 1, pos);
    if(r < L || l > R) return;
    int mid = l + ((r - l) >> 1);
    update(L,R,l,mid,pos << 1);
    update(L,R,mid+1,r,pos << 1 | 1);
    getup(pos);
}

int main() {
    freopen("in.in","rw",stdin);
    scanf("%d%d",&n,&m);
    scanf("%s",a);
    build(1,n,1);
    int op,l,r;
    while(m--) {
        scanf("%d%d%d",&op,&l,&r);
        if(op == 1) {
            printf("%d\n",query(l,r,1,n,1));
        } else {
            update(l,r,1,n,1);
        }
    }
}