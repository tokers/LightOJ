/*************************************************************************
    > File Name: LightOJ1054.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月07日 星期二 16时18分00秒
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
int prime[100000];
int INV[100000];
bool valid[100000];
int tot;

void getprime() {
	int n = 66000;
	valid[1] = 0;
	for (int i = 2; i <= n; ++i) {
		valid[i] = 1;
	}
	for (int i = 2; i <= n; ++i) {
		if (valid[i]) {
			if (n / i < i) {
				break;
			}
			for (int j = i * i; j <= n; j += i) {
				valid[j] = 0;
			}
		}
	}
	tot = 0;
	for (int i = 2; i <= n; ++i) {
		if (valid[i]) {
			prime[++tot] = i;
		}
	}
}

LL ex_gcd(LL a, LL b, LL &x, LL &y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}
	LL gcd = ex_gcd(b, a % b, x, y);
	LL t = x;
	x = y;
	y = t - (a / b) * x;
	return gcd;
}

LL inverse(LL num) {
	LL x, y;
	ex_gcd(num, mod, x, y);
	return (x % mod + mod) % mod;
}

LL fastpow(LL a, LL cnt) {
	LL ans = 1;
	while (cnt) {
		if (cnt & 1) {
			ans *= a;
			ans %= mod;
		}
		cnt >>= 1;
		a *= a;
		a %= mod;
	}
	return ans;
}

int main() { 
	getprime();
	for (int i = 1; i <= tot; ++i) {
		INV[prime[i] - 1] = inverse(prime[i] - 1);
	}
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		 LL n, m;
		 scanf("%lld%lld", &n, &m);
		 LL ans = 1;
		 for (int i = 1; (LL)prime[i] * prime[i] <= n; ++i) {
		 	 if (n % prime[i] == 0) {
			 	 LL cnt = 0;
			 	 while (n % prime[i] == 0) {
				 	 n /= prime[i];
				 	 ++cnt;
				 }
				 cnt = cnt * m + 1;
				 LL res = fastpow(prime[i], cnt);
				 res = (res - 1 + mod) % mod;
				 LL inv = INV[prime[i] - 1];
				 res *= inv;
				 res %= mod;
				 ans *= res;
				 ans %= mod;
			 }
		 }
		 if (n > 1) {
			LL res = fastpow(n, m + 1);
			res = (res - 1 + mod) % mod;
			LL inv = inverse(n - 1);
			res *= inv;
			res %= mod;
			ans *= res;
			ans %= mod;
		 }
		 printf("Case %d: %lld\n", icase++, ans);
	}
	return 0;
}
