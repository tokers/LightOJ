/*************************************************************************
    > File Name: LightOJ1419.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月10日 星期一 15时33分23秒
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

int fastpow(int n, int cnt) {
	int ans = 1;
	while (cnt) {
		if (cnt & 1) {
			ans = (LL)ans * n % mod;
		}
		cnt >>= 1;
		n = (LL)n * n % mod;
	}
	return ans;
}

int main() {
	int t, icase =1;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		int ans = 0;
		for (int i = 0; i <= n - 1; ++i) {
			int cnt = __gcd(n, i);
			ans += fastpow(k, cnt);
			ans %= mod;
		}
		ans = (LL)ans * fastpow(n, mod - 2) % mod;
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
