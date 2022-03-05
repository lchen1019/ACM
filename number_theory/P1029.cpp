// 基于算术基本定理
#include <cstdio>
#include <map>
#include<iterator>
using namespace std;
#define N 100005
typedef long long ll;

void factorize(map<int,int> &p, int n) {
    int temp = n;
    for (int i = 2; i * i <= temp; i++) {
        // 更新其所有因子
        while (n % i == 0) {
            p[i]++;
            n /= i;
        }
    }
    if(n != 1) p[n]++;
}

int main() {
    map<int,int> p, q;
    int m, n;
    scanf("%d%d",&m,&n);
    if(n % m != 0) {
        printf("0\n");
        return 0;
    }
    factorize(p, m);
    factorize(q, n);
    int same = 0;
    int un = 0;
    map<int,int>::iterator last = q.end();
    for(auto &it : p) {
        map<int,int>::iterator a = q.find(it.first);
        if(a != last && a->second == it.second) ++same;
        if(a == last) ++un;
    }
    long long res = 1 << (q.size() + un - same);
    printf("%lld\n",res);
}