/*************************************************************************
    > File Name: LightOJ1281.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月24日 星期一 19时27分49秒
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
const int M = 30010;
struct Edge {
	int nxt;
	int to;
	int c1, c2;
}edge[M];
int head[N];
int tot;
int dist[N][15];

void addedge(int from, int to, int c1, int c2) {
	edge[tot].to = to;
	edge[tot].c1 = c1;
	edge[tot].c2 = c2;
	edge[tot].nxt = head[from];
	head[from] = tot++; 
}

struct sta {
	int u, c;
	bool operator < (const sta &b) const {
		return dist[u][c] > dist[b.u][b.c];
	}

	sta(int _u, int _c) : u(_u), c(_c) {}
};

priority_queue <sta> qu;

void dijkstra(int s, int limit) {
	memset(dist, inf, sizeof(dist));
	dist[s][0] = 0;
	while (!qu.empty()) {
		qu.pop();
	}
	qu.push(sta(s, 0)); // u, c, dist[u][c]
	while (!qu.empty()) {
		sta now = qu.top();
		qu.pop();
		int u = now.u;
		int c = now.c;
		for (int i = head[u]; ~i; i = edge[i].nxt) {
			int v = edge[i].to;
			int cnt = edge[i].c2;
			if (c + cnt <= limit && dist[v][c + cnt] > dist[u][c] + edge[i].c1) {
				dist[v][c + cnt] = dist[u][c] + edge[i].c1;
				qu.push(sta(v, c + cnt));
			}
		}
	}
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m, k, d, u, v, w;
		scanf("%d%d%d%d", &n, &m, &k, &d);
		memset(head, -1, sizeof(head));
		tot = 0;
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d%d", &u, &v, &w);
			addedge(u, v, w, 0);
		}
		for (int i = 1; i <= k; ++i) {
			scanf("%d%d%d", &u, &v, &w);
			addedge(u, v, w, 1);
		}
		dijkstra(0, d);
		int ans = inf;
		for (int i = 0; i <= d; ++i) {
			ans = min(ans, dist[n - 1][i]);
		}
		printf("Case %d: ", icase++);
		if (ans == inf) {
			printf("Impossible\n");
		}
		else {
			printf("%d\n", ans);
		}
	}
	return 0;
}
