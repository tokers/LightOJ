/*************************************************************************
    > File Name: LightOJ1206.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年09月07日 星期一 13时05分36秒
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

const int N = 510;
struct Edge {
	int to;
	int nxt;
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

int hungry(int n) {
	memset(match, -1, sizeof(match));
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		memset(vis, 0, sizeof(vis));
		if (dfs(i)) {
			++ans;
		}
	}
	return ans;
}

struct node {
	int t, x1, y1, x2, y2;
}p[N];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		memset(head, -1, sizeof(head));
		tot = 0;
		int h, m;
		for (int i = 1; i <= n; ++i) {
			scanf("%d:%d %d %d %d %d", &h, &m, &p[i].x1, &p[i].y1, &p[i].x2, &p[i].y2);
			p[i].t = h * 3600 + m * 60;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i == j) {
					continue;
				}
				int use = abs(p[i].x1 - p[i].x2) + abs(p[i].y1 - p[i].y2) + abs(p[i].x2 - p[j].x1) + abs(p[i].y2 - p[j].y1);
				if (p[i].t + use * 60 <= p[j].t - 1) {
					addedge(i, j);
				}
			}
		}
		printf("Case %d: %d\n", icase++, n - hungry(n));
	}
	return 0;
}
