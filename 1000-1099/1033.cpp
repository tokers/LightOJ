/*************************************************************************
    > File Name: LightOJ1033.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月12日 星期五 20时36分57秒
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

int dp[110][110];
char str[110];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", str);
		int n = strlen(str);
		memset(dp, inf, sizeof(dp));
		for (int i = 0; i < n; ++i) {
			dp[i][i] = 0;
		}
		for (int i = n - 1; i >= 0; --i) {
			for (int j = i + 1; j < n; ++j) {
				if (str[i] == str[j]) {
					if (i + 1 == j) {
						dp[i][j] = 0;
					}
					else {
						dp[i][j] = dp[i + 1][j - 1];
					}
				}
				else {
					dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
				}
			}
		}
		printf("Case %d: %d\n", icase++, dp[0][n - 1]);
	}
	return 0;
}
