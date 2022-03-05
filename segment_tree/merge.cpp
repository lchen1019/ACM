#include<cstdio>
#include<ctime>
#include<iostream>
#include<cstring>
using namespace std;
#define N 500005

int n;
int a[N];
int l[N], r[N];
long long tot;

void out() {
    for(int i=0;i<n;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void merge(int left, int right) {
    int mid = left + ((right - left) >> 1);
    int nl = mid - left + 1;
    int nr = right - mid;
    for(int i = 0; i < nl; i++) l[i] = a[i + left];
    for(int i = 0; i < nr; i++) r[i] = a[i + mid + 1];
    l[nl] = r[nr] = 0x7fffffff;
    int pos_l = 0, pos_r = 0, pos = 0;
    while(pos <= right - left) {
        if(l[pos_l] <= r[pos_r]){
            a[pos + left] = l[pos_l++];
        } else{
            tot += (nl - pos_l);
            a[pos + left] = r[pos_r++];
        }
        ++pos;
    }
}

void merge_sort(int left, int right) {
    if(left >= right) return;
    int mid = left + ((right - left) >> 1);
    merge_sort(left, mid);
    merge_sort(mid + 1,right);
    merge(left, right);
}



int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    merge_sort(0, n - 1);
    printf("%lld\n",tot);
}