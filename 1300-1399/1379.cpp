/*************************************************************************
    > File Name: LightOJ1379.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月24日 星期一 20时05分10秒
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
const int M = 50010;
int dist[N];
int dist2[N];

queue <int> qu;
struct Edge {
	int nxt;
	int to;
	int w;
}edge[M], edge2[M];
int head[N];
int head2[N];
int tot2;
int tot;

void addedge(int from, int to, int w, Edge edge[], int &tot, int head[]) {
	edge[tot].to = to;
	edge[tot].w = w;
	edge[tot].nxt = head[from];
	head[from] = tot++;
}

void spfa(int s, int dist[], Edge edge[], int head[]) {
	while (!qu.empty()) {
		qu.pop();
	}
	qu.push(s);
	while (!qu.empty()) {
		int u = qu.front();
		qu.pop();
		for (int i = head[u]; ~i; i = edge[i].nxt) {
			int v = edge[i].to;
			int w = edge[i].w;
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				qu.push(v);
			}
		}
	}
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m, s, t, p;
		scanf("%d%d%d%d%d", &n, &m, &s, &t, &p);
		memset(head, -1, sizeof(head));
		memset(head2, -1, sizeof(head2));
		tot = tot2 = 0;
		int u, v, w;
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d%d", &u, &v, &w);
			addedge(u, v, w, edge, tot, head);
			addedge(v, u, w, edge2, tot2, head2);
		}
		memset(dist, inf, sizeof(dist));
		memset(dist2, inf, sizeof(dist2));
		dist[s] = 0;
		dist2[t] = 0;
		spfa(s, dist, edge, head);
		spfa(t, dist2, edge2, head2);
		int ans = -1;
		for (int i = 1; i <= n; ++i) {
			for (int j = head[i]; ~j; j = edge[j].nxt) {
				u = i, v = edge[j].to;
				if (dist[u] + dist2[v] + edge[j].w <= p) {
					ans = max(ans, edge[j].w);
				}
			}
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
