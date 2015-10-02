/*************************************************************************
    > File Name: LightOJ1137.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年10月02日 星期五 19时44分18秒
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
const double eps = 1e-18;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> PLL;
const LL INF = (1LL << 60);

int main() {
	double L, n, C;
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%lf%lf%lf", &L, &n, &C);
		double l = 0, ang, r = pi, mid;
		while (r - l > eps) {
			mid = (l + r) / 2;
			double val = mid / sin(mid / 2);
			if (val - (2 + 2 * n * C) > eps) {
				r = mid;
			}
			else if (val - (2 + 2 * n * C) < -eps) {
				l = mid;
			}
			else {
				ang = mid;
				break;
			}
		}
		r = L / 2 / sin(ang / 2);
		printf("Case %d: %.12f\n", icase++, r - sqrt(r * r - 0.25 * L * L));
	}
	return 0;
}
