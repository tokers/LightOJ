/*************************************************************************
    > File Name: LightOJ1424.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月14日 星期五 16时25分23秒
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

const int N = 2010;
char str[N][N];
int sum[N][N]; // 第i列, 前j行连续0长度
int L[N], R[N];
PLL St[N];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%s", str[i] + 1);
		}
		memset (sum, 0, sizeof(sum));
		for (int j = 1; j <= m; ++j) {
			for (int i = 1; i <= n; ++i) {
				if (str[i][j] == '1') {
					sum[j][i] = 0;
				}
				else {
					sum[j][i] = 1;
					if (i > 1) {
						sum[j][i] += sum[j][i - 1];
					}
				}
			}
		}
		int ans = 0;
		int tp;
		for (int i = 1; i <= n; ++i) {
			tp = 0;
			for (int j = 1; j <= m; ++j) {
				while (tp > 0) {
					PLL u = St[tp];
					if (u.first > sum[j][i]) {
						--tp;
						R[u.second] = j - 1;
					}
					else {
						break;
					}
				}
				St[++tp] = make_pair(sum[j][i], j);
			}
			while (tp > 0) {
				PLL u = St[tp--];
				R[u.second] = m;
			}
			tp = 0;
			for (int j = m; j >= 1; --j) {
				while (tp > 0) {
					PLL u = St[tp];
					if (u.first > sum[j][i]) {
						--tp;
						L[u.second] = j + 1;
					}
					else {
						break;
					}
				}
				St[++tp] = make_pair(sum[j][i], j);
			}
			while (tp > 0) {
				PLL u = St[tp--];
				L[u.second] = 1;
			}
			for (int j = 1; j <= m; ++j) {
				int l = L[j], r = R[j];
				ans = max(ans, sum[j][i] * (r - l + 1));
			}
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
