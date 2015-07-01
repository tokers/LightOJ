/*************************************************************************
    > File Name: LightOJ1085.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月01日 星期三 12时33分44秒
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

const int N = 100100;
const int mod = 1000000007;
int tree[N];
int cnt;
int xis[N];
int Arr[N];

int lowbit(int x) {
	return x & (-x);
}

void add(int x, int val) {
	for (int i = x; i <= 100000; i += lowbit(i)) {
		tree[i] += val;
		tree[i] %= mod;
	}
}

int getsum(int x) {
	int ans = 0;
	for (int i = x; i; i -= lowbit(i)) {
		ans += tree[i];
		ans %= mod;
	}
	return ans;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &Arr[i]);
			xis[i] = Arr[i];
		}
		sort(xis + 1, xis + 1 + n);
		cnt = unique(xis + 1, xis + 1 + n) - xis - 1;
		memset(tree, 0, sizeof(tree));
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			int val = lower_bound(xis + 1, xis + 1 + n, Arr[i]) - xis;
			int tmp = (getsum(val - 1) + 1) % mod;
			ans += tmp;
			ans %= mod;
			add(val, tmp);
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
