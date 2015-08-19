/*************************************************************************
    > File Name: LightOJ1183.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月19日 星期三 20时45分45秒
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
struct SegTree {
	int l, r;
	int add;
	LL sum;
}tree[N << 2];

void build(int p, int l, int r) {
	tree[p].l = l;
	tree[p].r = r;
	tree[p].add = -1;
	tree[p].sum = 0;
	if (l == r) {
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
}

void pushup(int p) {
	tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
}

void pushdown(int p) {
	if (tree[p].add != -1) {
		tree[p << 1].add = tree[p].add;
		tree[p << 1 | 1].add = tree[p].add;
		tree[p << 1].sum = (LL)tree[p].add * (tree[p << 1].r - tree[p << 1].l + 1);
		tree[p << 1 | 1].sum = (LL)tree[p].add * (tree[p << 1| 1].r - tree[p << 1 | 1].l + 1);
		tree[p].add = -1;
	}
}

void update(int p, int l, int r, int val) {
	if (l <= tree[p].l && tree[p].r <= r) {
		tree[p].add = val;
		tree[p].sum = (LL)val * (tree[p].r - tree[p].l + 1);
		return;
	}
	pushdown(p);
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

LL query(int p, int l, int r) {
	if (l <= tree[p].l && tree[p].r <= r) {
		return tree[p].sum;
	}
	pushdown(p);
	int mid = (tree[p].l + tree[p].r) >> 1;
	if (r <= mid) {
		return query(p << 1, l, r);
	}
	else if (l > mid) {
		return query(p << 1 | 1, l, r);
	}
	else {
		return query(p << 1, l, mid) + query(p << 1 | 1, mid + 1, r);
	}
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, q;
		scanf("%d%d", &n, &q);
		build(1, 1, n);
		int ty, x, y, val;
		printf("Case %d:\n", icase++);
		while (q--) {
			scanf("%d%d%d", &ty, &x, &y);
			++x, ++y;
			if (ty == 1) {
				scanf("%d", &val);
				update(1, x, y, val);
			}
			else {
				LL sum = query(1, x, y);
				int num = y - x + 1;
				LL gcd = __gcd(sum, (LL)num);
				if (sum % num) {
					printf("%lld/%lld\n", sum / gcd, num / gcd);
				}
				else {
					printf("%lld\n", sum / num);
				}
			}
		}
	}
	return 0;
}
