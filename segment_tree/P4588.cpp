#include<cstdio>
#include<cstring>
using namespace std;
#define N 100005
typedef long long ll;

int t;
int q,mod;
ll tree[N << 2];

void update(int l,int r,int val,int k,int pos) {
    int mid = l + ((r - l) >> 1);
    if(l == r) {
        tree[pos] = val % mod;
        return;
    }
    if(k <= mid) update(l,mid,val,k,pos << 1);
    if(k > mid) update(mid+1,r,val,k,pos << 1 | 1);
    tree[pos] = (tree[pos << 1] * tree[pos << 1 | 1]) % mod; 
}

int main() {
    scanf("%d",&t);
    while(t--) {
        memset(tree,0,sizeof(tree));
        scanf("%d%d",&q,&mod);
        for(int i=1;i< (q << 2);i++) tree[i] = 1;
        int op,m;
        for(int i = 1; i <= q; i++) {
            scanf("%d%d",&op,&m);
            if(op == 1) {
                update(1,q,m,i,1);
            } else {
                update(1,q,1,m,1);
            }
            printf("%lld\n",tree[1] % mod);
        }
    }
}