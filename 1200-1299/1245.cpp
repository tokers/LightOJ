/*************************************************************************
    > File Name: LightOJ1245.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年07月11日 星期六 18时06分32秒
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
        int n;
        scanf("%d", &n);
        LL ans = 0;
        for (int i = 1; (LL)i * i <= n; ++i) {
            if (n / i != i) {
                ans += n / i;
                int l = n / (i + 1) + 1;
                int r = n / i;
                ans += (r - l + 1) * i;
            }
            else {
                ans += n / i;
            }
        }
        printf("Case %d: %lld\n", icase++, ans);
    }
    return 0;
}
