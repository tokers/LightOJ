/*************************************************************************
    > File Name: LightOJ1380.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月24日 星期一 10时07分51秒
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
const int M = 10010;
struct Edge {
	int u, v, w;
}edge[M];

int G[N][N];
int pre[N], in[N], vis[N], id[N];

int zhuliu(int root, int n, int m) {
	int res = 0, u, v;
	while (1) {
		memset(in, inf, sizeof(in));
		for (int i = 0; i < m; ++i) {
			if (edge[i].u != edge[i].v && edge[i].w < in[edge[i].v]) {
				in[edge[i].v] = edge[i].w;
				pre[edge[i].v] = edge[i].u;
			}
		}
		for (int i = 0; i < n; ++i) {
			if (i != root && in[i] == inf) {
				return -1;
			}
		}
		int tn = 0;
		memset(id, -1, sizeof(id));
		memset(vis, -1, sizeof(vis));
		in[root] = 0;
		for (int i = 0; i < n; ++i) {
			res += in[i];
			v = i;
			while (vis[v] != i && id[v] == -1 && v != root) {
				vis[v] = i;
				v = pre[v];
			}
			if (v != root && id[v] == -1) {
				for (int u = pre[v]; u != v; u = pre[u]) {
					id[u] = tn;
				}
				id[v] = tn++;
			}
		}
		if (tn == 0) {
			break;
		}
		for (int i = 0; i < n; ++i) {
			if (id[i] == -1) {
				id[i] = tn++;
			}
		}
		for (int i = 0; i < m; ++i) {
			int v = edge[i].v;
			edge[i].u = id[edge[i].u];
			edge[i].v = id[edge[i].v];
			if (edge[i].u != edge[i].v) {
				edge[i].w -= in[v];
			}
		}
		n = tn;
		root = id[root];
	}
	return res;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int u, v, w, n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		memset(G, inf, sizeof(G));
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d%d", &u, &v, &w);
			G[u][v] = min(G[u][v], w);
		}
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (G[i][j] == inf) {
					continue;
				}
				edge[cnt].u = i;
				edge[cnt].v = j;
				edge[cnt++].w = G[i][j];
			}
		}
		int res = zhuliu(k, n, cnt);
		if (res == -1) {
			printf("Case %d: impossible\n", icase++);
			continue;
		}
		printf("Case %d: %d\n", icase++, res);
	}
	return 0;
}
