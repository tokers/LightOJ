/*************************************************************************
> File Name: LightOJ1002.cpp
> Author: ALex
> Mail: zchao1995@gmail.com
> Created Time: 2015年06月02日 星期二 19时34分01秒
************************************************************************/

#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <set>
#include <vector>

using namespace std;

const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef pair <int, int> PLL;

static const int N = 555;
int dist[N];
priority_queue < PLL, vector<PLL>, greater<PLL> > qu;
struct node {
int nxt;
int w;
int to;
}edge[40000];
bool vis[555];
int head[N], tot;

void addedge(int from, int to, int w) {
edge[tot].to = to;
edge[tot].w = w;
edge[tot].nxt = head[from];
head[from] = tot++;
}

void Dijkstra(int u, int n) {
while (!qu.empty()) {
    qu.pop();
}
for (int i = 0; i < n; ++i) {
    dist[i] = inf;
}
dist[u] = 0;
qu.push(make_pair(dist[u], u));
while (!qu.empty()) {
    PLL tmp = qu.top();
    qu.pop();
    int s = tmp.second;
    int d = tmp.first;
    for (int i = head[s]; ~i; i = edge[i].nxt) {
        int t = edge[i].to;
        int w = edge[i].w;
        if (dist[t] > max(d, w)) {
            dist[t] = max(d, w);
            qu.push(make_pair(dist[t], t));
        }
    }
}
}

int main() {
int t, icase = 1;
scanf("%d", &t);
while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        head[i] = -1;
    }
    tot = 0;
    int u, v, w;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        addedge(u, v, w);
        addedge(v, u, w);
    }
    scanf("%d", &u);
    Dijkstra(u, n);
    printf("Case %d:\n", icase++);
    for (int i = 0; i < n; ++i) {
        if (dist[i] == inf) {
            printf("Impossible\n");
        }
        else {
            printf("%d\n", dist[i]);
        }
    }
}
return 0;
}
