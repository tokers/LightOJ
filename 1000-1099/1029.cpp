/*************************************************************************
    > File Name: LightOJ1029.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月11日 星期四 21时10分14秒
 ************************************************************************/

#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <set>
#include <vector>

using namespace std;

const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef pair <int, int> PLL;

namespace DSU {
	int father[110];

	int find(int x) {
		if (father[x] == -1) {
			return x;
		}
		return father[x] = find(father[x]);
	}

	void init(int n) {
		for (int i = 0; i <= n; ++i) {
			father[i] = -1;
		}
	}
}

struct node {
	int u, v, w;
}edge[12010];

int cmp1(node a, node b) {
	return a.w < b.w;
}

int cmp2(node a, node b) {
	return a.w > b.w;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int u, v, w;
		int cnt = 0;
		while (scanf("%d%d%d", &u, &v, &w) && (u || v || w)) {
			edge[cnt].u = u;
			edge[cnt].v = v;
			edge[cnt++].w = w;
		}	
		int maxc = 0, minc = 0;
		sort(edge, edge + cnt, cmp1);
		DSU :: init(n);
		int use = 0;
		for (int i = 0; i < cnt; ++i) {
			int u = edge[i].u;
			int v = edge[i].v;
			int fu = DSU :: find(u);
			int fv = DSU :: find(v);
			if (fu != fv) {
				++use;
				DSU :: father[fu] = fv;
				minc += edge[i].w;
			}
			if (use == n) {
				break;
			}
		}
		sort(edge, edge + cnt, cmp2);
		DSU :: init(n);
		use = 0;
		for (int i = 0; i < cnt; ++i) {
			int u = edge[i].u;
			int v = edge[i].v;
			int fu = DSU :: find(u);
			int fv = DSU :: find(v);
			if (fv != fu) {
				++use;
				DSU :: father[fu] = fv;
				maxc += edge[i].w;
			}
			if (use == n) {
				break;
			}
		}
		int sum = maxc + minc;
		if(sum % 2) {
			printf("Case %d: %d/2\n", icase++, sum);
		}
		else {
			printf("Case %d: %d\n", icase++, sum / 2);
		}
	}
	return 0;
}
