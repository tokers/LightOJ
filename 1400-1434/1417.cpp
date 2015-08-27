/*************************************************************************
    > File Name: LightOJ1417.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月27日 星期四 15时06分29秒
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
struct Edge {
	int to;
	int nxt;
}edge[N];
vector <int> e[N];
int dp[N];
int head[N], dfn[N], low[N], st[N];
bool instack[N];
int block[N], num[N];
int tot, Top, sccnum, ord;

void init() {
	memset(head, -1, sizeof(head));
	memset(dfn, -1, sizeof(dfn));
	memset(instack, 0, sizeof(instack));
	memset(num, 0, sizeof(num));
	tot = Top = sccnum = ord = 0;
}

void addedge(int from, int to) {
	edge[tot].to = to;
	edge[tot].nxt = head[from];
	head[from] = tot++;
}

void tarjan(int u) {
	instack[u] = 1;
	st[Top++] = u;
	low[u] = dfn[u] = ++ord;
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int v = edge[i].to;
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
			++num[sccnum];
		}while (v != u);
	}
}

int dfs(int u) {
	if (~dp[u]) {
		return dp[u];
	}
	int size = e[u].size();
	dp[u] = num[u];
	for (int i = 0; i < size; ++i) {
		int v = e[u][i];
		dp[u] = max(dp[u], dfs(v) + num[u]);
	}
	return dp[u];
}

int solve(int n) {
	for (int i = 1; i <= n; ++i) {
		if (dfn[i] == -1) {
			tarjan(i);
		}
	}
	for (int i = 1; i <= sccnum; ++i) {
		dp[i] = -1;
		e[i].clear();
	}
	for (int u = 1; u <= n; ++u) {
		for (int i = head[u]; ~i; i = edge[i].nxt) {
			int v = edge[i].to;
			if (block[u] != block[v]) {
				e[block[u]].push_back(block[v]);
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= sccnum; ++i) {
		if (dp[i] == -1) {
			dfs(i);
		}
		res = max(res, dp[i]);
	}
	for (int i = 1; i <= n; ++i) {
		if (res == dp[block[i]]) {
			return i;
		}
	}
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, u, v;
		scanf("%d", &n);
		init();
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", &u, &v);
			addedge(u, v);
		}
		printf("Case %d: %d\n", icase++, solve(n));
	}
	return 0;
}
