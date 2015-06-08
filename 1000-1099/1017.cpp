/*************************************************************************
    > File Name: LightOJ1017.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月08日 星期一 19时26分07秒
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

map <int, int> st;
int dp[110][110];

struct node {
	int num;
	int y;
}p[110];

int cmp(node a, node b) {
	return a.y > b.y;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		st.clear();
		int n, w, k;
		int x, y;
		scanf("%d%d%d", &n, &w, &k);
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", &x, &y);
			if (st.find(y) == st.end()) {
				st[y] = 1;
			}
			else {
				++st[y];
			}
		}
		int cnt = 0;
		for (map <int, int> :: iterator it = st.begin(); it != st.end(); ++it) {
			p[++cnt].y = it -> first;
			p[cnt].num = it -> second;
		}
		sort(p + 1, p + cnt + 1, cmp);
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= cnt; ++i) {
			for (int j = 1; j <= k; ++j) {
				dp[i][j] = dp[i - 1][j];
				int sum = 0;
				for (int l = i; l >= 1; --l) {
					if (p[l].y > p[i].y + w) {
						break;
					}
					sum += p[l].num;
					dp[i][j] = max(dp[i][j], dp[l - 1][j - 1] + sum);
				}
			}
		}
		printf("Case %d: %d\n", icase++, dp[cnt][k]);
	}
	return 0;
}
