/*************************************************************************
    > File Name: LightOJ1140.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月03日 星期一 10时45分54秒
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

int bit[11];
LL dp[11][11][2];

LL dfs(int cur, int cnt, bool flag, bool ok) {
	if (cur == -1) {
		return cnt == 0;
	}
	if (!flag && ~dp[cur][cnt][ok]) {
		return dp[cur][cnt][ok];
	}
	LL ans = 0;
	int end = flag ? bit[cur] : 9;
	for (int i = 0; i <= end; ++i) {
		if (cnt - (i == 0) < 0) {
			continue;
		}
		if (ok == 1 || (ok == 0 && i)) {
			ans += dfs(cur - 1, cnt - (i == 0), flag && i == end, 1);
		}
		else {
			ans += dfs(cur - 1, cnt, flag && i == end, 0);
		}
	}
	if (!flag) {
		dp[cur][cnt][ok] = ans;
	}
	return ans;
}

LL calc(LL n) {
	int cnt = 0;
	if (n == 0) {
		bit[cnt++] = 0;
	}
	while (n) {
		bit[cnt++] = n % 10;
		n /= 10;
	}
	LL ans = 0;
	for (int i = 1; i <= 9; ++i) {
		LL num = dfs(cnt - 1, i, 1, 0);
		ans += (LL)i * num;
	}
	return ans;
}

int main() {
	int t, icase = 1;
	memset(dp, -1, sizeof(dp));
	scanf("%d", &t);
	while (t--) {
		LL a, b;
		scanf("%lld%lld", &a, &b);
		LL ans = calc(b);
		if (a >= 1) {
			ans -= calc(a - 1);
		}
		else {
			++ans;
		}
		printf("Case %d: %lld\n", icase++, ans);
	}
	return 0;
}
