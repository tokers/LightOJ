/*************************************************************************
    > File Name: LightOJ1055.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月09日 星期四 11时18分17秒
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

int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
bool vis[9][9][9][9][9][9];
char mat[9][9];
int n;

struct Node {
	int x1, y1;
	int x2, y2;
	int x3, y3;
	int t;

	Node(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _t) {
		x1 = _x1; y1 = _y1;
		x2 = _x2; y2 = _y2;
		x3 = _x3; y3 = _y3;
		t = _t;
	}
};

queue <Node> qu;

bool check(int x, int y) { // whether ok
	return (x >= 0 && x < n && y >= 0 && y < n && mat[x][y] != '#');
}

int bfs(int sx1, int sy1, int sx2, int sy2, int sx3, int sy3) {
	while (!qu.empty()) {
		qu.pop();
	}
	memset(vis, 0, sizeof(vis));
	qu.push(Node(sx1, sy1, sx2, sy2, sx3, sy3, 0));
	int ans = -1;
	vis[sx1][sy1][sx2][sy2][sx3][sy3] = 1;
	while (!qu.empty()) {
		Node now = qu.front();
		qu.pop();
		int x1 = now.x1, y1 = now.y1;
		int x2 = now.x2, y2 = now.y2;
		int x3 = now.x3, y3 = now.y3;
		int t = now.t;
		if (mat[x1][y1] == 'X' && mat[x2][y2] == 'X' && mat[x3][y3] == 'X') {
			ans = t;
			break;
		}
		for (int i = 0; i < 4; ++i) {
			int _x1 = x1 + dir[i][0];
			int _y1 = y1 + dir[i][1];
			bool flag1 = 0, flag2 = 0, flag3 = 0;
			if (!check(_x1, _y1)) {
				_x1 = x1, _y1 = y1; //stay
				flag1 = 1;
			}
			int _x2 = x2 + dir[i][0];
			int _y2 = y2 + dir[i][1];
			if (!check(_x2, _y2)) {
				_x2 = x2, _y2 = y2;
				flag2 = 1;
			}
			int _x3 = x3 + dir[i][0];
			int _y3 = y3 + dir[i][1];
			if (!check(_x3, _y3)) {
				_x3 = x3, _y3 = y3;
				flag3 = 1;
			}
			if (flag1 && flag2 && flag3) {
				if (vis[_x1][_y1][_x2][_y2][_x3][_y3]) {
					continue;
				}
				vis[_x1][_y1][_x2][_y2][_x3][_y3] = 1;
				qu.push(Node(_x1, _y1, _x2, _y2, _x3, _y3, t + 1));
			}
			else {
				while (1) {
					bool flag = 0;
					if (!flag1 && flag2 && _x1 == _x2 && _y1 == _y2) {
						_x1 = x1, _y1 = y1;
						flag1 = 1;
						flag = 1;
					}
					if (flag1 && !flag2 && _x1 == _x2 && _y1 == _y2) {
						_x2 = x2, _y2 = y2;
						flag2 = 1;
						flag = 1;
					}
					if (!flag1 && flag3 && _x1 == _x3 && _y1 == _y3) {
						_x1 = x1, _y1 = y1;
						flag1 = 1;
						flag = 1;
					}
					if (flag1 && !flag3 && _x1 == _x3 && _y1 == _y3) {
						_x3 = x3, _y3 = y3;
						flag3 = 1;
						flag = 1;
					}
					if (!flag2 && flag3 && _x2 == _x3 && _y2 == _y3) {
						_x2 = x2, _y2 = y2;
						flag2 = 1;
						flag = 1;
					}
					if (flag2 && !flag3 && _x2 == _x3 && _y2 == _y3) {
						_x3 = x3, _y3 = y3;
						flag3 = 1;
						flag = 1;
					}
					if (!flag) {
						break;
					}
				}
				if (vis[_x1][_y1][_x2][_y2][_x3][_y3]) {
					continue;
				}
				vis[_x1][_y1][_x2][_y2][_x3][_y3] = 1;
				qu.push(Node(_x1, _y1, _x2, _y2, _x3, _y3, t + 1));
			}
		}
	}
	return ans;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int x1, y1, x2, y2, x3, y3;
		for (int i = 0; i < n; ++i) {
			scanf("%s", mat[i]);
			for (int j = 0; j < n; ++j) {
				if (mat[i][j] == 'A'){
					x1 = i;
					y1 = j;
				}
				else if (mat[i][j] == 'B') {
					x2 = i;
					y2 = j;
				}
				else if (mat[i][j] == 'C') {
					x3 = i;
					y3 = j;
				}
			}
		}
		int ans = bfs(x1, y1, x2, y2, x3, y3);
		if (ans == -1) {
			printf("Case %d: trapped\n", icase++);
		}
		else {
			printf("Case %d: %d\n", icase++, ans);
		}
	}
	return 0;
}
