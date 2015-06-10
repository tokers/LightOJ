/*************************************************************************
    > File Name: LightOJ1025.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月10日 星期三 19时54分01秒
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

LL dp[66][66];
char str[66];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", str);
		int n = strlen(str);
		memset(dp, 0, sizeof(dp));
		for (int i = n - 1; i >= 0; --i) {
			for (int j = i; j < n; ++j) {
				dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + (str[i] == str[j]);
				if (str[i] != str[j]) {
					dp[i][j] -= dp[i + 1][j - 1];
				}
			}
		}
		printf("Case %d: %lld\n", icase++, dp[0][n - 1]);
	}
	return 0;
}
