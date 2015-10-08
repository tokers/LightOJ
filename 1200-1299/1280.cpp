/*************************************************************************
    > File Name: LightOJ1280.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年10月08日 星期四 13时40分05秒
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
 
const int N = 20010;
PLL sc[N];
double b[N];
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n, d;
        scanf("%d%d", &n, &d);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &sc[i].first, &sc[i].second);
        }
        double l = 0, r = 1.0, mid, ans = 0.0;
        while (r - l >= eps) {
            mid = (l + r) / 2;
            for (int i = 1; i <= n; ++i) {
                b[i] = sc[i].first * 1.0 - mid * sc[i].second;
            }
            sort(b + 1, b + n + 1);
            double val = 0;
            for (int i = n; i > d; --i) {
                val += b[i];
            }
            if (val >= eps) {
                ans = mid;
                l = mid;
            }
            else {
                r = mid;
            }
        }
        printf("Case %d: %.12f\n", icase++, ans * 100);
    }
    return 0;
}
