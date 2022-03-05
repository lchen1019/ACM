#include<cstdio>
#include<queue>
using namespace std;
#define N 200005

int n;
int a[N];
bool show[N];
bool sex[N];
pair<int,int> arr[N];
struct Neighbor {
    int cur,next;
    int dif;
};

bool operator > (const Neighbor &a,const Neighbor &b) {
    if(a.dif != b.dif)
        return a.dif > b.dif;
    return a.cur > b.cur;
}

priority_queue<Neighbor,vector<Neighbor>,greater<Neighbor> > q;

int main() {
    scanf("%d",&n);
    char temp[N];
    scanf("%s",temp + 1);
    for(int i=1;i<=n;i++){
        if(temp[i] == 'B')  sex[i] = false;
        else sex[i] = true;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    // 遍历一遍
    for(int i=1;i<n;i++){
        if(sex[i] ^ sex[i + 1]){
            Neighbor b;
            b.cur = i;
            b.next = i + 1;
            int temp = a[i] - a[i + 1];
            b.dif = temp > 0 ? temp : -temp;
            q.push(b);
        }
    }
    int tot = 0;
    while(!q.empty()) {
        Neighbor top = q.top();
        q.pop();
        if(show[top.cur] || show[top.next])
            continue;
        show[top.cur] = show[top.next] = true;
        // 从top.cur - 1 到 top.next + 1
        int pre = top.cur - 1;
        int next = top.next + 1;
        while(show[pre] && pre >= 1) pre--;
        while(show[next] && next <= n) next++;
        if(pre >= 1 && next <= n) {
            if(sex[pre] ^ sex[next]) {
                Neighbor b;
                b.cur = pre;
                b.next = next;
                int temp = a[pre] - a[next];
                b.dif = temp > 0 ? temp : -temp;
                q.push(b);
            }
        }
        arr[tot++] = make_pair(top.cur,top.next);
    }
    printf("%d\n",tot);
    for(int i=0;i<tot;i++){
        printf("%d %d\n",arr[i].first,arr[i].second);
    }
}