/*************************************************************************
    > File Name: LightOJ1077.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月29日 星期一 18时09分33秒
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

LL gcd(LL a, LL b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		LL x1, y1, x2, y2;
		scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
		printf("Case %d: %lld\n", icase++, gcd(abs(x2 - x1), abs(y2 - y1)) + 1);
	}
	return 0;
}
