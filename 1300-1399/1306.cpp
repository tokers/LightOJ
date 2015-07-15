/*************************************************************************
    > File Name: LightOJ1306.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年07月15日 星期三 21时25分44秒
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
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        LL a, b, c, x1, x2, y1, y2;
        scanf("%lld%lld%lld%lld%lld%lld%lld", &a, &b, &c, &x1, &x2, &y1, &y2);
        LL ans = 0;
        if (a == 0 && b == 0) {
            if (c == 0) {
                ans = (x2 - x1 + 1) * (y2 - y1 + 1);
            }
            else {
                ans = 0;
            }
        }
        else if (a == 0) {
            if (c % b == 0 && y1 <= (-c / b) && (-c / b) <= y2) {
                ans = (x2 - x1 + 1);
            }
            else {
                ans = 0;
            }
        }
        else if (b == 0) {
            if (c % a == 0 && x1 <= (-c / a) && (-c / a) <= x2) {
                ans = (y2 - y1 + 1);
            }
            else {
                ans = 0;
            }
        }
        else {
            LL x, y;
            LL gcd = exgcd(a, b, x, y);
            if (c % gcd) {
                ans = 0;
            }
            else {
                LL beishu = -c / gcd;
                b /= gcd;
                a /= gcd;
                x *= beishu;
                y *= beishu;
                double l = -(double)(1LL << 50), r = (double)(1LL << 50);
                if (b > 0) {
                    r = min(r, floor((x2 - x) * 1.0 / b));
                    l = max(l, ceil((x1 - x) * 1.0 / b));
                }
                else {
                    l = max(l, ceil((x2 - x) * 1.0 / b));
                    r = min(r, floor((x1 - x) * 1.0 /b));
                }
                if (a > 0) {
                    l = max(l, ceil((y - y2) * 1.0 / a));
                    r = min(r, floor((y - y1) * 1.0 / a));
                }
                else {
                    r = min(r, floor((y - y2) * 1.0 / a));
                    l = max(l, ceil((y - y1) * 1.0 / a));
                }
                ans = max((LL)r - (LL)l + 1, 0LL);
            }
        }
        printf("Case %d: %lld\n", icase++, ans);
    }
    return 0;
}
