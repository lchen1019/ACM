#include<cstdio>
#include<utility>
using namespace std;
#define N 10005

int n, base;
int a[N];
int pos;

void out() {
    for(int i=pos-1;i>=0;i--){
        if(a[i] >= 0 && a[i] <= 9) printf("%c",'0' + a[i]);
        else printf("%c",'A' + a[i] - 10);
    }
}

pair<int,int> div(int val) {
    int t = val / base;
    if(val - t * base >= 0) {
        return make_pair(t, val - t * base);
    } else {
        return make_pair(t + 1, val - t * base - base);
    }
}

int main() {
    scanf("%d%d",&n, &base);
    printf("%d=",n);
    while(true) {
        pair<int,int> t = div(n);
        n = t.first;
        a[pos++] = t.second;
        if(t.first == 0) break;
    }
    out();
    printf("(base%d)\n",base);
}