/*************************************************************************
    > File Name: LightOJ1307.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年10月08日 星期四 14时59分32秒
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
int len[N];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &len[i]);
		}
		sort(len + 1, len + n + 1);
		LL ans = 0;
		for (int i = 1; i <= n - 2; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int mx = len[i] + len[j];
				if (len[j + 1] >= mx) {
					continue;
				}
				int p = lower_bound(len + j + 1, len + n + 1, mx) - len;
				--p;
				ans += p - j;
			}
		}
		printf("Case %d: %lld\n", icase++, ans);
	}
	return 0;
}
