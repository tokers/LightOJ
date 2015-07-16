/*************************************************************************
    > File Name: LightOJ1116.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月16日 星期四 09时58分58秒
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

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		LL n, m;
		scanf("%lld", &n);
		m = n;
		int cnt = 0;
		while (n % 2 == 0) {
			n >>= 1;
			++cnt;
		}
		if (cnt == 0) {
			printf("Case %d: Impossible\n", icase++);
			continue;
		}
		printf("Case %d: %lld %lld\n", icase++, m / (1LL << cnt), (1LL << cnt));
	}
	return 0;
}
