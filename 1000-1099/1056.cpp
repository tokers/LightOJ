/*************************************************************************
    > File Name: LightOJ1056.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月08日 星期三 16时24分37秒
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
const double eps = 1e-9;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> PLL;
const LL INF = (1LL << 60);

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d%*c%*c%*c%d", &a, &b);
		double rr = a * 1.0 / b;
		double ang = 2 * asin(1.0 / sqrt(rr * rr + 1));
		double l = 0, r = 200, mid, ans;
		while (l <= r) {
			mid = (l + r) / 2;
			double tmp = ang / 2 * sqrt(rr * rr + 1) + rr;
			tmp *= mid;
			if (tmp - 200 > eps) {
				r = mid;
			}
			else if (200 - tmp > eps) {
				l = mid;
			}
			else {
				ans = mid;
				break;
			}
		}
		double ans2 = ans * rr;
		printf("Case %d: %.12f %.12f\n", icase++, ans2, ans);
	}
	return 0;
}
