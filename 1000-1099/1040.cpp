/*************************************************************************
    > File Name: LightOJ1040.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月21日 星期日 20时49分18秒
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

int mat[55][55];
struct node {
	int u, v, w;
}edge[55 * 55];

int cmp(node a, node b) {
	return a.w < b.w;
}

int fa[55];

int find(int x) {
	if (fa[x] == -1) {
		return x;
	}
	return fa[x] = find(fa[x]);
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, ret = 0, sum = 0, use = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			fa[i] = -1;
			for (int j = 1; j <= n; ++j) {
				scanf("%d", &mat[i][j]);
				sum += mat[i][j];
				if (!mat[i][j]) {
					continue;
				}
				edge[ret].u = i;
				edge[ret].v = j;
				edge[ret++].w = mat[i][j];
			}
		}
		sort(edge, edge + ret, cmp);
		int cnt = 0;
		for (int i = 0; i < ret; ++i) {
			int fu = find(edge[i].u);
			int fv = find(edge[i].v);
			if (fu != fv) {
				++cnt;
				fa[fu] = fv;
				use += edge[i].w;
			}
			if (cnt == n - 1) {
				break;
			}
		}
		int ans;
		if (cnt < n - 1) {
			ans = -1;
		}
		else {
			ans = sum - use;
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
