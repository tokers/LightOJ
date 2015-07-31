/*************************************************************************
    > File Name: LightOJ1166.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年07月31日 星期五 09时40分49秒
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
 
int Arr[110];
int fa[110];
int vis[110];
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n;
        memset(vis, 0, sizeof(vis));
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &Arr[i]);
            fa[Arr[i]] = i;
        }
        int ans = 0;
        while (1) {
            int u = -1;
            for (int i = 1; i <= n; ++i) {
                if (!vis[i]) {
                    u = Arr[i];
                    vis[u] = 1;
                    break;
                }
            }
            if (u == -1) {
                break;
            }
            int uu = fa[u];
            int cnt = 1;
            while (uu != u) {
                ++cnt;
                vis[uu] = 1;
                uu = fa[uu];
            }
            ans += cnt - 1;
        }
        printf("Case %d: %d\n", icase++, ans);
    }
    return 0;
}
