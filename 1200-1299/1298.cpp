/*************************************************************************
    > File Name: LightOJ1298.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月19日 星期三 10时05分15秒
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
int dp[510][510];
int prime[10100];
int tot;
bool vis[10100];

void getPrime() {
	tot = 0;
	for (int i = 2; i <= 10000; ++i) {
		vis[i] = 1;
	}
	vis[1] = 0;
	for (int i = 2; i <= 10000; ++i) {
		if (vis[i]) {
			if (10000 / i < i) {
				break;
			}
			for (int j = i * i; j <= 10000; j += i) {
				vis[j] = 0;
			}
		}
	}
	for (int j = 2; j <= 10000; ++j) {
		if (vis[j]) {
			prime[++tot] = j;
		}
	}
}

int main() {
	getPrime();
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 1; i <= 500; ++i) {
		for (int j = 1; j <= i; ++j) {
			dp[i][j] += (LL)dp[i - 1][j - 1] * (prime[j] - 1) % mod;
			dp[i][j] += (LL)dp[i - 1][j] * prime[j] % mod;
			dp[i][j] %= mod;
		}
	}
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int K, P;
		scanf("%d%d", &K, &P);
		printf("Case %d: %d\n", icase++, dp[K][P]);
	}
	return 0;
}
