/*************************************************************************
    > File Name: LightOJ1032.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月12日 星期五 18时04分26秒
 ************************************************************************/

#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <set>
#include <vector>

using namespace std;

const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef pair <int, int> PLL;

LL dp[40][2][40][40];
int bit[40];
int m;

LL dfs(int cur, int e, int getO, bool flag) {
	if (cur == -1) {
		return getO == 0;
	}
	if (!flag && ~dp[cur][e][getO][m]) {
		return dp[cur][e][getO][m];
	}
	LL ans = 0;
	int end = flag ? bit[cur] : 1;
	for (int i = 0; i <= end; ++i) {
		if (getO >= (i && e)) {
			ans += dfs(cur - 1, i, getO - (i && e), flag && i == end);
		}
	}
	if (!flag) {
		dp[cur][e][getO][m] = ans;
	}
	return ans;
}

LL calc(int n) {
	int cnt = 0;
	while (n) {
		bit[cnt++] = n & 1;
		n >>= 1;
	}
	LL ans = 0;
	for (int i = 1; i <= 32; ++i) {
		m = i;
		ans += dfs(cnt - 1, 0, i, 1) * i;
	}	
	return ans;
}

int main() {
	memset(dp, -1, sizeof(dp));
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("Case %d: %lld\n", icase++, calc(n));
	}
	return 0;
}
