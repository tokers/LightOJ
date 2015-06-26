/*************************************************************************
    > File Name: LightOJ1039.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月26日 星期五 14时47分02秒
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

const int N = 20000;
bool forbidden[52][3][26];
struct Edge {
	int nxt;
	int to;
}edge[N * 16];
int head[N], tot;
int dist[N];

void addedge(int from, int to) {
	edge[tot].to = to;
	edge[tot].nxt = head[from];
	head[from] = tot++;
}

void spfa(int u) {
	memset(dist, inf, sizeof(dist));
	dist[u] = 0;
	queue <int> qu;
	qu.push(u);
	while (!qu.empty()) {
		int now = qu.front();
		qu.pop();
		for (int i = head[now]; ~i; i = edge[i].nxt) {
			int nxt = edge[i].to;
			if (dist[nxt] > dist[now] + 1) {
				dist[nxt] = dist[now] + 1;
				qu.push(nxt);
			}
		}
	}
}

char x[5], y[5];
char str[3][50];
int n;

bool check(int now) {
	int x = now / 26 / 26 % 26;
	int y = now / 26 % 26;
	int z = now % 26;
	for (int i = 1; i <= n; ++i) {
		if (forbidden[i][0][x] && forbidden[i][1][y] && forbidden[i][2][z]) {
			return 0;
		}
	}
	return 1;
}

int tmp[10];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%s%s", x, y);
		scanf("%d", &n);
		memset(forbidden, 0, sizeof(forbidden));
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < 3; ++j) {
				scanf("%s", str[j]);
				int len = strlen(str[j]);
				for (int k = 0; k < len; ++k) {
					forbidden[i][j][str[j][k] - 'a'] = 1;
				}
			}
		}
		memset(head, -1, sizeof(head));
		tot = 0;
		for (int i = 0; i < 26; ++i) {
			for (int j = 0; j < 26; ++j) {
				for (int k = 0; k < 26; ++k) {
					int u = i * 26 * 26 + j * 26 + k;
					if (!check(u)) {
						continue;
					}
					tmp[0] = i * 26 * 26 + j * 26 + (k - 1 + 26) % 26;
					tmp[1] = i * 26 * 26 + j * 26 + (k + 1) % 26;
					tmp[2] = i * 26 * 26 + (j - 1 + 26) % 26 * 26 + k;
					tmp[3] = i * 26 * 26 + (j + 1) % 26 * 26 + k;
					tmp[4] = (i - 1 + 26) % 26 * 26 * 26 + j * 26 + k;
					tmp[5] = (i + 1) % 26 * 26 * 26 + j * 26 + k;
					for (int l = 0; l < 6; ++l) {
						if (check(tmp[l])) {
							addedge(u, tmp[l]);
						}
					}
				}
			}
		}
		int u = (x[0] - 'a') * 26 * 26 + (x[1] - 'a') * 26 + (x[2] - 'a');
		int v = (y[0] - 'a') * 26 * 26 + (y[1] - 'a') * 26 + (y[2] - 'a');
		int ans;
		if (!check(u) || !check(v)) {
			ans = -1;
		}
		else {
			spfa(u);
			ans = dist[v];
		}
		if (ans == inf) {
			ans = -1;
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
