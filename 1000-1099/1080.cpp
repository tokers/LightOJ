/*************************************************************************
    > File Name: LightOJ1080.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月05日 星期日 17时45分34秒
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
struct SegTree {
	int l, r;
	bool add;
}tree[N << 2];
char str[100010];

void build(int p, int l, int r) {
	tree[p].l = l;
	tree[p].r = r;
	tree[p].add = 0;
	if (l == r) {
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
}

void pushdown(int p) {
	if (tree[p].add) {
		tree[p << 1].add ^= 1;
		tree[p << 1 | 1].add ^= 1;
		tree[p].add = 0;
	}
}

void update(int p, int l, int r) {
	if (l <= tree[p].l && tree[p].r <= r) {
		tree[p].add ^= 1;
		return;
	}
	int mid = (tree[p].l + tree[p].r) >> 1;
	pushdown(p);
	if (r <= mid) {
		update(p << 1, l, r);
	}
	else if (l > mid) {
		update(p << 1 | 1, l, r);
	}
	else {
		update(p << 1, l, mid);
		update(p << 1 | 1, mid + 1, r);
	}
}

int query(int p, int pos) {
	if (tree[p].l == tree[p].r) {
		return tree[p].add;
	}
	pushdown(p);
	int mid = (tree[p].l + tree[p].r) >> 1;
	if (pos <= mid) {
		return query(p << 1, pos);
	}
	else {
		return query(p << 1 | 1, pos);
	}
}

char op[10];

int main() {
	int m, n, t, x, y, icase = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", str);
		n = strlen(str);
		build(1, 1, n);
		scanf("%d", &m);
		printf("Case %d:\n", icase++);
		while (m--) {
			scanf("%s", op);
			if (op[0] == 'Q') {
				scanf("%d", &x);
				int val = str[x - 1] - '0';
				printf("%d\n", query(1, x) ^ val);
			}
			else {
				scanf("%d%d", &x, &y);
				update(1, x, y);
			}
		}
	}
	return 0;
}
