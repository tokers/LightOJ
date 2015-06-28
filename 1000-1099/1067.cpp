/*************************************************************************
    > File Name: LightOJ1067.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年06月28日 星期日 20时45分04秒
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
 
static const int mod = 1000003;
int fac[1001100];
 
int extend_gcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    int gcd = extend_gcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - (a / b) * x;
}
 
int get_inverse(int num) {
    int x, y;
    extend_gcd(num, mod, x, y);
    return (x % mod + mod) % mod;
}
 
int Combine(int n, int m) {
    int t2 = (LL)fac[m] * fac[n - m] % mod;
    int t1 = fac[n];
    return (LL)t1 * get_inverse(t2) % mod;
}
 
int main() {
    int t, icase = 1;
    fac[0] = 1;
    fac[1] = 1;
    for (int i = 2; i <= 1000000; ++i) {
        fac[i] = (LL)fac[i - 1] * i % mod;
    }
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        printf("Case %d: %d\n", icase++, Combine(n, k));
    }
    return 0;
}
