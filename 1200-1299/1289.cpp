/*************************************************************************
    > File Name: LightOJ1289.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年07月16日 星期四 16时19分41秒
 ************************************************************************/
 
#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <functional>
#include <algorithm>
 
using namespace std;
 
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> PLL;
const LL INF = (1LL << 60);
 
const int N = 5900000;
unsigned int sum[N];
int prime[N];
int valid[3400000];
int tot;
 
void getprime() {
    int n = 100000007;
    tot = 0;
    for (int i = 0; i < 3400000; ++i) {
        valid[i] = ((1 << 30) - 1);
    }
    valid[0] ^= 1;
    valid[0] ^= 2;
    for (int i = 2; i <= n; ++i) {
        int id1 = i / 30;
        int id2 = i % 30;
        if (valid[id1] & (1 << id2)) {
            if (n / i < i) {
                break;
            }
            for (int j = i * i; j <= n; j += i) {
                id1 = j / 30;
                id2 = j % 30;
                if (valid[id1] & (1 << id2)) {
                    valid[id1] ^= (1 << id2);
                }
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        int id1 = i / 30;
        int id2 = i % 30;
        if (valid[id1] & (1 << id2)) {
            prime[++tot] = i;
        }
    }
}
 
int main() {
    getprime();
    sum[0] = 1;
    for (int i = 1; i <= tot; ++i) {
        sum[i] = sum[i - 1] * prime[i];
    }
    int icase = 1, t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        unsigned int lcm = 1;
        int p = lower_bound(prime + 1, prime + 1 + tot, n) - prime;
        if (prime[p] != n) {
            --p;
        }
        lcm *= sum[p];
        for (int i = 1; i <= tot &&  prime[i] <= n / prime[i]; ++i) {
			int tmp = n;
			unsigned int ans = 1;
			while (tmp >= prime[i]) {
				tmp /= prime[i];
				ans *= prime[i];
			}
			lcm *= ans / prime[i];
        }
        printf("Case %d: %u\n", icase++, lcm);
    }
    return 0;
}
