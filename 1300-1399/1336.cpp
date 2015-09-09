/*************************************************************************
    > File Name: LightOJ1336.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年07月13日 星期一 14时46分20秒
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
 
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        LL n, ans = 0;
        scanf("%lld", &n);
        for (int i = 1; (LL)i * i <= n; ++i) {
            if (i & 1) {
                int cnt = 0;
                LL u = n / i / i;
                while (u >= 2) {
                    ++cnt;
                    u /= 2;
                }
                ans += cnt + 1;
            }
        }
        ans = n - ans;
        printf("Case %d: %lld\n", icase++, ans);
    }
    return 0;
}
