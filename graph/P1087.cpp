#include <cstdio>
using namespace std;
#define N 5005

int n;
char s[N];
char r[N];
int pos;

char build(int left, int right) {
    if (left == right) {
        r[pos++] = s[left] == '0' ? 'B' : 'I';
        return r[pos - 1];
    }
    int mid = left + ((right - left) >> 1);
    char lef = build(left, mid);
    char righ = build(mid + 1, right);
    if (lef == righ) {
        r[pos++] = lef;
    } else {
        r[pos++] = 'F';
    }
    return r[pos - 1];
}

int main() {
    scanf("%d", &n);
    scanf("%s", s);
    n = 1 << n;
    build(0, n - 1);
    printf("%s\n",r);
}