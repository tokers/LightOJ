/*************************************************************************
    > File Name: LightOJ1009.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月05日 星期五 12时33分33秒
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

static const int N = 30000;
vector <int> edge[N];
int col[N];
int Num[N][2];
int xis[N * 10];
int cnt;

struct node {
	int u, v;
}Temp[100010];

void bfs(int u, int tot) {
	col[u] = 1;
	queue <int> qu;
	qu.push(u);
	while (!qu.empty()) {
		int now = qu.front();
		++Num[tot][col[now]];
		qu.pop();
		int size = edge[now].size();
		for (int i = 0; i < size; ++i) {
			int nxt = edge[now][i];
			if (col[nxt] == -1) {
				col[nxt] = (col[now] ^ 1);
				qu.push(nxt);	
			}
		}
	}
}

int Search(int val) {
	int l = 1, r = cnt, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (xis[mid] == val) {
			break;
		}
		else if (xis[mid] > val) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return mid;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, u, v;
		cnt = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", &u, &v);
			Temp[i].u = u;
			Temp[i].v = v;
			xis[++cnt] = u;
			xis[++cnt] = v;
		}
		sort(xis + 1, xis + 1 + cnt);
		cnt = unique(xis + 1, xis + 1 + cnt) - xis - 1;
		for (int i = 1; i <= cnt; ++i) {
			edge[i].clear();
			col[i] = -1;
			Num[i][0] = Num[i][1] = 0;
		}
		int tot = 0;
		for (int i = 1; i <= n; ++i) {
			u = Search(Temp[i].u);
			v = Search(Temp[i].v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		for (int i = 1; i <= cnt; ++i) {
			if (col[i] == -1) {
				bfs(i, ++tot);
			}
		}
		int ans = 0;
		for (int i = 1; i <= tot; ++i) {
			ans += max(Num[i][0], Num[i][1]);
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
