/*************************************************************************
    > File Name: LightOJ1048.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年06月26日 星期五 20时02分59秒
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
 
const int N = 1010;
int dist[N];
int n, k;
int sum[N];
int res;
 
bool judge(int n, int m, int maxs) {
    int zu = 1;
    int use = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] > maxs) {
            return 0;
        }
        if (use + dist[i] <= maxs) {
            use += dist[i];
        }
        else {
            ++zu;
            use = dist[i];
        }
    }
    return zu <= m;
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        ++n;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &dist[i]);
        }
        sum[n + 1] = 0;
        for (int i = n; i >= 1; --i) {
            sum[i] = sum[i + 1] + dist[i];
        }
        res = -1;
        int l = 1, r = 10000000, mid;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (judge(n, k + 1, mid)) {
                res = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        int need = k + 1;
        printf("Case %d: %d\n", icase++, res);
        for (int i = 1; i <= n;) {
            int d = 0;
            while (i <= n && d + dist[i] <= res && (need - 1) <= (n - i)) {
                d += dist[i];
                ++i;
            }
            --need;
            printf("%d\n", d);
            if (need == 0) {
                break;
            }
        }
    }
    return 0;
}
