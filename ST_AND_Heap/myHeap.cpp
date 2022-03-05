#include <cstdio>
#include <iostream>
using namespace std;
#define N 100005
typedef long long ll;

ll n;
ll a[N];
ll last;

void swap(ll& a, ll& b) {
    ll p = a;
    a = b;
    b = p;
}

void pushdown(int pos) {
    while(2 * pos <= last) {
        int left = 2 *pos;
        int right = 2*pos + 1;
        int k = left;
        if(right <= n && a[left] > a[right])    k = right;
        if(a[k] < a[pos])   swap(a[k],a[pos]);
        pos = k;
    }
}

void init() {
    ll start = n / 2;
    for (ll i = start; i >= 1; i--) {
        ll pos = i;
        ll left = 2 * pos;
        ll right = 2 * pos + 1;
        int k = left;
        if(right <= last && a[left] > a[right]) k = right;
        swap(a[k],a[pos]);
        pushdown(k);
    }
}

inline ll top() {
    return a[1];
}

inline void pop() {
    swap(a[1], a[last]);
    --last;
    // 下沉
    ll pos = 1;
    pushdown(pos);
}

int main() {
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++) {
        scanf("%lld", a + i);
    }
    last = n;
    init();
    ll max = (n + 1) / 2;
    for (ll i = 1; i <= max; i++) {
        printf("%lld\n", top());
        pop();
    }
}