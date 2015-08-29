/*************************************************************************
    > File Name: LightOJ1168.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年08月27日 星期四 14时01分40秒
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
const int M = 10100;
struct Edge {
    int nxt;
    int to;
}edge[M];
int DFN[N], low[N], head[N], block[N], St[N];
bool instack[N];
int I[N], O[N];
int tot, ord, sccnum, Top;
 
void init(int n) {
    memset(I, 0, sizeof(I));
    memset(O, 0, sizeof(O));
    memset(head, -1, sizeof(head));
    memset(DFN, -1, sizeof(DFN));
    memset(instack, 0, sizeof(instack));
    tot = ord = sccnum = Top = 0;
}
 
void addedge(int from, int to) {
    edge[tot].to = to;
    edge[tot].nxt = head[from];
    head[from] = tot++;
}
 
void tarjan(int u) {
    DFN[u] = low[u] = ++ord;
    instack[u] = 1;
    St[Top++] = u;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (DFN[v] == -1) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (instack[v]) {
            low[u] = min(low[u], DFN[v]);
        }
    }
    int v;
    if (low[u] == DFN[u]) {
        ++sccnum;
        do {
            v = St[--Top];
            instack[v] = 0;
            block[v] = sccnum;
        }while (v != u);
    }
}
 
bool solve(int n) {
    for (int i = 1; i <= n; ++i) {
        if (DFN[i] == -1) {
            tarjan(i);
        }
    }
    if (sccnum == 1) {
        return 1;
    }
    for (int u = 1; u <= n; ++u) {
        for (int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if (block[u] != block[v]) {
                ++O[block[u]];
                ++I[block[v]];
            }
        }
    }
    if (O[block[1]] == 0 || I[block[1]] != 0) {
        return 0;
    }
    int a = 0, b = 0, c = 0;
    for (int i = 1; i <= sccnum; ++i) {
        if (I[i] == 0 && O[i] == 1) {
        	++a;
        }
        if (I[i] == 1 && O[i] == 0) {
			++b;
		}
		if (I[i] == 1 && O[i] == 1) {
			++c;
		}
    }
    return a == 1 && b == 1 && (a + b + c == sccnum);
}
 
struct EE {
    int u, v;
}e[M];
int xis[2 * M];
 
int main() {
    int t, icase = 1;
    int n, u, v;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int ret = 0, cnt = 0;
        xis[++ret] = 0;
        for (int i = 1; i <= n; ++i) {
            int k;
            scanf("%d", &k);
            while (k--) {
                scanf("%d%d", &u, &v);
                e[cnt].u = u;
                e[cnt++].v = v;
                xis[++ret] = u;
                xis[++ret] = v;
            }
        }
        sort(xis + 1, xis + ret + 1);
        ret = unique(xis + 1, xis + ret + 1) - xis - 1;
        init(ret);
        for (int i = 0; i < cnt; ++i) {
            u = lower_bound(xis + 1, xis + ret + 1, e[i].u) - xis;
            v = lower_bound(xis + 1, xis + ret + 1, e[i].v) - xis;
            addedge(u, v);
        }
        printf("Case %d: %s\n", icase++, solve(ret) ? "YES" : "NO");
    }
    return 0;
}
 
