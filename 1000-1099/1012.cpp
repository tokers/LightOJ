/*************************************************************************
    > File Name: LightOJ1012.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月07日 星期日 17时48分45秒
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

char mat[55][55];
int num[55][55];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

namespace DSU {
	int father[3000];
	int num[3000];

	int find(int x) {
		if (father[x] == -1) {
			return x;
		}
		return father[x] = find(father[x]);
	}

	void init(int n) {
		for (int i = 0; i < n; ++i) {
			father[i] = -1;
			num[i] = 1;
		}
	}
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int cnt = 0;
		int w, h;
		int sx, sy;
		scanf("%d%d", &h, &w);
		for (int i = 0; i < w; ++i) {
			scanf("%s", mat[i]);
			for (int j = 0; j < h; ++j) {
				if (mat[i][j] != '#') {
					num[i][j] = cnt++;
				}
				if (mat[i][j] == '@') {
					sx = i;
					sy = j;
				}
			}
		}
		DSU :: init(cnt);
		for (int i = 0; i < w; ++i) {
			for (int j = 0; j < h; ++j) {
				if (mat[i][j] == '#') {
					continue;
				}
				for (int k = 0; k < 4; ++k) {
					int x = i + dir[k][0];
					int y = j + dir[k][1];
					if (x < 0 || x >= w || y < 0 || y >= h) {
						continue;
					}
					if (mat[x][y] == '#') {
						continue;
					}
					int fu = DSU :: find(num[i][j]);
					int fv = DSU :: find(num[x][y]);
					if (fu != fv) {
						DSU :: father[fu] = fv;
						DSU :: num[fv] += DSU :: num[fu];
					}
				}
			}
		}
		int fu = DSU :: find(num[sx][sy]);
		printf("Case %d: %d\n", icase++, DSU :: num[fu]);
	}
	return 0;
}
