/*************************************************************************
    > File Name: LightOJ1074.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月09日 星期四 17时12分34秒
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

int dist[250];
struct Edge {
	int w;
	int to;
	int nxt;
}edge[40010];
int head[250], tot;

void addedge(int from, int to, int w) {
	edge[tot].to = to;
	edge[tot].nxt = head[from];
	edge[tot].w = w;
	head[from] = tot++;
}

int cnt[333];

void spfa(int n) {
	memset(dist, inf, sizeof(dist));
	dist[1] = 0;
	queue <int> qu;
	qu.push(1);
	memset(cnt, 0, sizeof(cnt));
	while (!qu.empty()) {
		int u = qu.front();
		qu.pop();
		++cnt[u];
		if (cnt[u] > n) {
			return;
		}
		for (int i = head[u]; ~i; i = edge[i].nxt) {
			int v = edge[i].to;
			if (dist[v] > dist[u] + edge[i].w) {
				dist[v] = dist[u] + edge[i].w;
				qu.push(v);
			}
		}
	}
}

int w[250];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &w[i]);
		}
		memset(head, -1, sizeof(head));
		tot = 0;
		int u, v, m, q;
		scanf("%d", &m);
		while (m--) {
			scanf("%d%d", &u, &v);
			addedge(u, v, (w[v] - w[u]) * (w[v] - w[u]) * (w[v] - w[u]));
		}
		spfa(n);
		scanf("%d", &q);
		printf("Case %d:\n", icase++);
		while (q--) {
			scanf("%d", &u);
			if (dist[u] == inf || dist[u] < 3) {
				printf("?\n");
			}
			else {
				printf("%d\n", dist[u]);
			}
		}
	}
	return 0;
}
