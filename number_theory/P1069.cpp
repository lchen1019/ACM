#include<cstdio>
#include<map>
using namespace std;
#define N 10005
typedef long long ll;

int n;
int m1, m2;
int num[N];
map<int,int> m;
map<int,int> p[N];

void factorize(map<int,int> &p, int n) {
    for(int i = 2;i * i <= n;i++) {
        while(n % i == 0) {
            p[i]++;
            n /= i;
        }
    }
    if(n > 1)   p[n]++;
}

int main() {
    scanf("%d%d%d",&n,&m1,&m2);
    if(m1 == 1 && m2 == 1) {
        printf("0\n");
        return 0;
    }
    for(int i=0;i<n;i++)    scanf("%d",&num[i]);
    factorize(m, m1);
    for(auto &it : m) {
        it.second *= m2;
    }
    for(int i=0;i<n;i++) {
        factorize(p[i], num[i]);
    }
    ll res = 0x7ffffffff;
    auto last = m.end();
    for(int i = 0;i < n; i++) {
        ll temp = -1;
        bool could = true;
        for(auto it : m) {
            auto a = p[i].find(it.first);
            if(a->second == 0) {
                could = false;
                break;
            }
            if(a != last) {
                ll k = it.second % a->second ? it.second / a->second + 1 : it.second / a->second;
                temp = temp > k ? temp : k;
            } else {
                break;
                could = false;
            }
        }
        if (could) res = res > temp ? temp : res;
    }
    printf("%lld\n",res == 0x7ffffffff ? -1 : res);
}