/*************************************************************************
    > File Name: LightOJ1352.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年09月10日 星期四 18时24分52秒
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

LL dp[70][70][2];
int bit[70];
LL one[70];
int now, len;
LL pre[70][70]; // (2^i以内第j位是1的数个数)

LL dfs(int cur, bool ok, bool flag) {
	if (cur == -1) {
		return ok;
	}
	if (!flag && ~dp[cur][now][ok]) {
		return dp[cur][now][ok];
	}
	int end = flag ? bit[cur] : 1;
	LL res = 0;
	for (int i = 0; i <= end; ++i) {
		res += dfs(cur - 1, ok || (i && now == cur), flag && i == end);
	}
	if (!flag) {
		dp[cur][now][ok] = res;
	}
	return res;
}

LL calc(LL n, int x) {
	int cnt = 0;
	while (n) {
		bit[cnt++] = (n & 1);
		n >>= 1;
	}
	LL res = 0;
	now = x;
	res = dfs(cnt - 1, 0, 1);
	return res;
}

void go(LL n, int sgn) {
	LL m = n;
	int cnt = 0;
	while (n) {
		++cnt;
		n >>= 1;
	}
	for (int i = cnt - 1; i >= 0; --i) {
		for (int j = cnt; j >= 1; --j) { // 对于j位数来说
			if (j == len) {
				LL x = calc(m, i) - pre[j - 1][i];
				if (x <= 0) {
					continue;
				}
				one[i] += (LL)sgn * x;
			}
			else {
				LL x;
				if (j == cnt) {
					x = calc(m, i) - pre[j - 1][i];
				}
				else {
					x = pre[j][i] - pre[j - 1][i];
				}
				one[i + (len - j)] += (LL)sgn * x;
			}
		}
	}
}

int main() {
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < 63; ++i) {
		for (int j = 0; j <= i; ++j) {
			pre[i][j] = calc((1LL << i) -1, j);
		}
	}
	LL a, b;
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		memset(one, 0, sizeof(one));
		scanf("%lld%lld", &a, &b);
		LL tmp = b;
		len = 0;
		while (tmp) {
			tmp >>= 1;
			++len;
		}
		go(b, 1);
		go(a - 1, -1);
		LL res = 0;
		for (int i = len - 1; i >= 0; --i) {
			res <<= 1;
			res += (one[i] & 1);
		}
		printf("Case %d: %lld\n", icase++, res);
	}
	return 0;
}
