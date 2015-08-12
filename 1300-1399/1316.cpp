/*************************************************************************
    > File Name: LightOJ1316.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月12日 星期三 12时50分02秒
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

int edge[510][510];
vector <PLL> edge2[510];
int dp[(1 << 16) + 10][16]; // vis status
int po[16];
int mat[16][16];
int dist[510][510];

void spfa(int s) {
	memset(dist[s], inf, sizeof(dist[s]));
	dist[s][s] = 0;
	queue <int> qu;
	qu.push(s);
	while (!qu.empty()) {
		int u = qu.front();
		qu.pop();
		int size = edge2[u].size();
		for (int i = 0; i < size; ++i) {
			int v = edge2[u][i].first;
			int w = edge2[u][i].second;
			if (dist[s][v] > dist[s][u] + w) {
				dist[s][v] = dist[s][u] + w;
				qu.push(v);
			}
		}
	}
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m, s;
		scanf("%d%d%d", &n, &m, &s);
		memset(edge, inf, sizeof(edge));
		memset(dp, inf, sizeof(dp));
		int u, v, w;
		for (int i = 0; i < s; ++i) {
			scanf("%d", &po[i]);
		}
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d%d", &u, &v, &w);
			edge[u][v] = min(edge[u][v], w);
		}
		for (int i = 0; i < n; ++i) {
			edge2[i].clear();
			for (int j = 0; j < n; ++j) {
				if (edge[i][j] != inf) {
					edge2[i].push_back(make_pair(j, edge[i][j]));
				}
			}
		}
		for (int i = 0; i < s; ++i) {
			spfa(po[i]);
			for (int j = 0; j < s; ++j) {
				mat[i][j] = dist[po[i]][po[j]];
				if (mat[i][j] != inf) {
				}
			}
			mat[i][i] = 0;
		}
		spfa(0);
		for (int i = 0; i < s; ++i) {
			dp[(1 << i)][i] = dist[0][po[i]];
		}
		for (int i = 0; i < (1 << s); ++i) {
			for (int j = 0; j < s; ++j) {
				if (i & (1 << j)) {
					for (int k = 0; k < s; ++k) {
						if (i & (1 << k)) {
							continue;
						}
						int &res = dp[i | (1 << k)][k];
						res = min(res, dp[i][j] + mat[j][k]);
					}
				}
			}
		}
		int ans1 = 0, dis = inf;
		for (int i = 0; i < (1 << s); ++i) {
			int cnt = 0;
			for (int j = 0; j < s; ++j) {
				if (i & (1 << j)) {
					++cnt;
				}
			}
			for (int j = 0; j < s; ++j) {
				if (dp[i][j] != inf)  {
					if (ans1 < cnt && dist[po[j]][n - 1] < inf) {
						ans1 = cnt, dis = dp[i][j] + dist[po[j]][n - 1];
					}
					else if (ans1 == cnt) {
						dis = min(dis, dp[i][j] + dist[po[j]][n - 1]);
					}
				}
			}
		}
		if (dis >= inf) {
			ans1 = 0;
			if (dist[0][n - 1] >= inf) {
				printf("Case %d: Impossible\n", icase++);
			}
			else {
				printf("Case %d: %d %d\n", icase++, 0, dist[0][n - 1]);
			}
		}
		else {
			printf("Case %d: %d %d\n", icase++, ans1, dis);
		}
	}
	return 0;
}
