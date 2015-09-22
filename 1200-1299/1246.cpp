/*************************************************************************
    > File Name: LightOJ1246.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年09月22日 星期二 15时50分54秒
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
int C[510][510];
int a[510], b[510];

void init() {
	C[0][0] = 1;
	for (int i = 1; i <= 500; ++i) {
		C[i][0] = 1;
		C[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
		}
	}
}

int main() {
	init();
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		++n, ++m;
		int black = (m / 2 + (m & 1)) * (n / 2 + (n & 1)) + (m / 2) * (n / 2);
		int white = n * m - black;
		int ans = 0;
		if (white == 0) {
			printf("Case %d: %d\n", icase++, k);
			continue;
		}
		for (int i = 1; i <= k; ++i) {
			a[i] = 1;
			for (int j = 1; j <= black; ++j) {
				a[i] = (LL)a[i] * i % mod;
			}
			b[i] = 1;
			for (int j = 1; j <= white; ++j) {
				b[i] = (LL)b[i] * i % mod;
			}
		}
		for (int i = 2; i <= k; ++i) {
			int res = 0;
			for (int j = 1; j < i; ++j) {
				if (black < j || white < i - j) {
					continue;
				}
				int sgn = 1;
				int res1 = 0, res2 = 0;
				for (int x = j; x >= 1; --x) {
					res1 += (LL)sgn * C[j][x] * a[x] % mod;
					res1 %= mod;
					sgn *= -1;
				}
				res1 = (res1 + mod) % mod;
				sgn = 1;
				for (int x = i - j; x >= 1; --x) {
					res2 += (LL)sgn * C[i - j][x] * b[x] % mod;
					res2 %= mod;
					sgn *= -1;
				}
				res2 = (res2 + mod) % mod;
				res += (LL)C[i][j] * res1 % mod * res2 % mod;
				res %= mod;
			}
			res = (LL)res * C[k][i] % mod;
			ans += res;
			ans %= mod;
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
