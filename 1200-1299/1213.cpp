/*************************************************************************
    > File Name: LightOJ1213.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年07月12日 星期日 10时08分07秒
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
 
int fastpow(int a, int cnt, int mod) {
    LL ret = 1;
    a %= mod;
    while (cnt) {
        if (cnt & 1) {
            ret = ret * a % mod;
        }
        cnt >>= 1;
        a = (LL)a * a % mod;
    }
    return ret;
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int ans = 0, u, n, k, mod;
        LL sum = 0;
        scanf("%d%d%d", &n, &k, &mod);
        LL ret = fastpow(n, k - 1, mod);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &u);
            u %= mod;
            sum += u;
            sum %= mod;
        }
        sum *= ret;
        sum %= mod;
        sum *= k;
        sum %= mod;
        printf("Case %d: %lld\n", icase++, sum);
    }
    return 0;
}
