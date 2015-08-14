/*************************************************************************
    > File Name: LightOJ1266.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月14日 星期五 20时01分31秒
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

const int N = 1100;
int tree[N][N];
bool has[N][N];

int lowbit(int x) {
	return x & (-x);
}

void add(int x, int y) {
	for (int i = x; i < N; i += lowbit(i)) {
		for (int j = y; j < N; j += lowbit(j)) {
			++tree[i][j];
		}
	}
}

int sum(int x, int y) {
	int ans = 0;
	for (int i = x; i; i -= lowbit(i)) {
		for (int j = y; j; j -= lowbit(j)) {
			ans += tree[i][j];
		}
	}
	return ans;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		memset(tree, 0, sizeof(tree));
		memset(has, 0, sizeof(has));
		int ty, x, y, x2, y2;
		scanf("%d", &n);
		printf("Case %d:\n", icase++);
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d%d", &ty, &x, &y);
			if (ty) {
				scanf("%d%d", &x2, &y2);
				++x, ++y, ++x2, ++y2;
				int ans = sum(x2, y2) - sum(x - 1, y2) - sum(x2, y - 1) + sum(x - 1, y - 1);
				printf("%d\n", ans);
			}
			else {
				++x, ++y;
				if (!has[x][y]) {
					add(x, y);
					has[x][y] = 1;
				}
			}
		}
	}
	return 0;
}
