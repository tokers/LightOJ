/*************************************************************************
    > File Name: LightOJ1108.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年08月25日 星期二 13时15分51秒
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
const int M = 2010;
int head[N];
struct Edge {
    int to;
    int nxt;
    int w;
}edge[M];
int st[N];
int tot, ord, sccnum, Top;
int low[N];
int DFN[N];
vector <int> go[N];
bool instack[N];
bool vis[N];
int block[N];
vector <int> P[N];
vector <int> ans;
int cnt[N];
int dist[N];
bool ins[N];
 
void init(int n) {
    memset(head, -1, sizeof(head));
    memset(DFN, -1, sizeof(DFN));
    memset(instack, 0, sizeof(instack));
    memset(vis, 0, sizeof(vis));
    tot = 0;
    ord = 0;
    sccnum = 0;
    Top = 0;
    for (int i = 0; i < n; ++i) {
        go[i].clear();
        P[i].clear();
    }
 
}
void addedge(int from, int to, int w) {
    edge[tot].to = to;
    edge[tot].nxt = head[from];
    edge[tot].w = w;
    head[from] = tot++;
}
 
void tarjan(int u) {
    DFN[u] = low[u] = ++ord;
    instack[u] = 1;
    st[Top++] = u;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (DFN[v] == -1) {
            tarjan(v);
            if (low[u] > low[v]) {
                low[u] = low[v];
            }
        }
        else if (instack[v]) {
            low[u] = min(low[u], DFN[v]);
        }
    }
    int v;
    if (DFN[u] == low[u]) {
        do {
            v = st[--Top];
            P[sccnum].push_back(v);
            block[v] = sccnum;
            instack[v] = 0;
        }while (v != u);
        ++sccnum;
    }
}
 
void spfa(int num) {
    memset(cnt, 0, sizeof(cnt));
    memset(ins, 0, sizeof(ins));
    memset(dist, inf, sizeof(dist));
    queue <int> qu;
    for (int i = 0; i < num; ++i) {
        if ((int)P[i].size() == 1) {
            continue;
        }
        dist[P[i][0]] = 0;
        qu.push(P[i][0]);
        ins[P[i][0]] = 1;
    }
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        ins[u] = 0;
        if (vis[block[u]]) {
            continue;
        }
        ++cnt[u];
        if (cnt[u] >= (int)P[block[u]].size()) {
            vis[block[u]] = 1;
            continue;
        }
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if (block[v] != block[u]) {
                continue;
            }
            int w = edge[i].w;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (ins[v] == 0) {
                    qu.push(v);
                    ins[v] = 1;
                }
            }
        }
    }
}
 
void dfs(int u) {
    int size = go[u].size();
    for (int i = 0; i < size; ++i) {
        int v = go[u][i];
        if (!vis[v]) {
            vis[v] = 1;
            dfs(v);
        }
    }
}
 
void solve(int n) {
    for (int i = 0; i < n; ++i) {
        if (DFN[i] == -1) {
            tarjan(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = head[i]; ~j; j = edge[j].nxt) {
            int u = i, v = edge[j].to;
            if (block[u] == block[v]) {
                continue;
            }
            go[block[v]].push_back(block[u]);
        }
    }
    spfa(sccnum);
    for (int i = 0; i < sccnum; ++i) {
        if (vis[i]) {
            dfs(i);
        }
    }
    ans.clear();
    for (int i = 0; i < sccnum; ++i) {
        if (!vis[i]) {
            continue;
        }
        int size = P[i].size();
        for (int j = 0; j < size; ++j) {
            ans.push_back(P[i][j]);
        }
    }
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        int u, v, w;
        init(n);
        for (int i = 1; i <= m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            addedge(u, v, w);
        }
        solve(n);
        printf("Case %d:", icase++);
        int size = ans.size();
        if (!size) {
            printf(" impossible\n");
        }
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < size; ++i) {
                printf(" %d", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
