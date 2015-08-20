/*************************************************************************
    > File Name: LightOJ1207.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月20日 星期四 10时59分03秒
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

const int N = 200010;
struct SegTree {
	int l, r;
	int col;
}tree[N << 2];

void build(int p, int l, int r) {
	tree[p].l = l;
	tree[p].r = r;
	tree[p].col = -1;
	if (l == r) {
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
}

 void update(int p, int l, int r, int col) {
 	 if (l <= tree[p].l && tree[p].r <= r) {
	 	 tree[p].col = col;
	 	 return;
	 }
	 if (tree[p].col != -1) {
	 	 tree[p << 1].col = tree[p << 1 | 1].col = tree[p].col;
	 	 tree[p].col = -1;
	 }
	 int mid = (tree[p].l + tree[p].r) >> 1;
	 if (r <= mid) {
	 	 update(p << 1, l, r, col);
	 }
	 else if (l > mid) {
	 	 update(p << 1 | 1, l, r, col);
	 }
	 else {
	 	 update(p << 1, l, mid, col);
	 	 update(p << 1 | 1, mid + 1, r, col);
	 }
	 if (tree[p << 1].col == tree[p << 1 | 1].col) {
	 	 tree[p].col = tree[p << 1].col;
	 }
	 else {
	 	 tree[p].col = -1;
	 }
 }

int ans;
bool flag[N];

void query(int p) {
	if (tree[p].col != -1) {
		if (!flag[tree[p].col]) {
			flag[tree[p].col] = 1;
			++ans;
		}
		return;
	}
	if (tree[p].l == tree[p].r) {
		return;
	}
	query(p << 1);
	query(p << 1 | 1);
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		build(1, 1, 2 * n);
		int l, r;
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", &l, &r);
			update(1, l, r, i);
		}
		memset(flag, 0, sizeof(flag));
		ans = 0;
		query(1);
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
