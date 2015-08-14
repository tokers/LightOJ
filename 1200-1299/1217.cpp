/*************************************************************************
    > File Name: LightOJ1217.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月14日 星期五 15时58分37秒
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

const int N = 1010;
int dp[N][2];
int Arr[N];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &Arr[i]);
		}
		memset(dp, 0, sizeof(dp));
		dp[1][1] = Arr[1];
		for (int i = 2; i <= n; ++i) {
			if (i == 2 || i == n) {
				dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
			}
			else {
				dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
				dp[i][1] = dp[i - 1][0] + Arr[i];
			}
		}
		int ans = dp[n][0];
		memset(dp, 0, sizeof(dp));
		for (int i = 2; i <= n; ++i) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
			dp[i][1] = dp[i - 1][0] + Arr[i];
		}
		ans = max(ans, max(dp[n][1], dp[n][0]));
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
