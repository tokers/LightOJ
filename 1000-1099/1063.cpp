/*************************************************************************
    > File Name: LightOJ1063.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月29日 星期一 15时01分42秒
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
const int M = 20010;

struct Edge {
	int nxt;
	int to;
}edge[M << 1];

int head[N], tot;
int DFN[N], low[N];
int ord, Top;
int Stack[N];
bool instack[N];
bool cut[N];
int root;

void addedge(int from, int to) {
	edge[tot].to = to;
	edge[tot].nxt = head[from];
	head[from] = tot++;
}

void init() {
	memset(head, -1, sizeof(head));
	memset(DFN, -1, sizeof(DFN));
	memset(instack, 0, sizeof(instack));
	memset(cut, 0, sizeof(cut));
	tot = ord = Top = 0;
}

void tarjan(int u, int fa) {
	instack[u] = 1;
	Stack[++Top] = u;
	DFN[u] = low[u] = ++ord;
	int cnt = 0;
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int v = edge[i].to;
		if (v == u) {
			continue;
		}
		if (DFN[v] == -1) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			++cnt;
			if (u == root && cnt > 1) {
				cut[u] = 1;
			}
			else if (u != root && low[v] >= DFN[u]) {
				cut[u] = 1;
			}
		}
		else if (low[u] > DFN[v]) {
			low[u] = DFN[v];
		}
	}
	if (low[u] == DFN[u]) {
		int v;
		do {
			v = Stack[Top--];
			instack[v] = 0;
		}while (v != u);
	}
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		init();
		int u, v;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d", &u, &v);
			addedge(u, v);
			addedge(v, u);
		}
		for (int i = 1; i <= n; ++i) {
			if (DFN[i] == -1) {
				root = i;
				tarjan(i, -1);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			ans += cut[i];
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
