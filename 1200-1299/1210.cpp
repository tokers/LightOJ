/*************************************************************************
    > File Name: LightOJ1210.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年08月27日 星期四 14时06分39秒
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
 
const int N = 20010;
const int M = 50010;
struct Edge {
    int nxt;
    int to;
}edge[M];
 
int head[N], dfn[N], low[N];
int st[N];
int tot, ord, sccnum, Top;
int ins[N], outs[N];
int block[N];
bool instack[N];
 
void addedge(int from, int to) {
    edge[tot].to = to;
    edge[tot].nxt = head[from];
    head[from] = tot++;
}
 
void init() {
    memset(head, -1, sizeof(head));
    memset(dfn, -1, sizeof(dfn));
    memset(ins, 0, sizeof(ins));
    memset(outs, 0, sizeof(outs));
    memset(instack, 0, sizeof(instack));
    tot = ord = sccnum = Top = 0;
}
 
void tarjan(int u) {
    dfn[u] = low[u] = ++ord;
    instack[u] = 1;
    st[Top++] = u;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (dfn[v] == -1) {
            tarjan(v);
            if (low[u] > low[v]) {
                low[u] = low[v];
            }
        }
        else if (instack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    int v;
    if (dfn[u] == low[u]) {
        ++sccnum;
        do {
            v = st[--Top];
            block[v] = sccnum;
            instack[v] = 0;
        }while (v != u);
    }
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        init();
        int u, v;
        for (int i = 1 ; i <= m; ++i) {
            scanf("%d%d", &u, &v);
            addedge(u, v);
        }
        for (int i = 1; i <= n; ++i) {
            if (dfn[i] == -1) {
                tarjan(i);
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = head[i]; ~j; j = edge[j].nxt) {
                u = i, v = edge[j].to;
                if (block[u] != block[v]) {
                    ++ins[block[v]];
                    ++outs[block[u]];
                }
            }
        }
        int a = 0, b = 0;
        for (int i = 1; i <= sccnum; ++i) {
            a += (ins[i] == 0);
            b += (outs[i] == 0);
        }
        if (sccnum == 1) {
            a = b = 0;
        }
        printf("Case %d: %d\n", icase++, max(a, b));
    }
    return 0;
}
