/*************************************************************************
    > File Name: LightOJ1188.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年08月05日 星期三 18时57分30秒
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
 
struct Modui {
    int l, r, bid, id;
    bool operator < (const Modui &b) const {
        if (bid == b.bid) {
            return r < b.r;
        }
        return bid < b.bid;
    }
}que[50010];
 
int vis[100010];
int lastl, lastr;
int Arr[100010];
int ans[50010];
int res;
 
int query(int l, int r, int id) {
    if (id == 1) {
        for (int i = l; i <= r; ++i) {
            if (!vis[Arr[i]]) {
                ++res;
            }
            ++vis[Arr[i]];
        }
    }
    else {
        for (int i = lastl; i < l; ++i) {
            --vis[Arr[i]];
            if (!vis[Arr[i]]) {
                --res;
            }
        }
        for (int i = l; i < lastl; ++i) {
            if (!vis[Arr[i]]) {
                ++res;
            }
            ++vis[Arr[i]];
        }
        for (int i = r + 1; i <= lastr; ++i) {
            --vis[Arr[i]];
            if (!vis[Arr[i]]) {
                --res;
            }
        }
        for (int i = lastr + 1; i <= r; ++i) {
            if (!vis[Arr[i]]) {
                ++res;
            }
            ++vis[Arr[i]];
        }
    }
    lastl = l;
    lastr = r;
    return res;
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n, q;
        scanf("%d%d", &n, &q);
        int bsize = sqrt(n * 1.0);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &Arr[i]);
        }
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= q; ++i) {
            scanf("%d%d", &que[i].l, &que[i].r);
            que[i].bid = que[i].l / bsize;
            que[i].id = i;
        }
        sort(que + 1, que + 1 + q);
        res = 0;
        printf("Case %d:\n", icase++);
        for (int i = 1; i <= q; ++i) {
            ans[que[i].id] = query(que[i].l, que[i].r, i);
        }
        for (int i = 1; i <= q; ++i) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
