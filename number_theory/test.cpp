#include<cstdio>
#include<map>
using namespace std;

int main() {
    map<int,int> p;
    p[1] = 1;
    p[2] = 2;
    printf("%d",p[3]);
    printf("%d",p[4]);
    printf("%d",p[5]);
    printf("%d",p[6]);
    printf("%d",p[7]);
    printf("%d\n",p.size());
    printf("%d\n",p.find(8));
    printf("%d\n",p.size());
    
}