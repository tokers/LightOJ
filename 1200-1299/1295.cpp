/*************************************************************************
    > File Name: LightOJ1295.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年09月15日 星期二 16时58分29秒
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

int dp[1010];
struct Light {
	int vi, ki, ci, li;
	bool operator < (const Light &b) const {
		return vi < b.vi;
	}
}light[1010];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		memset(dp, inf, sizeof(dp));
		dp[0] = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d%d%d", &light[i].vi, &light[i].ki, &light[i].ci, &light[i].li);
		}
		sort(light + 1, light + 1 + n);
		for (int i = 1; i <= n; ++i) {
			int cnt = 0;
			for (int j = i; j >= 1; --j) {
				cnt += light[j].li;
				dp[i] = min(dp[i], dp[j - 1] + cnt * light[i].ci + light[i].ki);
			}
		}
		printf("Case %d: %d\n", icase++, dp[n]);
	}
	return 0;
}
