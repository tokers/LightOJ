/*************************************************************************
    > File Name: LightOJ1300.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年08月31日 星期一 14时54分35秒
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
 
const int N = 10010;
const int M = 20010;
struct Edge {
    int to;
    int nxt;
}edge[M << 1];
int head[N], block[N], dfn[N], low[N], St[N], col[N];
bool instack[N], vis[N];
int Top, ord, num, tot;
 
void addedge(int from, int to) {
    edge[tot].to = to;
    edge[tot].nxt = head[from];
    head[from] = tot++;
}
 
void init() {
    memset(head, -1, sizeof(head));
    memset(col, -1, sizeof(col));
    memset(dfn, -1, sizeof(dfn));
    memset(instack, 0, sizeof(instack));
    memset(vis, 0, sizeof(vis));
    tot = ord = num = Top = 0;
}
 
void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++ord;
    instack[u] = 1;
    St[Top++] = u;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v == fa) {
            continue;
        }
        if (dfn[v] == -1) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if (instack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    int v;
    if (dfn[u] == low[u]) {
        ++num;
        do {
            v = St[--Top];
            instack[v] = 0;
            block[v] = num;
        }while (v != u);
    }
}
 
int bfs(int n) {
    queue <int> qu;
    for (int i = 0; i < n; ++i) {
        if (!vis[block[i]]) {
            qu.push(i);
            vis[block[i]] = 1;
            col[i] = 1;
        }
    }
    memset(vis, 0, sizeof(vis));
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        if (vis[block[u]]) {
            continue;
        }
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if (block[v] != block[u]) {
                continue;
            }
            if (vis[block[v]]) {
                continue;
            }
            if (col[v] == -1) {
                col[v] = (!col[u]);
                qu.push(v);
            }
            else if (col[v] == col[u]) {
                vis[block[u]] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (vis[block[i]]) {
            ++ans;
        }
    }
    return ans;
}
 
int solve(int n) {
    for (int i = 0; i < n; ++i) {
        if (dfn[i] == -1) {
            tarjan(i, -1);
        }
    }
    return bfs(n);
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m, u, v;
        init();
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; ++i) {
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }
        printf("Case %d: %d\n", icase++, solve(n));
    }
    return 0;
}
