/*************************************************************************
    > File Name: LightOJ1094.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月09日 星期四 13时52分48秒
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

const int N = 30010;
struct Edge {
	int nxt;
	int to;
	int w;
}edge[N << 1];
int head[N], tot;
bool vis[N];
int dist[N];

void addedge(int from, int to, int w) {
	edge[tot].to = to;
	edge[tot].nxt = head[from];
	edge[tot].w = w;
	head[from] = tot++;
}

int end_p;

int bfs(int s) {
	queue <int> qu;
	int d = 0;
	qu.push(s);
	memset(vis, 0, sizeof(vis));
	memset(dist, inf, sizeof(dist));
	dist[s] = 0;
	vis[s] = 1;
	while (!qu.empty()) {
		int u = qu.front();
		qu.pop();
		for (int i = head[u]; ~i; i = edge[i].nxt) {
			int v = edge[i].to;
			int w = edge[i].w;
			if (!vis[v]) {
				vis[v] = 1;
				qu.push(v);
				dist[v] = dist[u] + w;
				if (d < dist[v]) {
					d = dist[v];
					end_p = v;
				}
			}
		}
	}
	return d;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		memset(head, -1, sizeof(head));
		tot = 0;
		int u, v, w;
		for (int i = 1; i <= n - 1; ++i) {
			scanf("%d%d%d", &u, &v, &w);
			++u, ++v;
			addedge(u, v, w);
			addedge(v, u, w);
		}
		bfs(1);
		int ans = bfs(end_p);
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
