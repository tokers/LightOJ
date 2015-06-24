/*************************************************************************
    > File Name: LightOJ1348.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月24日 星期三 11时56分58秒
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

const int N = 30010;
struct Edge {
	int nxt;
	int to;
}edge[N << 1];

int head[N], tot;
int top[N];
int deep[N];
int fa[N];
int size[N];
int son[N];
int p[N];
int fp[N];
int w[N];
int pos;

void init() {
	tot = pos = 0;
	memset(son, -1, sizeof(son));
	memset(head, -1, sizeof(head));
}

void addedge(int from, int to) {
	edge[tot].to = to;
	edge[tot].nxt = head[from];
	head[from] = tot++;
}

void dfs1(int u, int pre, int d) {
	deep[u] = d;
	fa[u] = pre;
	size[u] = 1;
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int v = edge[i].to;
		if (v != pre) {
			dfs1(v, u, d + 1);
			size[u] += size[v];
			if (son[u] == -1 || size[son[u]] < size[v]) {
				son[u] = v;
			}
		}
	}
}

void getpos(int u, int sp) {
	top[u] = sp;
	p[u] = ++pos;
	fp[p[u]] = u;
	if (son[u] == -1) {
		return;
	}
	getpos(son[u], sp);
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int v = edge[i].to;
		if (v != son[u] && v != fa[u]) {
			getpos(v, v);
		}
	}
}

struct SegTree {
	int l, r;
	int sum;
}tree[N << 2];

void pushup(int p) {
	tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
}

void build(int p, int l, int r) {
	tree[p].l = l;
	tree[p].r = r;
	if (l == r) {
		tree[p].sum = w[fp[l]];
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	pushup(p);
}

void update(int p, int pos, int val) {
	if (tree[p].l == tree[p].r) {
		tree[p].sum = val;
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
	if (tree[p].l >= l && tree[p].r <= r) {
		return tree[p].sum;
	}
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

int Find(int u, int v) {
	int f1 = top[u];
	int f2 = top[v];
	int ans = 0;
	while (f1 != f2) {
		if (deep[f1] < deep[f2]) {
			swap(f1, f2);
			swap(u, v);
		}
		ans += query(1, p[f1], p[u]);
		u = fa[f1];
		f1 = top[u];
	}
	if (deep[u] > deep[v]) {
		swap(u, v);
	}
	ans += query(1, p[u], p[v]);
	return ans;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		init();
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &w[i]);
		}
		int u, v;
		for (int i = 1; i <= n - 1; ++i) {
			scanf("%d%d", &u, &v);
			++u;
			++v;
			addedge(u, v);
			addedge(v, u);
		}
		dfs1(1, -1, 0);
		getpos(1, 1);
		build(1, 1, n);
		int m, op;
		scanf("%d", &m);
		printf("Case %d:\n", icase++);
		while (m--) {
			scanf("%d%d%d", &op, &u, &v);
			++u;
			if (op) {
				update(1, p[u], v);
			}
			else {
				++v;
				printf("%d\n", Find(u, v));
			}
		}
	}
	return 0;
}
