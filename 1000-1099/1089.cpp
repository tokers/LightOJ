/*************************************************************************
    > File Name: LightOJ1089.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月07日 星期二 15时44分46秒
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

const int N = 200000;
int Arr[N];
int xis[N];
int que[N];
struct fuck {
	int l, r;
}seg[N];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m, l, r, cnt = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", &l, &r);
			seg[i].l = l;
			seg[i].r = r;
			xis[++cnt] = l;
			xis[++cnt] = r;
		}
		for (int i = 1; i <= m; ++i) {
			scanf("%d", &que[i]);
			xis[++cnt] = que[i];
		}
		memset(Arr, 0, sizeof(Arr));
		sort(xis + 1, xis + 1 + cnt);
		cnt = unique(xis + 1, xis + 1 + cnt) - xis - 1;
		for (int i = 1; i <= n; ++i) {
			int l = lower_bound(xis + 1, xis + 1 + cnt, seg[i].l) - xis;
			int r = lower_bound(xis + 1, xis + 1 + cnt, seg[i].r) - xis;
			++Arr[l];
			--Arr[r + 1];
		}
		for (int i = 1; i <= cnt; ++i) {
			Arr[i] += Arr[i - 1];
		}
		printf("Case %d:\n", icase++);
		for (int i = 1; i <= m; ++i) {
			int val = lower_bound(xis + 1, xis + 1 + cnt, que[i]) - xis;
			printf("%d\n", Arr[val]);
		}
	}
	return 0;
}
