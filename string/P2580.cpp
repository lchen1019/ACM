#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;
#define N 10005

int n, m;
map<string,int> p;

int main() {
    scanf("%d",&n);
    string temp;
    getline(cin, temp);
    for (int i = 0; i < n; i++) {
        getline(cin, temp);
        p[temp] = 0;
    }
    auto last = p.end();
    scanf("%d",&m);
    getline(cin, temp);
    while(m--) {
        getline(cin, temp);
        auto ans = p.find(temp);
        if (ans != last) {
            if (ans->second == 0) {
                printf("OK\n");
                ans->second = 1;
            } else {
                printf("REPEAT\n");
            }
        } else {
            printf("WRONG\n");
        }
    }
}