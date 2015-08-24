/*************************************************************************
    > File Name: LightOJ1384.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月24日 星期一 10时38分52秒
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

const int N = 66;
const int M = 10010;

struct Edge {
	int u, v, c, bw;
}edge[M], edge2[M];

int pre[N], in[N], vis[N], id[N];

int zhuliu(int root, int n, int m, int X) {
	int res = 0, u, v;
	while (1) {
		memset(in, inf, sizeof(in));
		for (int i = 0; i < m; ++i) {
			if (edge[i].u != edge[i].v && edge[i].c < in[edge[i].v] && edge[i].bw >= X) {
				in[edge[i].v] = edge[i].c;
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
				edge[i].c -= in[v];
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
		int n, m, C;
		int mid, ans = -1, l = 1, r = 1;
		scanf("%d%d%d", &n, &m, &C);
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d%d", &edge[i].u, &edge[i].v, &edge[i].bw, &edge[i].c);
			r = max(r, edge[i].bw);
			edge2[i].u = edge[i].u, edge2[i].v = edge[i].v, edge2[i].c = edge[i].c;
			edge2[i].bw = edge[i].bw;
		}
		while (l <= r) {
			mid = (l + r) >> 1;
			int res = zhuliu(0, n, m, mid);
			if (res != -1 && res <= C) {
				ans = mid;
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
			for (int i = 0; i < m; ++i) {
				edge[i].u = edge2[i].u;
				edge[i].v = edge2[i].v;
				edge[i].c = edge2[i].c;
				edge[i].bw = edge2[i].bw;
			}
		}
		if (ans == -1) {
			printf("Case %d: impossible\n", icase++);
		}
		else {
			printf("Case %d: %d kbps\n", icase++, ans);
		}
	}
	return 0;
}
