/*************************************************************************
    > File Name: LightOJ1406.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年09月22日 星期二 16时38分52秒
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

int dp[(1 << 15) + 10];
const int N = 20;
bool link[(1 << 15) + 10];
bool vis[(1 << 15) + 10][16];
int head[N], tot;
vector <int> G[N];

void dfs(int mask, int u) {
	link[mask] = 1;
	int size = G[u].size();
	for (int i = 0; i < size; ++i) {
		int v = G[u][i];
		if (!vis[mask | (1 << v)][v]) {
			vis[mask | (1 << v)][v] = 1;
			dfs(mask | (1 << v), v);
		}
	}
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m, u, v;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			G[i].clear();
		}
		memset(dp, inf, sizeof(dp));
		dp[0] = 0;
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d", &u, &v);
			--u, --v;
			G[u].push_back(v);
		}
		memset(link, 0, sizeof(link));
		for (int i = 0; i < n; ++i) {
			memset(vis, 0, sizeof(vis));
			vis[(1 << i)][i] = 1;
			dfs((1 << i), i);
		}
		for (int i = 1; i < (1 << n); ++i) {
			for (int j = i; j; j = (j - 1) & i) {
				if (link[j]) {
					dp[i] = min(dp[i], dp[i - j] + 1);
				}
			}
		}
		printf("Case %d: %d\n", icase++, dp[(1 << n) - 1]);
	}
	return 0;
}
