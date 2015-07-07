/*************************************************************************
    > File Name: LightOJ1098.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月27日 星期六 15时01分49秒
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

const int N = 2000000;

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		LL n;
		scanf("%lld", &n);
		LL ans = 0;
		if (n <= 1) {
			ans = 0;
		}
		else {
			ans = -LL(n - 2) * (n + 1) / 2;
			for (LL i = 1; i * i <= n; ++i) {
				if (i != n / i) {
					LL tmp1 = n / i;
					ans += tmp1 * i;
					LL r = n / i;
					LL l = n / (i + 1) + 1;
					ans += (r - l + 1) * (l + r) / 2 * i;
				}
				else {
					ans += n / i * i;
				}
			}
			ans -= (LL)2 * n;
		}
		printf("Case %d: %lld\n", icase++, ans);
	}
	return 0;
}
