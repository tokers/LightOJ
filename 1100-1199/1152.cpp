/*************************************************************************
    > File Name: LightOJ1152.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年09月07日 星期一 12时33分58秒
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

const int N = 420;
struct Edge {
	int nxt;
	int to;
}edge[N * N];

int head[N], tot;

void addedge(int from, int to) {
	edge[tot].to = to;
	edge[tot].nxt = head[from];
	head[from] = tot++;
}

int match[N];
bool vis[N];

bool dfs(int u) {
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int v = edge[i].to;
		if (!vis[v]) {
			vis[v] = 1;
			if (match[v] == -1 || dfs(match[v])) {
				match[v] = u;
				return 1;
			}
		}
	}
	return 0;
}

char mat[33][33];
int ord[33][33];
int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		int N = 0;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%s", mat[i]);
			for (int j = 0; j < m; ++j) {
				if (mat[i][j] == '*') {
					ord[i][j] = ++N;
				}
			}
		}
		memset(head, -1, sizeof(head));
		tot = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (mat[i][j] == '*') {
					int u = ord[i][j];
					if (i - 1 >= 0 && mat[i - 1][j] == '*') {
						int v = ord[i - 1][j];
						addedge(u, v);
					}
					if (i + 1 < n && mat[i + 1][j] == '*') {
						int v = ord[i + 1][j];
						addedge(u, v);
					}
					if (j - 1 >= 0 && mat[i][j - 1] == '*') {
						int v = ord[i][j - 1];
						addedge(u, v);
					}
					if (j + 1 < m && mat[i][j + 1] == '*') {
						int v = ord[i][j + 1];
						addedge(u, v);
					}
				}
			}
		}
		int ans = 0;
		memset(match, -1, sizeof(match));
		for (int i = 1; i <= N; ++i) {
			memset(vis, 0, sizeof(vis));
			ans += dfs(i);
		}
		printf("Case %d: %d\n", icase++, N - ans / 2);
	}
	return 0;
}
