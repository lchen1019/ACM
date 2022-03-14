// Miller-Rabin 算法生成大素数
#include <cstdio>
#include <ctime>
#include <iostream>
#include <utility>
using namespace std;
typedef unsigned long long ull;

const int k = 100;  // 安全参数


// 随机数发生器
ull great_random() {
    ull ans = rand() * rand() * (rand() % 13) + rand() * (rand() % 11);
    return ans;
}

pair<ull,ull> break_down(ull n) {
    ull s = 0;
    while (!(n & 1)) {
        ++s;
        n >>= 1;
    }
    return make_pair(s, n);
}

ull fast_pow(ull a, ull b, ull mod) {
    ull res = 1, x = a;
    while (b) {
        if (b & 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    srand(time(0));
    while(true) {
        ull n = great_random(); // 生成待检验的大素数
        if (n % 2 == 0) continue;
        printf("产生的打随机数为: %llu\n", n);
        bool is = true;
        // 分解n - 1
        pair<ull, ull> b = break_down(n - 1);
        ull s = b.first, t = b.second;
        printf("s = %llu,t = %llu\n", s, t);
        // k次Fermat检验
        int time = 0;
        while(time < k) {
            ull m = rand() % n;
            if (m < 2 || m == n - 1)    continue;
            // printf("第%d次检验数据为%llu\n",time+1, m);
            bool satisfy = false;
            int time_s = 0;
            ull x = fast_pow(m, t, n);
            // printf("%llu\n",x);
            if(x == (ull)1 || x == (ull)(n - 1)) {
                time++;
                continue;
            }
            // 每一次检验都要做 s 次
            while(time_s < s) {
                x = x * x % n;
                // printf("x = %llu\n",x);
                if (x == (ull)(n - 1)){
                    satisfy = true;
                    break;
                }
                time_s++;   
            }
            if (!satisfy) {
                is = false;
                break;
            }
            time++;
        }
        if (is) {
            printf("************%llu***************\n",n);
        }
        // break;
    }
}