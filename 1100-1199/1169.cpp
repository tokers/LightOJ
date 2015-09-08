/*************************************************************************
    > File Name: LightOJ1169.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年09月08日 星期二 16时34分42秒
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
int A[1010];
int B[1010];
int costA[1010];
int costB[1010];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &A[i]);
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &B[i]);
		}
		for (int i = 1; i < n; ++i) {
			scanf("%d", &costA[i]);
		}
		for (int i = 1; i < n; ++i) {
			scanf("%d", &costB[i]);
		}
		memset(dp, inf, sizeof(dp));
		dp[1][0] = A[1], dp[1][1] = B[1];
		for (int i = 2; i <= n; ++i) {
			dp[i][0] = min(dp[i - 1][0] + A[i], dp[i - 1][1] + costB[i - 1] + A[i]);
			dp[i][1] = min(dp[i - 1][1] + B[i], dp[i - 1][0] + costA[i - 1] + B[i]);
		}
		printf("Case %d: %d\n", icase++, min(dp[n][0], dp[n][1]));
	}
	return 0;
}
