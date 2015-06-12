/*************************************************************************
    > File Name: LightOJ1034.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月12日 星期五 20时50分28秒
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
static const int M = 100010;
struct node {
	int nxt;
	int to;
}edge[M];

int head[N];
int tot, ord, sccnum, tp;
int in_deg[N];
int low[N];
int DFN[N];
bool instack[N];
int st[N];
int block[N];

void addedge(int from, int to) {
	edge[tot].to = to;
	edge[tot].nxt = head[from];
	head[from] = tot++;
}

void init() {
	memset(head, -1, sizeof(head));
	memset(low, 0, sizeof(low));
	memset(in_deg, 0, sizeof(in_deg));
	memset(DFN, -1, sizeof(DFN));
	memset(instack, 0, sizeof(instack));
	tp = tot = ord = sccnum = 0;
}

void tarjan(int u) {
	DFN[u] = low[u] = ++ord;
	st[tp++] = u;
	instack[u] = 1;
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int v = edge[i].to;
		if (DFN[v] == -1) {
			tarjan(v);
			if (low[v] < low[u]) {
				low[u] = low[v];
			}
		}
		else if (instack[v] && low[u] > DFN[v]) {
			low[u] = DFN[v];
		}
	}
	int v;
	if (low[u] == DFN[u]) {
		++sccnum;
		do {
			v = st[--tp];
			instack[v] = 0;
			block[v] = sccnum;
		}while (v != u);
	}
}

int solve(int n) {
	for (int i = 1; i <= n; ++i) {
		if (DFN[i] == -1) {
			tarjan(i);
		}
	}
	int ans = 0;
	for (int u = 1; u <= n; ++u) {
		for (int j = head[u]; ~j; j = edge[j].nxt) {
			int v = edge[j].to;
			if (block[u] != block[v]) {
				++in_deg[block[v]];
			}
		}
	}
	for (int i = 1; i <= sccnum; ++i) {
		if (!in_deg[i]) {
			++ans;
		}
	}
	printf("%d\n", ans);
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		init();
		int u, v;
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d", &u, &v);
			addedge(u, v);
		}
		printf("Case %d: ", icase++);
		solve(n);
	}
	return 0;
}
