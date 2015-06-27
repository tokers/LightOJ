/*************************************************************************
    > File Name: LightOJ1051.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月27日 星期六 19时21分08秒
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

bool dp[55][2];
char str[55];
int sta[55];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", str);
		memset(dp, 0, sizeof(dp));
		memset(sta, 0, sizeof(sta));
		int len = strlen(str);
		for (int i = 0; i < len; ++i) {
			if (str[i] == '?') {
				sta[i + 1] == 0;
			}
			else {
				if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
					sta[i + 1] = -1;
				}
				else {
					sta[i + 1] = 1;
				}
			}
		}
		bool bads = 0;
		for (int i = 1; i <= len; ++i) {
			if (i >= 3) {
				if (sta[i] <= 0 && sta[i - 1] <= 0 && sta[i - 2] <= 0) {
					bads = 1;
					break;
				}
			}
			if (i >= 5) {
				if (sta[i] >= 0 && sta[i - 1] >= 0 && sta[i - 2] >= 0 && sta[i - 3] >= 0 && sta[i - 4] >= 0) {
					bads = 1;
					break;
				}
			}
		}
		if (!bads) {
			printf("Case %d: GOOD\n", icase++);
			continue;
		}
		dp[0][0] = 1;
		dp[0][1] = 1;
		for (int i = 1; i <= len; ++i) {
			if (i < 3) {
				if (sta[i] <= 0) {
					dp[i][0] = 1;
				}
				if (sta[i] >= 0) {
					dp[i][1] = 1;
				}
			}
			else {
				if (sta[i] <= 0) {
					if (sta[i - 1] >= 0) {
						dp[i][0] = (dp[i - 1][1] || dp[i][0]);
					}
					if (sta[i - 1] <= 0 && sta[i - 2] >= 0) {
						dp[i][0] = (dp[i - 2][1] || dp[i][0]);
					}
				}
				if (sta[i] >= 0) {
					if (sta[i - 1] <= 0) {
						dp[i][1] = (dp[i][1] || dp[i - 1][0]);
					}
					if (sta[i - 1] >= 0) {
						if (sta[i - 2] <= 0) {
							dp[i][1] = (dp[i][1] || dp[i - 2][0]);
						}
						if (sta[i - 2] >= 0) {
							if (sta[i - 3] <= 0) {
								dp[i][1] = (dp[i][1] || dp[i - 3][0]);
							}
							if (sta[i - 3] >= 0) {
								if (sta[i - 4] <= 0) {
									dp[i][1] = (dp[i][1] || dp[i - 4][0]);
								}
							}
						}
					}
				}
			}
		}
		bool goods = dp[len][0] || dp[len][1];
		if (goods) {
			printf("Case %d: MIXED\n", icase++);
		}
		else {
			printf("Case %d: BAD\n", icase++);
		}
	}
	return 0;
}
