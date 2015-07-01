/*************************************************************************
    > File Name: LightOJ1062.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年07月01日 星期三 21时32分14秒
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
const double eps = 1e-12;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> PLL;
const LL INF = (1LL << 60);
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        double a, b, c;
        scanf("%lf%lf%lf", &a, &b, &c);
        double mid, l = 0, r = min(a, b);
        double ans = 0.0;
        while (r - l >= eps) {
            mid = (l + r) / 2;
            double res = c / sqrt(a * a - mid * mid) + c / sqrt(b * b - mid * mid);
            if (res - 1 > eps) {
                r = mid;
            }
            else if (res - 1 < -eps) {
                l = mid;
            }
            else {
                ans = mid;
                break;
            }
        }
        printf("Case %d: %.12f\n", icase++, ans);
    }
    return 0;
}
