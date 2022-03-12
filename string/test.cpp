#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 19930726;
const int N = 1100000;
char s[N],str[N*2];
int p[N*2],cnt[N];
int len,n;
ll ans=1,k;
ll ksm(int x,int y) {//因为数据范围很大容易爆掉，所以就要Fast_Pow
    if(x==1) return 1;
    ll res=1,base=x;
    while(y) {
        if(y&1) res=(res*base)%mod;
        base=(base*base)%mod;
        y>>=1;
    }
    return res;
}
void manacher() {//Manacher模板，详见洛谷P3805
    for(int i=1; i<=len; i++) str[i*2-1]='%',str[i*2]=s[i];
    str[len=len*2+1]='%';
    int id=0,mx=0;
    for(int i=1; i<=len; i++) {
        if(i<mx) p[i]=min(p[id*2-i],mx-i);
        else p[i]=1;
        while(p[i]+i<=len && i-p[i]>=1 && str[i+p[i]]==str[i-p[i]]) p[i]++;
        if(p[i]+i>mx) id=i,mx=i+p[i];
        if((p[i]-1)%2){
			 cnt[p[i]-1]++;
			printf("%d\n",p[i] - 1);
		}
    }
}
int main() {
    int sum=0;
    cin>>n>>k>>s+1;
    len=n;
    manacher();
    for(int i=n; i>=1; --i) {//根据题意常规操作
        if(i%2==0) continue;
		printf("%d  %d\n",i,cnt[i]);
        sum+=cnt[i];
        if(k>=sum) {
            ans=(ans*ksm(i,sum))%mod;
            k-=sum;
        } else {
            ans=(ans*ksm(i,k))%mod;
            k-=sum;
            break;
        }
    }
    if(k>0) ans=-1;
    cout<<ans;
    return 0;
}