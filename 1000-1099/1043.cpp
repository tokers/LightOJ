/*************************************************************************
    > File Name: LightOJ1043.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月24日 星期三 21时47分24秒
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
		double AB, AC, BC, r;
		scanf("%lf%lf%lf%lf", &AB, &AC, &BC, &r);
		double ans = AB * sqrt(r / (r + 1));
		printf("Case %d: %.12f\n", icase++, ans);
	}
	return 0;
}
