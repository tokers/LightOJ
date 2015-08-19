/*************************************************************************
    > File Name: LightOJ1120.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月14日 星期五 16时52分06秒
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

const int N = 60010;
struct SegTree {
	int l, r;
	int val;
	int add;
}tree[N << 2];

int xis[N];

void build(int p, int l, int r) {
	tree[p].l = l;
	tree[p].r = r;
	tree[p].add = 0;
	tree[p].val = 0;
	if (l == r) {
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
}

void pushup(int p) {
	if (tree[p].add) {
		tree[p].val = xis[tree[p].r + 1] - xis[tree[p].l];
	}
	else if (tree[p].l == tree[p].r) {
		tree[p].val = 0;
	}
	else {
		tree[p].val = tree[p << 1].val + tree[p << 1 | 1].val;
	}
}

void update(int p, int l, int r, int val) {
	if (l <= tree[p].l && tree[p].r <= r) {
		tree[p].add += val;
		pushup(p);
		return;
	}
	int mid = (tree[p].l + tree[p].r) >> 1;
	if (r <= mid) {
		update(p << 1, l, r, val);
	}
	else if (l > mid) {
		update(p << 1 | 1, l, r, val);
	}
	else {
		update(p << 1, l, mid, val);
		update(p << 1 | 1, mid + 1, r, val);
	}
	pushup(p);
}

struct LINE {
	int x1, x2, h;
	int flag;

	bool operator < (const LINE &b) const {
		return h < b.h;
	}
}lines[N];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int x1, x2, y1, y2, n, ret = 0;
		int cnt = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			xis[++ret] = x1;
			xis[++ret] = x2;
			lines[++cnt].x1 = x1, lines[cnt].x2 = x2;
			lines[cnt].h = y1, lines[cnt].flag = 1;
			lines[++cnt].x1 = x1, lines[cnt].x2 = x2;
			lines[cnt].h = y2, lines[cnt].flag = -1;
		}
		sort(xis + 1, xis + 1 + ret);
		ret = unique(xis + 1, xis + 1 + ret) - xis - 1;
		sort(lines + 1, lines + cnt + 1);
		build(1, 1, ret);
		LL ans = 0;
		int l = lower_bound(xis + 1, xis + 1 + ret, lines[1].x1) - xis;
		int r = lower_bound(xis + 1, xis + 1 + ret, lines[1].x2) - xis - 1;
		update(1, l, r, lines[1].flag);
		for (int i = 2; i <= cnt; ++i) {
			ans += (LL)tree[1].val * (lines[i].h - lines[i - 1].h);
			int l = lower_bound(xis + 1, xis + 1 + ret, lines[i].x1) - xis;
			int r = lower_bound(xis + 1, xis + 1 + ret, lines[i].x2) - xis - 1;
			update(1, l, r, lines[i].flag);
		}
		printf("Case %d: %lld\n", icase++, ans);
	}
	return 0;
}
