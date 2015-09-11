/*************************************************************************
    > File Name: LightOJ1230.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年09月10日 星期四 21时15分54秒
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

int dp[1010][2];
int f[1010][2];
bool vis[1010];
vector < vector<int> > tree;

void dfs(int u, int fa) {
	vis[u] = 1;
	int size = tree[u].size();
	dp[u][0] = 0;
	dp[u][1] = 1;
	f[u][0] = 0;
	f[u][1] = 0;
	for (int i = 0; i < size; ++i) {
		int v = tree[u][i];
		if (v == fa) {
			continue;
		}
		dfs(v, u);
		dp[u][0] += dp[v][1];
		f[u][0] += f[v][1];
		if (dp[v][0] < dp[v][1]) {
			dp[u][1] += dp[v][0];
			f[u][1] += f[v][0];
		}
		else if (dp[v][0] > dp[v][1]) {
			dp[u][1] += dp[v][1];
			f[u][1] += f[v][1] + 1;
		}
		else {
			dp[u][1] += dp[v][1];
			f[u][1] += max(f[v][1] + 1, f[v][0]);
		}
	}
//	printf("dp[%d][0] = %d, dp[%d][1] = %d\n", u, dp[u][0], u, dp[u][1]);
//	printf("f[%d][0] = %d, f[%d][1] = %d\n", u, f[u][0], u, f[u][1]);
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		memset(vis, 0, sizeof(vis));
		tree.assign(n + 1, vector <int> ());
		int u, v;
		for (int i = 0; i < m; ++i) {
			scanf("%d%d", &u, &v);
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		int res1 = 0, res2 = 0;
		for (int i = 0; i < n; ++i) {
			if (!vis[i]) {
				dfs(i, -1);
				if (dp[i][0] < dp[i][1]) {
					res1 += dp[i][0];
					res2 += f[i][0];
				}
				else if (dp[i][0] > dp[i][1]) {
					res1 += dp[i][1];
					res2 += f[i][1];
				}
				else {
					res1 += dp[i][1];
					res2 += max(f[i][1], f[i][0]);
				}
			}
		}
		printf("Case %d: %d %d %d\n", icase++, res1, res2, m - res2);
	}
	return 0;
}
