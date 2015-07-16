/*************************************************************************
    > File Name: LightOJ1102.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月16日 星期四 20时01分19秒
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
const int mod = 1000000007;

int exgcd(int a, int b, int &x, int &y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}
	int gcd = exgcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - (a / b) * x;
	return gcd;
}

int inverse(int num) {
	int x, y;
	exgcd(num, mod, x, y);
	return (x % mod + mod) % mod;
}

int fac[2000100];
int main() {
	fac[0] = 1;
	for (int i = 1; i <= 2000000; ++i) {
		fac[i] = (LL)fac[i - 1] * i % mod;
	}
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		int a = n + k - 1;
		int b = k - 1;
		int ans = fac[a];
		ans = (LL)ans * inverse((LL)fac[b] * fac[a - b] % mod) % mod;
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}

