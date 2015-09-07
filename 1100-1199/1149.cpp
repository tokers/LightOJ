/*************************************************************************
    > File Name: LightOJ1149.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年09月07日 星期一 10时33分29秒
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

const int N = 110;
bool edge[N][N];
int match[N];
bool vis[N];
int n, m;

bool dfs(int u) {
	for (int i = 1; i <= m; ++i) {
		if (edge[u][i] && !vis[i]) {
			vis[i] = 1;
			if (match[i] == -1 || dfs(match[i])) {
				match[i] = u;
				return 1;
			}
		}
	}
	return 0;
}

int hungry() {
	memset(match, -1, sizeof(match));
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		memset(vis, 0, sizeof(vis));
		if (dfs(i)) {
			++ans;
		}
	}
	return ans;
}

int A[N], B[N];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &A[i]);
		}
		scanf("%d", &m);
		for (int i = 1; i <= m; ++i) {
			scanf("%d", &B[i]);
		}
		memset(edge, 0, sizeof(edge));
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (B[i] % A[j] == 0) {
					edge[j][i] = 1;
				}
			}
		}
		printf("Case %d: %d\n", icase++, hungry());
	}
	return 0;
}
