/*************************************************************************
    > File Name: LightOJ1099.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年08月24日 星期一 12时39分31秒
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
 
const int N = 5050;
int dist[N];
int dist2[N];
struct Edge {
    int nxt;
    int to;
    int w;
}edge[200010];
int head[N], tot;
 
void addedge(int from, int to, int w) {
    edge[tot].to = to;
    edge[tot].nxt = head[from];
    edge[tot].w = w;
    head[from] = tot++;
}
 
priority_queue <PLL, vector<PLL>, greater<PLL> > qu;
 
void dijkstra(int s) {
    fill(dist, dist + N, inf);
    fill(dist2, dist2 + N, inf);
    dist[s] = 0;
    while (!qu.empty()) {
        qu.pop();
    }
    qu.push(make_pair(0, s));
    while (!qu.empty()) {
        PLL now = qu.top();
        qu.pop();
        int u = now.second;
        int d = now.first;
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if (d + edge[i].w < dist[v]) {
                dist2[v] = dist[v];
                dist[v] = d + edge[i].w;
                qu.push(make_pair(dist[v], v));
            }
            else if (dist[v] < d + edge[i].w && dist2[v] > d + edge[i].w) {
                dist2[v] = d + edge[i].w;
                qu.push(make_pair(dist2[v], v));
            }
        }
    }
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m, u, v, w;
        scanf("%d%d", &n, &m);
        fill(head, head + N, -1);
        tot = 0;
        for (int i = 1; i <= m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            addedge(u, v, w);
            addedge(v, u, w);
        }
        dijkstra(1);
        printf("Case %d: %d\n", icase++, dist2[n]);
    }
    return 0;
}
