/*************************************************************************
    > File Name: LightOJ1128.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年10月03日 星期六 14时42分01秒
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

const int N = 100010;
struct Edge {
	int nxt;
	int to;
}edge[N];
int head[N], tot;
int p[N][20];
int deep[N];
int Arr[N];

void addedge(int from, int to) {
	edge[tot].to = to;
	edge[tot].nxt = head[from];
	head[from] = tot++;
	
}
void dfs(int u) {
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int v = edge[i].to;
		deep[v] = deep[u] + 1;
		p[v][0] = u;
		dfs(v);
	}
}

int getto(int u, int d) {
	for (int i = 0; i < 20; ++i) {
		if (d & (1 << i)) {
			u = p[u][i];
		}
	}
	return u;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, q, u, val;
		scanf("%d%d", &n, &q);
		memset(head, -1, sizeof(head));
		tot = 0;
		for (int i = 1; i <= n - 1; ++i) {
			scanf("%d%d", &u, &Arr[i]);
			addedge(u, i);
		}
		deep[0] = 1;
		Arr[0] = 1;
		dfs(0);
		for (int i = 1; i < 20; ++i) {
			for (int j = 0; j < n; ++j) {
				p[j][i] = p[p[j][i - 1]][i - 1];
			}
		}
		printf("Case %d:\n", icase++);
		while (q--) {
			scanf("%d%d", &u, &val);
			int l = 1, r = deep[u], mid, ans = -1;
			while (l <= r) {
				mid = (l + r) >> 1;
				int d = deep[u] - mid;
				int id = getto(u, d);
				if (Arr[id] >= val) {
					ans = id;
					r = mid - 1;
				}
				else {
					l = mid + 1;
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
