/*************************************************************************
    > File Name: LightOJ1429.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年08月27日 星期四 20时25分02秒
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
 
int dfn[N], block[N], low[N], mark[N], st[N];
bool instack[N], vis[N];
int ord, sccnum, Top;
vector <int> E[N];
vector <int> e[N];
vector <int> G[N];
 
void init(int n) {
    memset(dfn, -1, sizeof(dfn));
    memset(mark, -1, sizeof(mark));
    memset(instack, 0, sizeof(instack));
    memset(vis, 0, sizeof(vis));
    ord = sccnum = Top = 0;
    for (int i = 1; i <= n; ++i) {
		E[i].clear();
		e[i].clear();
		G[i].clear();
	}
}
 
void tarjan(int u) {
    dfn[u] = low[u] = ++ord;
    instack[u] = 1;
    st[Top++] = u;
    int size = E[u].size();
    for (int i = 0; i < size; ++i) {
        int v = E[u][i];
        if (dfn[v] == -1) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
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
            instack[v] = 0;
            block[v] = sccnum;
        }while (v != u);
    }
}
 
bool dfs(int u) {
	int size = e[u].size();
    for (int i = 0; i < size; ++i) {
        int v = e[u][i];
        if (!vis[v]) {
            vis[v] = 1;
            if (mark[v] == -1 || dfs(mark[v])) {
                mark[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
 
int hungry() {
    int ans = 0;
    for (int i = 1; i <= sccnum; ++i) {
        memset(vis, 0, sizeof(vis));
        ans += dfs(i);
    }
    return ans;
}
 
void bfs(int s) {
	queue <int> qu;
	qu.push(s);
	memset(vis, 0, sizeof(vis));
	while (!qu.empty()) {
		int u = qu.front();
		qu.pop();
		vis[u] = 1;
		int size = G[u].size();
		for (int i = 0; i < size; ++i) {
			int v = G[u][i];
			if (vis[v]) {
				continue;
			}
			vis[v] = 1;
			E[s].push_back(v);
			qu.push(v);
		}
	}
}

int solve(int n) {
    for (int i = 1; i <= n; ++i) {
        if (dfn[i] == -1) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
    	int size = E[i].size();
        for (int j = 0; j < size; ++j) {
            int u = i, v = E[i][j];
            if (block[u] != block[v]) {
            	e[block[u]].push_back(block[v]);
            }
        }
    }
    int res = sccnum - hungry();
    return res;
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int u, v, n, m;
        scanf("%d%d", &n, &m);
        init(n);
        for (int i = 1; i <= m; ++i) {
            scanf("%d%d", &u, &v);
        	G[u].push_back(v);
        }
        for (int i = 1; i <= n; ++i) {
			bfs(i);
		}
        printf("Case %d: %d\n", icase++, solve(n));
    }
    return 0;
}
