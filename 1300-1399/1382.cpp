/*************************************************************************
    > File Name: LightOJ1382.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月05日 星期三 14时10分29秒
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

int C[1100][1100];
int dp[1100];
int In[1100];
int sum[1100];

const int mod = 1000000007;
vector <int> tree[1100];

void init() {
	C[0][0] = 1;
	for (int i = 1; i <= 1000; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			C[i][j] %= mod;
		}
	}
}

void dfs(int u) {
	dp[u] = 1;
	sum[u] = 1;
	int size = tree[u].size();
	for (int i = 0; i < size; ++i) {
		int v = tree[u][i];
		dfs(v);
		sum[u] += sum[v];
	}
	int num = sum[u] - 1;
	for (int i = 0; i < size; ++i) {
		int v = tree[u][i];
		dp[u] = (LL)dp[u] * C[num][sum[v]] % mod * dp[v] % mod;
		num -= sum[v];
	}
}

int main() {
	int t, icase = 1;
	init();
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		memset(In, 0, sizeof(In));
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; ++i) {
			tree[i].clear();
		}
		int u, v;
		for (int i = 1; i <= n - 1; ++i) {
			scanf("%d%d", &u, &v);
			tree[u].push_back(v);
			++In[v];
		}
		int root;
		for (int i = 1; i <= n; ++i) {
			if (In[i] == 0) {
				root = i;
				break;
			}
		}
		dfs(root);
		printf("Case %d: %d\n", icase++, dp[root]);
	}
	return 0;
}
