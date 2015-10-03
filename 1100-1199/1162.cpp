/*************************************************************************
    > File Name: LightOJ1162.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年10月03日 星期六 15时10分00秒
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

const int N = 100010;
struct Edge {
	int nxt;
	int to;
}edge[N << 1];
int head[N], tot;
int top[N], size[N];
int fa[N], deep[N];
int p[N], son[N], pos;

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

void dfs1(int u, int pre, int d) {
	deep[u] = d;
	fa[u] = pre;
	size[u] = 1;
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int v = edge[i].to;
		if (v != pre) {
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

int dp1[N][20], dp2[N][20];
int LOG[N];

void initRMQ() {
	dp1[1][0] = inf;
	dp2[1][0] = 0;
	LOG[0] = -1;
	for (int i = 1; i <= pos; ++i) {
		LOG[i] = (i & (i - 1)) ? LOG[i - 1] : LOG[i - 1] + 1;
	}
	for (int j = 1; j <= LOG[pos]; ++j) {
		for (int i = 1; i + (1 << j) - 1 <= pos; ++i) {
			dp1[i][j] = min(dp1[i][j - 1], dp1[i + (1 << (j - 1))][j - 1]);
			dp2[i][j] = max(dp2[i][j - 1], dp2[i + (1 << (j - 1))][j - 1]);
		}
	}
}

PLL ST(int l, int r) {
	int k = LOG[r - l + 1];
	int a = min(dp1[l][k], dp1[r - (1 << k) + 1][k]);
	int b = max(dp2[l][k], dp2[r - (1 << k) + 1][k]);
	return make_pair(a, b);
}

PLL solve(int u, int v) {
	int f1 = top[u];
	int f2 = top[v];
	int ans1 = inf, ans2 = 0;
	while (f1 != f2) {
		if (deep[f1] < deep[f2]) {
			swap(f1, f2);
			swap(u, v);
		}
		PLL now = ST(p[f1], p[u]);
		if (now.first < ans1) {
			ans1 = now.first;
		}
		if (now.second > ans2) {
			ans2 = now.second;
		}
		u = fa[f1];
		f1 = top[u];
	}
	if (u == v) {
		return make_pair(ans1, ans2);
	}
	if (deep[u] > deep[v]) {
		swap(u, v);
	}
	PLL now = ST(p[son[u]], p[v]);
	if (now.first < ans1) {
		ans1 = now.first;
	}
	if (now.second > ans2) {
		ans2 = now.second;
	}
	return make_pair(ans1, ans2);
}

struct E {
	int u, v, w;
}e[N];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, u, v, w;
		init();
		scanf("%d", &n);
		for (int i = 1; i <= n - 1; ++i) {
			scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
			addedge(e[i].u, e[i].v);
			addedge(e[i].v, e[i].u);
		}
		dfs1(1, -1, 0);
		getpos(1, 1);
		for (int i = 1; i <= n - 1; ++i) {
			if (deep[e[i].u] < deep[e[i].v]) {
				swap(e[i].u, e[i].v);
			}
			dp1[p[e[i].u]][0] = dp2[p[e[i].u]][0] = e[i].w;
		}
		initRMQ();
		int q;
		scanf("%d", &q);
		printf("Case %d:\n", icase++);
		while (q--) {
			scanf("%d%d", &u, &v);
			PLL ans = solve(u, v);
			printf("%d %d\n", ans.first, ans.second);
		}
	}
	return 0;
}
