/*************************************************************************
    > File Name: LightOJ1026.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月11日 星期四 12时22分12秒
 ************************************************************************/

#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <set>
#include <vector>

using namespace std;

const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef pair <int, int> PLL;

static const int N = 10010;
static const int M = 1000010;
int dfn[N];
int low[N];
int head[N];
int tot, ord;

struct node {
	int nxt;
	int to;
}edge[M << 1];

PLL bridge[M];
int res;

void addedge(int from, int to) {
	edge[tot].to = to;
	edge[tot].nxt = head[from];
	head[from] = tot++;
}

void init() {
	memset(head, -1, sizeof(head));
	memset(dfn, -1, sizeof(dfn));
	memset(low, 0, sizeof(low));
	ord = tot = 0;
}

void tarjan(int u, int x) {
	dfn[u] = low[u] = ++ord;
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		if (edge[i].to == x) {
			continue;
		}
		int v = edge[i].to;
		if (dfn[v] == -1) {
			tarjan(v, u);
			if (low[u] > low[v]) {
				low[u] = low[v];
			}
			if (dfn[u] < low[v]) {
				int x1 = u, y1 = v;
				if (x1 > y1) {
					swap(x1, y1);
				}
				bridge[res++] = make_pair(x1, y1);
			}
		}
		else if (low[u] > dfn[v]){
			low[u] = dfn[v];
		}
	}
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		init();
		scanf("%d", &n);
		int u, v, k, ret = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &u);
			getchar();
			getchar();
			scanf("%d", &k);
			getchar();
			while (k--) {
				scanf("%d", &v);
				addedge(u, v);
			}
		}
		res = 0;
		for (int i = 0; i < n; ++i) {
			if (dfn[i] == -1) {
				tarjan(i, -1);
			}
		}
		sort(bridge, bridge + res);
		printf("Case %d:\n", icase++);
		printf("%d critical links\n", res);
		for (int i = 0; i < res; ++i) {
			printf("%d - %d\n", bridge[i].first, bridge[i].second);
		}
	}
	return 0;
}
