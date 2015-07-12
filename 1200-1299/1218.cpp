/*************************************************************************
    > File Name: LightOJ1282.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月12日 星期日 11时03分23秒
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

int fastpow(int a, int cnt, int mod) {
	a %= mod;
	LL ret = 1;
	while (cnt) {
		if (cnt & 1) {
			ret *= a;
			ret %= mod;
		}
		cnt >>= 1;
		a = (LL)a * a % mod;
	}
	return ret;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		int b = fastpow(n, k, 1000);
		int pos = (int)(k * log10(n * 1.0)) + 1;
		double x = k * log10(n * 1.0) - (pos - 3);
		x = pow(10, x);
		printf("Case %d: %.0f %03d\n", icase++, x - 0.5, b);
	}
	return 0;
}
