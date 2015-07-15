/*************************************************************************
    > File Name: LightOJ1319.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年07月15日 星期三 21时52分29秒
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
 
LL exgcd(LL a, LL b, LL &x, LL &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    LL gcd = exgcd(b, a % b, x, y);
    LL t = x;
    x = y;
    y = t - (a / b) * x;
    return gcd;
}
 
LL inverse(LL num, LL mod) {
    LL x, y;
    exgcd(num, mod, x, y);
    return (x % mod + mod) % mod;
}
 
struct node {
    LL ai;
    LL pi;
}que[20];
 
LL CRT(int n) {
    LL M = 1;
    for (int i = 1; i <= n; ++i) {
        M *= que[i].pi;
    }
    LL ret = 0;
    for (int i = 1; i <= n; ++i) {
        LL inv = inverse(M / que[i].pi, que[i].pi);
        ret = (ret + M / que[i].pi * inv * que[i].ai) % M;
    }
    return ret;
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld%lld", &que[i].pi, &que[i].ai);
        }
        LL ans = CRT(n);
        printf("Case %d: %lld\n", icase++, ans);
    }
    return 0;
}
