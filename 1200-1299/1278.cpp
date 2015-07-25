/*************************************************************************
    > File Name: LightOJ1278.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月15日 星期三 20时13分00秒
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

int prime[1000000];
bool valid[15000010];
int tot; 

void getPrime() {
	int n = 15000000;
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

vector < pair<LL, int> > fac;
vector <LL> facc;

void dfs(int now, LL x) {
	if (now == (int)fac.size()) {
		facc.push_back(x);
		return;
	}
	dfs(now + 1, x);
	int cnt = fac[now].second;
	for (int i = 1; i <= cnt; ++i) {
		x *= fac[now].first;
		dfs(now + 1, x);
	}
}

int main() {
	int t, icase = 1;
	getPrime();
	scanf("%d", &t);
	while (t--) {
		int ans = 0;
		LL n;
		scanf("%lld", &n);
		n <<= 1;
		fac.clear();
		facc.clear();
		LL m = n;
		for (int i = 1; i <= tot && (LL)prime[i] * prime[i] <= m; ++i) {
			if (m % prime[i] == 0) {
				int cnt = 0;
				while (m % prime[i] == 0) {
					m /= prime[i];
					++cnt;
				}
				fac.push_back(make_pair(prime[i], cnt));
			}
		}
		if (m > 1) {
			fac.push_back(make_pair(m, 1));
		}
		dfs(0, 1);
		int size = facc.size();
		for (int i = 0; i < size; ++i) {
			if (facc[i] == 1 || facc[i] == n) {
				continue;
			}
			LL rest = n / facc[i];
			rest -= (facc[i] - 1);
			if (rest >= 2 && rest % 2 == 0) {
				++ans;
			}
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
