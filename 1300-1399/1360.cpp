/*************************************************************************
    > File Name: LightOJ1360.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年09月15日 星期二 15时56分20秒
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

const int N = 200100;
struct SegTree {
	int l, r;
	int val;
}tree[N << 2];

void pushup(int p) {
	tree[p].val = max(tree[p << 1].val, tree[p << 1 | 1].val);
}

void build(int p, int l, int r) {
	tree[p].l = l;
	tree[p].r = r;
	tree[p].val = 0;
	if (l == r) {
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
}

void update(int p, int pos, int val) {
	if (tree[p].l == tree[p].r) {
		tree[p].val = val;
		return;
	}
	int mid = (tree[p].l + tree[p].r) >> 1;
	if (pos <= mid) {
		update(p << 1, pos, val);
	}
	else {
		update(p << 1 | 1, pos, val);
	}
	pushup(p);
}

int query(int p, int l, int r) {
	if (l <= tree[p].l && tree[p].r <= r) {
		return tree[p].val;
	}
	int mid = (tree[p].l + tree[p].r) >> 1;
	if (l > mid) {
		return query(p << 1 | 1, l, r);
	}
	else if (r <= mid) {
		return query(p << 1, l, r);
	}
	else {
		return max(query(p << 1, l, mid), query(p << 1 | 1, mid + 1, r));
	}
}

vector <PLL> adv[200110];
int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, a, b, c;
		scanf("%d", &n);
		for (int i = 0; i <= 200010; ++i) {
			adv[i].clear();
		}
		build(1, 1, 200010);
		int low = inf, high = -inf;
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d%d", &a, &b, &c);
			++a;
			low = min(low, a);
			high = max(high, a + b - 1);
			adv[a + b - 1].push_back(make_pair(a, c));
		}
		int ans = 0;
		for (int i = low; i <= high; ++i) {
			int now = 0;
			if (i > 1) {
				now = query(1, 1, i - 1);
			}
			int size = adv[i].size();
			for (int j = 0; j < size; ++j) {
				a = adv[i][j].first;
				c = adv[i][j].second;
				if (a > 1) {
					now = max(now, query(1, 1, a - 1) + c);
				}
				else {
					now = max(now, c);
				}
			}
			ans = max(ans, now);
			update(1, i, now);
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}

