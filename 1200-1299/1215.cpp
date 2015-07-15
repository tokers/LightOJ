/*************************************************************************
    > File Name: LightOJ1215.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月15日 星期三 19时44分11秒
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

bool valid[1000100];
int prime[100000];
int tot;

void getPrime() {
	int n = 1000000;
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
	for (int i = 2; i <= 1000000; ++i) {
		if (valid[i]) {
			prime[++tot] = i;
		}
	}
}

LL gcd(LL a, LL b) {
	return b ? gcd(b, a % b) : a;
}

vector < pair<LL, int> > fac;
vector <LL> x;

void dfs(int now, LL num) { 
	if (now == (int)fac.size()) {
		x.push_back(num);
		return;
	}
	dfs(now + 1, num);
	for (int i = 1; i <= (int)fac[now].second; ++i) {
		num *= fac[now].first;
		dfs(now + 1, num);
	}
}

int main() {
	getPrime();
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		LL a, b, L;
		scanf("%lld%lld%lld", &a, &b, &L);
		LL lcm = a * b / gcd(a, b);
		if (L % lcm) {
			printf("Case %d: impossible\n", icase++);
			continue;
		}
		fac.clear();
		LL use = L;
		for (int i = 1; i <= tot && (LL)prime[i] * prime[i] <= L; ++i) {
			if (L % prime[i] == 0) {
				int cnt = 0;
				while (L % prime[i] == 0) {
					L /= prime[i];
					++cnt;
				}
				fac.push_back(make_pair(prime[i], cnt));
			}
		}
		if (L > 1) {
			fac.push_back(make_pair(L, 1));
		}
		x.clear();
		dfs(0, 1);
		sort(x.begin(), x.end());
		LL ans;
		int size = x.size();
		for (int i = 0; i < size; ++i) {
			if (lcm * x[i] / gcd(lcm, x[i]) == use) {
				ans = x[i];
				break;
			}
		}
		printf("Case %d: %lld\n", icase++, ans);
	}
	return 0;
}
