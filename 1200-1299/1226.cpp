/*************************************************************************
    > File Name: LightOJ1226.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年09月09日 星期三 14时31分38秒
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

const int mod = 1e9 + 7;
int fun[1000100];
int inv[1000100];
int dp[1010];
int val[1010];

int mod_pow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = (LL)res * a % mod;
		}
		b >>= 1;
		a = (LL)a * a % mod;
	}
	return res;
}

int main() {
	fun[0] = 1;
	inv[0] = 1;
	for (int i = 1; i <= 1000000; ++i) {
		fun[i] = (LL)fun[i - 1] * i % mod;
		inv[i] = mod_pow(fun[i], mod - 2);
	}
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			dp[i] = 0;
			scanf("%d", &val[i]);
		}
		int sum = 0;
		dp[0] = 1;
		for (int i = 1; i <= n; ++i) {
			sum += val[i];
			int V = (LL)fun[sum - 1] * inv[val[i] - 1] % mod * inv[sum - val[i]] % mod;
			dp[i] = (LL)dp[i - 1] * V % mod;
		}
		printf("Case %d: %d\n", icase++, dp[n]);
	}
	return 0;
}
