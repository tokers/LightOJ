/*************************************************************************
    > File Name: LightOJ1434.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年10月10日 星期六 16时08分24秒
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

char mat[33][33];
char str[20];
bool vis[20][33][33];
int dir[8][2] = {1, 0, 0, 1, -1, 0, 0, -1, 1, -1, 1, 1, -1, 1, -1, -1};
int ex, ey;
char ope[20][20];

struct STS {
	LL move;
	int pos;
	int x, y;
	STS(LL _a, int _b, int _x, int _y) {
		move = _a;
		pos = _b;
		x = _x, y = _y;
	}
};

LL bfs(int n, int m) {
	int len = strlen(str);
	memset(vis, 0, sizeof(vis));
	queue <STS> qu;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (mat[i][j] == str[0]) {
				qu.push(STS(0, 0, i, j));
				vis[0][i][j] = 1;
			}
		}
	}
	LL ans = -1;
	while (!qu.empty()) {
		STS now = qu.front();
		qu.pop();
		if (now.pos == len - 1) {
			ans = now.move;
			ex = now.x;
			ey = now.y;
			break;
		}
		int x = now.x, y = now.y;
		if (!vis[now.pos + 1][x][y] && mat[x][y] == str[now.pos + 1]) {
			vis[now.pos + 1][x][y] = 1;
			qu.push(STS(now.move * 10 + 9, now.pos + 1, x, y));
		}
		for (int i = 0; i < 8; ++i) {
			int xx = x + dir[i][0];
			int yy = y + dir[i][1];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m || vis[now.pos + 1][xx][yy] || mat[xx][yy] != str[now.pos + 1]) {
				continue;
			}
			vis[now.pos + 1][xx][yy] = 1;
			qu.push(STS(now.move * 10 + i + 1, now.pos + 1, xx, yy));
		}
	}
	return ans;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m, q;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%s", mat[i]);
		}
		scanf("%d", &q);
		printf("Case %d:\n", icase++);
		while (q--) {
			scanf("%s", str);
			LL ans = bfs(n, m);
			if (ans == -1) {
				printf("%s not found\n", str);
				continue;
			}
			printf("%s found:", str);
			int cnt = 0, len = strlen(str);
			while (ans) {
				int mo = ans % 10;
				ans /= 10;
				if (mo == 9) {
					strcpy(ope[cnt++], "*");
					continue;
				}
				else if (mo == 1) {
					strcpy(ope[cnt++], "D");
				}
				else if (mo == 2) {
					strcpy(ope[cnt++], "R");
				}
				else if (mo == 3) {
					strcpy(ope[cnt++], "U");
				}
				else if (mo == 4) {
					strcpy(ope[cnt++], "L");
				}
				else if (mo == 5) {
					strcpy(ope[cnt++], "DL");
				}
				else if (mo == 6) {
					strcpy(ope[cnt++], "DR");
				}
				else if (mo == 7) {
					strcpy(ope[cnt++], "UR");
				}
				else {
					strcpy(ope[cnt++], "UL");
				}
				ex -= dir[mo - 1][0];
				ey -= dir[mo - 1][1];
			}
			printf(" (%d,%d)", ex + 1, ey + 1);
			for (int i = cnt - 1; i >= 0; --i) {
				printf(", %s", ope[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
