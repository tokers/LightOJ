/*************************************************************************
    > File Name: LightOJ1087.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月05日 星期日 18时15分21秒
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

const int N = 160000;

struct SegTree {
	int l, r;
	int sum;
	int val;
}tree[N << 2];

int n, q;
int Arr[N];

void pushup(int p) {
	tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
}

void build(int p, int l, int r) {
	tree[p].l = l;
	tree[p].r = r;
	if (l == r) {
		if (l <= n) {
			tree[p].val = Arr[l];
			tree[p].sum = 1;
		}
		else {
			tree[p].sum = 0;
		}
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	pushup(p);
}

void update(int p, int pos, int val) {
	if (tree[p].l == tree[p].r) {
		tree[p].sum = 1;
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

int ans;
void query(int p, int k) {
	if (tree[p].l == tree[p].r) {
		tree[p].sum = 0;
		ans = tree[p].val;
		return;
	}
	int mid = (tree[p].l + tree[p].r) >> 1;
	if (tree[p << 1].sum >= k) {
		query(p << 1, k);
	}
	else {
		query(p << 1 | 1, k - tree[p << 1].sum);
	}
	pushup(p);
}

char op[10];
int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int m, k, val;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &Arr[i]);
		}
		build(1, 1, n + m);
		int len = n;
		printf("Case %d:\n", icase++);
		while (m--) {
			scanf("%s", op);
			if (op[0] == 'c') {
				scanf("%d", &k);
				if (tree[1].sum < k) {
					printf("none\n");
				}
				else {
					query(1, k);
					printf("%d\n", ans);
				}
			}
			else {
				scanf("%d", &val);
				++len;
				update(1, len, val);
			}
		}
	}
	return 0;
}
