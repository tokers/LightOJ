/*************************************************************************
    > File Name: LightOJ1150.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年09月07日 星期一 11时22分47秒
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

const int N = 650; 
int un, vn; 
int G[N][N]; 
vector <int> edge[N];
int ord[30][30];
char mat[30][30];
bool vis[30][30];
bool use[N];
int match[N];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int n;

void bfs(int u, int x, int y) {
	queue < pair <int, pair<int, int> > > qu;
	memset(vis, 0, sizeof(vis));
	vis[x][y] = 1;
	qu.push(make_pair(0, make_pair(x, y)));
	while (!qu.empty()) {
		pair < int, pair<int, int> > now = qu.front();
		qu.pop();
		for (int i = 0; i < 4; ++i) {
			int xx = now.second.first + dir[i][0];
			int yy = now.second.second + dir[i][1];
			if (xx < 0 || yy < 0 || xx >= n || yy >= n || mat[xx][yy] == '#' || vis[xx][yy]) {
				continue;
			}
			vis[xx][yy] = 1;
			int tt = now.first + 1;
			if (mat[xx][yy] == 'H') {
				G[u][ord[xx][yy]] = 2 * tt + 2;
			}
			qu.push(make_pair(tt, make_pair(xx, yy)));
		}
	}
}

bool dfs(int u) {
	int size = edge[u].size();
	for (int i = 0; i < size; ++i) {
		int v = edge[u][i];
		if (!use[v]) {
			use[v] = 1;
			if (match[v] == -1 || dfs(match[v])) {
				match[v] = u;
				return 1;
			}
		}
	}
	return 0;
}

int hungry() {
	int ans = 0;
	memset(match, -1, sizeof(match));
	for (int i = 0; i < un; ++i) {
		memset(use, 0, sizeof(use));
		if (dfs(i)) {
			++ans;
		}
	}
	return ans;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		memset(G, inf, sizeof(G));
		scanf("%d", &n);
		un = vn = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%s", mat[i]);
			for (int j = 0; j < n; ++j) {
				if (mat[i][j] == 'H') {
					ord[i][j] = vn++;
				}
				else if (mat[i][j] == 'G') {
					ord[i][j] = un++;
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (mat[i][j] == 'G') {
					bfs(ord[i][j], i, j);
				}
			}
		}
		int l = 0, r = 100000, mid, res = -1;
		while (l <= r) {
			mid = (l + r) >> 1;
			for (int i = 0; i < un; ++i) {
				edge[i].clear();
			}
			for (int i = 0; i < un; ++i) {
				for (int j = 0; j < vn; ++j) {
					if (G[i][j] <= mid) {
						edge[i].push_back(j);
					}
				}
			}
			int ans = hungry();
			if (ans == vn) {
				res = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		if (res != -1) {
			printf("Case %d: %d\n", icase++, res);
		}
		else {
			printf("Case %d: Vuter Dol Kupokat\n", icase++);
		}
	}
	return 0;
}
