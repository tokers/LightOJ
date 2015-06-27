/*************************************************************************
    > File Name: LightOJ1097.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月27日 星期六 16时02分52秒
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

const int N = 1500000;
struct SegTree {
	int l, r;
	int sum;
}tree[N * 3];

void build(int p, int l, int r) {
	tree[p].l = l;
	tree[p].r = r;
	if (l == r) {
		tree[p].sum = (l & 1);
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
}

void update(int p, int pos) {
	if (tree[p].l == tree[p].r) {
		tree[p].sum = 0;
		return;
	}
	if (pos <= tree[p << 1].sum) {
		update(p << 1, pos);
	}
	else {
		update(p << 1 | 1, pos - tree[p << 1].sum);
	}
	tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
}

int query(int p, int pos) {
	if (tree[p].l == tree[p].r) {
		return tree[p].l;
	}
	int mid = (tree[p].l + tree[p].r) >> 1;
	if (tree[p << 1].sum >= pos) {
		return query(p << 1, pos);
	}
	else {
		return query(p << 1 | 1, pos - tree[p << 1].sum);
	}
}

void init() {
	build(1, 1, 1429431);
	int cur = 2; //序列的第i个数
	while (tree[1].sum >= cur) {
		int tmp = query(1, cur);
		int now = tmp;
		while (now <= tree[1].sum) {
			update(1, now);
			now += tmp - 1;
		}
		++cur;
	}
}
int main() {
	init();
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("Case %d: %d\n", icase++, query(1, n));
	}
	return 0;
}
