/*************************************************************************
    > File Name: LightOJ1161.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年08月08日 星期六 13时39分30秒
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
 
int cnt[10010];
vector <int> fac;
 
int main() {
    int t, icase = 1, n, u;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &u);
            fac.clear();
            for (int j = 2; j * j <= u; ++j) {
                if (u % j == 0) {
                    fac.push_back(j);
                    while (u % j == 0) {
                        u /= j;
                    }
                }
            }
            if (u > 1) {
                fac.push_back(u);
            }
            int size = fac.size();
            for (int j = 0; j < (1 << size); ++j) {
                int u = 1;
                for (int k = 0; k < size; ++k) {
                    if (j & (1 << k)) {
                        u *= fac[k];
                    }
                }
                ++cnt[u];
            }
        }
        LL ans = (LL)n * (n - 1) * (n - 2) * (n - 3) / 24;
        for (int i = 2; i <= 10000; ++i) {
            if (cnt[i] < 4) {
                continue;
            }
            int u = i, ret = 0;
            for (int j = 2; j * j <= u; ++j) {
                if (u % j == 0) {
                    ++ret;
                    while (u % j == 0) {
                        u /= j;
                    }
                }
            }
            if (u > 1) {
                ++ret;
            }
            int sgn = 1;
            if (ret & 1) {
                sgn = -1;
            }
            ans += sgn * (LL)cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) * (cnt[i] - 3) / 24;
        }
        printf("Case %d: %lld\n", icase++, ans);
    }
    return 0;
}
