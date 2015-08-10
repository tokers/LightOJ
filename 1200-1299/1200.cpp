/*************************************************************************
    > File Name: LightOJ1200.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月10日 星期一 13时05分05秒
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

int dp[10010];
PLL Arr[110];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		memset(dp, 0, sizeof(dp));
		int n, V, need;
		scanf("%d%d", &n, &V);
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d%d", &Arr[i].first, &need, &Arr[i].second);
			V -= need * Arr[i].second;
		}
		if (V < 0) {
			printf("Case %d: Impossible\n", icase++);
			continue;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = Arr[i].second; j <= V; ++j) {
				dp[j] = max(dp[j], dp[j - Arr[i].second] + Arr[i].first);
			}
		}
		printf("Case %d: %d\n", icase++, dp[V]);
	}
	return 0;
}
