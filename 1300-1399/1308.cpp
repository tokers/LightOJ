/*************************************************************************
    > File Name: LightOJ1308.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月31日 星期一 16时22分14秒
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
	int to;
	int nxt;
}edge[M << 1];
int head[N], dfn[N], low[N], St[N], deg[N];
bool instack[N];
bool cut[N];
vector <int> block[N];
int tot, ord, Top, num;
int root;

void addedge(int from, int to) {
	edge[tot].to = to;
	edge[tot].nxt = head[from];
	head[from] = tot++;
}

void init() {
	memset(head, -1, sizeof(head));
	memset(dfn, -1, sizeof(dfn));
	memset(cut, 0, sizeof(cut));
	memset(deg, 0, sizeof(deg));
	memset(instack, 0, sizeof(instack));
	tot = ord = Top = num = 0;
}

void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++ord;
	instack[u] = 1;
	St[Top++] = u;
	int x = 0;
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int v = edge[i].to;
		if (v == fa) {
			continue;
		}
		++x;
		if (dfn[v] == -1) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= dfn[u]) {
				if (u != root) {
					cut[u] = 1;
				}
				else if (x > 1) {
					cut[u] = 1;
				}
				++num;
				block[num].clear();	
				block[num].push_back(u);
				int vn;
				do {
					vn = St[--Top];
					block[num].push_back(vn);
					instack[vn] = 0;
				}while (vn != v);
			}

		}
		else if (instack[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
}

int ans;
ULL ways;

void solve(int n) {
	for (int i = 0; i < n; ++i) {
		if (dfn[i] == -1) {
			tarjan(i, -1);
		}
	}
	ans = 0;
	ways = 1;
	for (int i = 1; i <= num; ++i) {
		int size = block[i].size();
		int cuts = 0;
		for (int j = 0; j < size; ++j) {
			if (cut[block[i][j]]) {
				++cuts;
			}
		}
		if (cuts >= 2) {
			continue;
		}
		if (cuts == 0 && size >= 2) {
			ans += 2;
			ways *= (ULL)(size - 1) * size / 2;
		}
		else if (size > cuts) {
			++ans;
			ways *= (size - cuts);
		}
	}
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int u, v, n, m;
		scanf("%d%d", &n, &m);
		init();
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d", &u, &v);
			addedge(u, v);
			addedge(v, u);
		}
		solve(n);
		printf("Case %d: %d %llu\n", icase++, ans, ways);
	}
	return 0;
}
