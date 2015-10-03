/*************************************************************************
    > File Name: LightOJ1101.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年10月03日 星期六 13时05分33秒
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
 
const int N = 50010;
const int M = 100010;
 
struct E {
    int u, v, w;
    bool flag;
    bool operator < (const E &b) const {
        return w < b.w;
    }
}e[M];
 
struct Edge {
    int to, nxt;
}edge[M << 1];
int head[N], tot;
int top[N], fa[N];
int deep[N], size[N];
int p[N];
int fp[N];
int son[N];
int pos;
int pre[N];
int dp[N][20];
int LOG[N];
 
void init() {
    tot = pos = 0;
    memset(head, -1, sizeof(head));
    memset(son, -1, sizeof(son));
}
 
void addedge(int from, int to) {
    edge[tot].to = to;
    edge[tot].nxt = head[from];
    head[from] = tot++;
}
 
int Find(int x) {
    if (pre[x] == -1) {
        return x;
    }
    return pre[x] = Find(pre[x]);
}
 
int kruskal(int n, int m) {
    sort(e + 1, e + m + 1);
    memset(pre, -1, sizeof(pre));
    int cnt = 0;
    for (int i = 1; i <= m; ++i) {
        int u = Find(e[i].u);
        int v = Find(e[i].v);
        if (u != v) {
            pre[u] = v;
            ++cnt;
            e[i].flag = 1;
        }
        if (cnt == n - 1) {
            return i;
        }
    }
}
 
void dfs1(int u, int anc, int d) {
    deep[u] = d;
    fa[u] = anc;
    size[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v != anc) {
            dfs1(v, u, d + 1);
            size[u] += size[v];
            if (son[u] == -1 || size[v] > size[son[u]]) {
                son[u] = v;
            }
        }
    }
}
 
void getpos(int u, int sp) {
    top[u] = sp;
    p[u] = ++pos;
    fp[p[u]] = u;
    if (son[u] == -1) {
        return;
    }
    getpos(son[u], sp);
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (v != son[u] && v != fa[u]) {
            getpos(v, v);
        }
    }
}
 
void initRMQ() {
    LOG[0] = -1;
    dp[1][0] = 0;
    for (int i = 1; i <= pos; ++i) {
        LOG[i] = (i & (i - 1)) ? LOG[i - 1] : LOG[i - 1] + 1;
    }
    for (int j = 1; j <= LOG[pos]; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= pos; ++i) {
            dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
}
 
int ST(int l, int r) {
    int k = LOG[r - l + 1];
    return max(dp[l][k], dp[r - (1 << k) + 1][k]);
}
 
int solve(int u, int v) {
    int f1 = top[u];
    int f2 = top[v];
    int ans = 0;
    while (f1 != f2) {
        if (deep[f1] < deep[f2]) {
            swap(f1, f2);
            swap(u, v);
        }
        ans = max(ans, ST(p[f1], p[u]));
        u = fa[f1];
        f1 = top[u];
    }
    if (u == v) {
        return ans;
    }
    if (deep[u] > deep[v]) {
        swap(u, v);
    }
    return max(ans, ST(p[son[u]], p[v]));
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int u, v, w, n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            e[i].u = u, e[i].v = v, e[i].w = w;
            e[i].flag = 0;
        }
        init();
        m = kruskal(n, m);
        for (int i = 1; i <= m; ++i) {
            if (e[i].flag) {
                u = e[i].u, v = e[i].v;
                addedge(u, v);
                addedge(v, u);
            }
        }
        dfs1(1, -1, 0);
        getpos(1, 1);
        for (int i = 1; i <= m; ++i) {
            if (e[i].flag) {
                if (deep[e[i].u] < deep[e[i].v]) {
                    swap(e[i].u, e[i].v);
                }
                dp[p[e[i].u]][0] = e[i].w;
            }
        }
        initRMQ();
        int q;
        scanf("%d", &q);
        printf("Case %d:\n", icase++);
        while (q--) {
            scanf("%d%d", &u, &v);
            printf("%d\n", solve(u, v));
        }
    }
    return 0;
}
