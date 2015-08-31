/*************************************************************************
    > File Name: LightOJ1291.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月31日 星期一 10时37分55秒
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
int deg[N], low[N], head[N], block[N], dfn[N], St[N];
bool instack[N];
int tot, ord, num, Top;

void addedge(int from, int to) {
	edge[tot].to = to;
	edge[tot].nxt = head[from];
	head[from] = tot++;
}

void init() {
	memset(head, -1, sizeof(head));
	memset(dfn, -1, sizeof(dfn));
	memset(instack, 0, sizeof(instack));
	memset(deg, 0, sizeof(deg));
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

int solve(int n) {
	for (int i = 1; i <= n; ++i) {
		if (dfn[i] == -1) {
			tarjan(i, -1);
		}
	}
	if (num == 1) {
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = head[i]; ~j; j = edge[j].nxt) {
			int u = i, v = edge[j].to;
			if (block[u] != block[v]) {
				++deg[block[u]];
				++deg[block[v]];
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= num; ++i) {
		if (deg[i] / 2 == 1) {
			++ans;
		}
	}
	return (ans + 1) >> 1;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int u, v, n, m;
		scanf("%d%d", &n, &m);
		init();
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d", &u, &v);
			++u, ++v;
			addedge(u, v);
			addedge(v, u);
		}
		printf("Case %d: %d\n", icase++, solve(n));
	}
	return 0;
}
