/*************************************************************************
    > File Name: LightOJ1041.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月24日 星期三 20时42分16秒
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

struct Edge {
	int u, v, w;
}edge[55];

map <string, int> mp;
char a[100], b[100];

int cmp(Edge a, Edge b) {
	return a.w < b.w;
}

int fa[110];

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
		mp.clear();
		int m, w, cnt = 0;
		scanf("%d", &m);
		for (int i = 1; i <= m; ++i) {
			scanf("%s%s%d", a, b, &w);
			if (mp.find(a) == mp.end()) {
				mp[a] = ++cnt;
			}
			if (mp.find(b) == mp.end()) {
				mp[b] = ++cnt;
			}
			edge[i].u = mp[a];
			edge[i].v = mp[b];
			edge[i].w = w;
		}
		for (int i = 1; i <= cnt; ++i) {
			fa[i] = -1;
		}
		int ret = cnt;
		cnt = 0;
		int sum = 0;
		sort(edge + 1, edge + 1 + m, cmp);
		for (int i = 1; i <= m; ++i) {
			int fu = find(edge[i].u);
			int fv = find(edge[i].v);
			if (fu != fv) {
				++cnt;
				fa[fu] = fv;
				sum += edge[i].w;
			}
			if (cnt == ret - 1) {
				break;
			}
		}
		printf("Case %d: ", icase++);
		if (cnt != ret - 1) {
			printf("Impossible\n");
		}
		else {
			printf("%d\n", sum);
		}
	}
	return 0;
}
