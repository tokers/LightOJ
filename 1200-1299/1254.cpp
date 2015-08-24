/*************************************************************************
    > File Name: LightOJ1254.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年08月24日 星期一 13时59分05秒
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
 
const int N = 110;
int dist[N][N];
int price[N];
struct Edge {
    int from;
    int to;
    int w;
    int nxt;
}edge[2010];
int head[N];
int tot;
queue <PLL> qu;
 
void addedge(int from, int to, int w) {
    edge[tot].to = to;
    edge[tot].w = w;
    edge[tot].nxt = head[from];
    head[from] = tot++;
}
 
void spfa(int s, int c, int t) {
    memset(dist, inf, sizeof(dist));
    dist[s][0] = 0;
    while (!qu.empty()) {
        qu.pop();
    }
    qu.push(make_pair(s, 0));
    while (!qu.empty()) {
        PLL now = qu.front();
        qu.pop();
        int u = now.first;
        int rest = now.second;
        if (u == t) {
            continue;
        }
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if (rest >= edge[i].w && dist[v][rest - edge[i].w] > dist[u][rest]) {
                dist[v][rest - edge[i].w] = dist[u][rest];
                qu.push(make_pair(v, rest - edge[i].w));
            }
        }
        if (rest < c && dist[u][rest + 1] > dist[u][rest] + price[u]) {
            qu.push(make_pair(u, rest + 1));
            dist[u][rest + 1] = dist[u][rest] + price[u];
        }
    }
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m, u, v, w, q, c;
        scanf("%d%d", &n, &m);
        memset(head, -1, sizeof(head));
        tot = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &price[i]);
        }
        for (int i = 1; i <= m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            addedge(u, v, w);
            addedge(v, u, w);
        }
        scanf("%d", &q);
        printf("Case %d:\n", icase++);
        while (q--) {
            scanf("%d%d%d", &c, &u, &v);
            spfa(u, c, v);
            int ans = inf;
            for (int i = 0; i <= c; ++i) {
                ans = min(ans, dist[v][i]);
            }
            if (ans == inf) {
                printf("impossible\n");
            }
            else {
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
