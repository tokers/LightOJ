/*************************************************************************
    > File Name: LightOJ1197.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月11日 星期六 13时32分32秒
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

bool valid[100010];
int prime[100010];
int prime2[100010];
int ret;
int tot;

void getPrime() {
	int n =100000;
	for (int i = 2; i <= n; ++i) {
		valid[i] = 1;
	}
	valid[1] = 0;
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

void SegPrime(int L, int R) {
	for (int i = 0; i <= R - L; ++i) {
		valid[i] = 1;
	}
	if (L < 2) {
		L = 2;
	}
	for (int i = 1; i <= tot && (LL)prime[i] * prime[i] <= R; ++i) {
		int s = L / prime[i] + (L % prime[i] > 0);
		if (s == 1) {
			s = 2;
		}
		for (int j = s; (LL)j * prime[i] <= R; ++j) {
			if ((LL)j * prime[i] >= L) {
				valid[(LL)j * prime[i] - L] = 0;
			}
		}
	}
	ret = 0;
	for (int i = 0; i <= R - L; ++i) {
		if (valid[i]) {
			prime2[++ret] = i + L;
		}
	}
}

int main() {
	int t, icase = 1;
	getPrime();
	scanf("%d", &t);
	while (t--) {
		int l, r;
		scanf("%d%d", &l, &r);
		SegPrime(l, r);
		printf("Case %d: %d\n", icase++, ret);
	}
	return 0;
}
