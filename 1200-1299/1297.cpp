/*************************************************************************
    > File Name: LightOJ1297.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年07月16日 星期四 14时10分08秒
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
        double L, W;
        scanf("%lf%lf", &L, &W);
        double x1 = (L + W + sqrt(L * L + W * W - L * W)) / 6;
        double x2 = (L + W - sqrt(L * L + W * W - L * W)) / 6;
        double ans = (L - 2 * x1) * (W - 2 * x1) * x1;
        ans = max(ans, (L - 2 * x2) * (W - 2 * x2) * x2);
        printf("Case %d: %.12f\n", icase++, ans);
    }
    return 0;
}
