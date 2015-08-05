/*************************************************************************
    > File Name: LightOJ1112.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月05日 星期三 21时41分39秒
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

const int N = 100010;
LL tree[N];
int n;

int lowbit(int x) {
	return x & (-x);
}

void add(int x, int val) {
	for (int i = x; i <= n; i += lowbit(i)) {
		tree[i] += val;
	}
}

LL sum(int x) {
	LL ans = 0;
	for (int i = x; i; i -= lowbit(i)) {
		ans += tree[i];
	}
	return ans;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int m;
		scanf("%d%d", &n, &m);
		memset(tree, 0, sizeof(tree));
		int u;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &u);
			add(i, u);
		}
		printf("Case %d:\n", icase++);
		int ty, x, y;
		while (m--) {
			scanf("%d", &ty);
			if (ty == 1) {
				scanf("%d", &x);
				++x;
				LL num = sum(x) - sum(x - 1);
				printf("%lld\n", num);
				add(x, -num);
			}
			else if (ty == 2) {
				scanf("%d%d", &x, &y);
				++x;
				add(x, y);
			}
			else {
				scanf("%d%d", &x, &y);
				++x, ++y;
				printf("%lld\n", sum(y) - sum(x - 1));
			}
		}
	}
	return 0;
}
