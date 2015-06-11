/*************************************************************************
    > File Name: LightOJ1028.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月11日 星期四 17时56分51秒
 ************************************************************************/

#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <set>
#include <vector>

using namespace std;

const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef pair <int, int> PLL;

int prime[2000100];
bool isprime[2000100];
int cnt;

void getPrime() {
	cnt = 0;
	isprime[1] = 0;
	for (int i = 2; i <= 2000000; ++i) {
		isprime[i] = 1;
	}
	for (int i = 2; i <= 2000000; ++i) {
		if (isprime[i]) {
			if (2000000 / i < i) {
				break;
			}
			for (int j = i * i; j <= 2000000; j += i) {
				isprime[j] = 0;
			}
		}
	}
	for (int i = 2; i <= 2000000; ++i) {
		if (isprime[i]) {
			prime[++cnt] = i;
		}
	}
}

int main() {
	getPrime();
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		LL n;
		LL ans = 1;
		scanf("%lld", &n);
		for (int i = 1; (LL)prime[i] * prime[i] <= n; ++i) {
			if (n % prime[i] == 0) {
				int cnt = 0;
				while (n % prime[i] == 0) {
					n /= prime[i];
					++cnt;
				}
				ans *= (cnt + 1);
			}
		}
		if (n > 1) {
			ans *= 2;
		}
		--ans;
		printf("Case %d: %lld\n", icase++, ans);
	}
	return 0;
}
