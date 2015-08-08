/*************************************************************************
    > File Name: LightOJ1161.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月08日 星期六 13时39分30秒
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

int cnt[10010];
LL ans[10010];

int main() {
	int t, icase = 1, n, u;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &u);
			for (int j = 1; j * j <= u; ++j) {
				if (u % j == 0) {
					++cnt[j];
					if (u / j != j) {
						++cnt[u / j];
					}
				}
			}
		}
		for (int i = 10000; i >= 1; --i) {
			ans[i] = (LL)cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) * (cnt[i] - 3) / 24;
			for (int j = 2 * i; j <= 10000; j += i) {
				ans[i] -= ans[j];
			}
		}
		printf("Case %d: %lld\n", icase++, ans[1]);
	}
	return 0;
}
