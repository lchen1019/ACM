#include <cstdio>
using namespace std;
#define N 300005

int M, S, T;

int main() {
    scanf("%d%d%d", &M, &S, &T);
    int pos = 0;
    for (int i = 1; i <= T; i++) {
        int need = (10 - M) % 4 == 0 ? (10 - M) / 4 : (10 - M) / 4 + 1;
        if (M >= 10) {
            pos += 60;
            M -= 10;
        } else if ((need + 1) * 17 >= S - pos) {
            pos += 17;
        } else if (need <= T - i) {
            M += 4;
        } else {
            pos += 17;
        }
        if (pos >= S) {
            printf("Yes\n");
            printf("%d\n", i);
            return 0;
        }
    }
    printf("No\n%d\n", pos);
}