#include <cstdio>
using namespace std;

int n;
int a, b;
bool ans;

int main() {
    scanf("%d",&n);
    while(n--) {
        scanf("%d%d",&a, &b);
        ans = false;
        if (a < b) {
            int p = a;
            a = b;
            b = p;
        }
        while (a && b) {
            int t = a % b;
            t += b;
            a = b;
            b = t;
            ans = !ans;
        }
        if (ans) {
            printf("Stan wins\n");
        } else {
            printf("Ollie wins\n");
        }
    }
}