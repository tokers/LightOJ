/*************************************************************************
    > File Name: LightOJ1185.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年10月10日 星期六 15时09分44秒
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

const int N = 110;
int col[N];
queue <int> qu;
bool vis[N];
bool edge[N][N];
int cnt, n, m;

void dfs(int u) {
	++cnt;
	for (int i = 1; i <= n; ++i) {
		if (edge[u][i] && !vis[i]) {
			vis[i] = 1;
			dfs(i);
		}
	}
}

int bfs() {
	while (!qu.empty()) {
		qu.pop();
	}
	for (int i = 1; i <= n; ++i) {
		col[i] = -1;
	}
	col[1] = 0;
	qu.push(1);
	memset(vis, 0, sizeof(vis));
	vis[1] = 1;
	dfs(1);
	bool flag = 1;
	while (!qu.empty()) {
		int u = qu.front();
		qu.pop();
		for (int i = 1; i <= n; ++i) {
			if (edge[u][i]) {
				if (col[i] == -1) {
					col[i] = (!col[u]);
					qu.push(i);
				}
				else if (col[i] == col[u]) {
					flag = 0;
					break;
				}
			}
		}
	}
	int ans = 0;
	if (flag) {
		for (int i = 1; i <= n; ++i) {
			if (col[i] != -1 && col[i] == col[1]) {
				++ans;
			}
		}
	}
	else {
		ans = cnt;
	}
	if (cnt == 1) {
		ans = 0;
	}
	return ans;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		memset(edge, 0, sizeof(edge));
		int u, v;
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d", &u, &v);
			edge[u][v] = edge[v][u] = 1;
		}
		cnt = 0;
		int ans = bfs();
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
