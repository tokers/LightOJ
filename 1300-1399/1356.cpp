/*************************************************************************
    > File Name: LightOJ1356.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月06日 星期一 18时55分25秒
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

const int N = 500010;
int vis[N];
int Arr[40010];
bool prime[N];
int col[N];

struct Edge {
	int nxt;
	int to;
}edge[N];
int head[N], tot;

void getprime() {
	int n = 500000;
	for (int i = 2; i <= n; ++i) {
		prime[i] = 1;
	}
	prime[1] = 0;
	for (int i = 2; i <= n; ++i) {
		if (prime[i]) {
			if (n / i < i) {
				break;
			}
			for (int j = i * i; j <= n; j += i) {
				prime[j] = 0;
			}
		}
	}
}

void addedge(int from, int to) {
	edge[tot].to = to;
	edge[tot].nxt = head[from];
	head[from] = tot++;
}

const int MAXN = 40010;
int Mx[MAXN], My[MAXN];
int dx[MAXN], dy[MAXN];
int dis;
int uN;
bool used[MAXN];

bool SearchP() {
	queue <int> Q;
	dis = inf;
	memset(dx, -1, sizeof(dx));
	memset(dy, -1, sizeof(dy));
	for (int i = 1; i <= uN; ++i) {
		if (Mx[i] == -1) {
			Q.push(i);
			dx[i] = 0;
		}
	}
	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		if (dx[u] > dis) {
			break;
		}
		for (int i = head[u]; ~i; i = edge[i].nxt) {
			int v = edge[i].to;
			if (dy[v] == -1) {
				dy[v] = dx[u] + 1;
				if (My[v] == -1) {
					dis = dy[v];
				}
				else {
					dx[My[v]] = dy[v] + 1;
					Q.push(My[v]);
				}
			}
		}
	}
	return dis != inf;
}

bool dfs(int u) {
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int v = edge[i].to;
		if (!used[v] && dy[v] == dx[u] + 1) {
			used[v] = 1;
			if (My[v] != -1 && dy[v] == dis) {
				continue;
			}
			if (My[v] == -1 || dfs(My[v])) {
				My[v] = u;
				Mx[u] = v;
				return 1;
			}
		}
	}
	return 0;
}

int MaxMatch() {
	int res = 0;
	memset(Mx, -1, sizeof(Mx));
	memset(My, -1, sizeof(My));
	while (SearchP()) {
		memset(used, 0, sizeof(used));
		for (int i = 1; i <= uN; ++i) {
			if (Mx[i] == -1 && dfs(i)) {
				++res;
			}
		}
	}
	return res;
}

int main() {
	getprime();
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		memset(vis, 0, sizeof(vis));
		memset(head, -1, sizeof(head));
		tot = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &Arr[i]);
			vis[Arr[i]] = i;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j * j <= Arr[i]; ++j) {
				if (Arr[i] % j == 0) {
					if (vis[j] && prime[Arr[i] / j]) {
						addedge(i, vis[j]);
						addedge(vis[j], i);
					}
					if (Arr[i] / j != j && prime[j] && vis[Arr[i] / j]) {
						addedge(i, vis[Arr[i] / j]);
						addedge(vis[Arr[i] / j], i);
					}
				}
			}
		}
		uN = n;
		printf("Case %d: %d\n", icase++, uN - MaxMatch() / 2);
	}
	return 0;
}
