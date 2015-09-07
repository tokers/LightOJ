/*************************************************************************
    > File Name: LightOJ1171.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年09月07日 星期一 15时43分42秒
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

const int MAXN = 40010; 
int Mx[MAXN], My[MAXN]; 
int dx[MAXN], dy[MAXN]; 
int dis; 
int uN; 
bool used[MAXN]; 
int head[MAXN];
int tot;
struct Edge {
	int nxt;
	int to;
}edge[MAXN * 40];
int dir[8][2] = {-2, -1, -2, 1, -1, -2, -1, 2, 1, -2, 1, 2, 2, -1, 2, 1};

void addedge(int from, int to) {
	edge[tot].to = to;
	edge[tot].nxt = head[from];
	head[from] = tot++;
}

bool SearchP() { 
	queue <int> Q; 
	dis = inf; 
	memset(dx, -1, sizeof(dx)); 
	memset(dy, -1, sizeof(dy)); 
	for (int i = 1; i <= uN; ++i) { 
		if (Mx[i] == -1) { 
			Q.push(i); 
			dx[i] = 0; 
		} 
	} 
	while (!Q.empty()) { 
		int u = Q.front(); 
		Q.pop(); 
		if (dx[u] > dis) { 
			break; 
		} 
		for (int i = head[u]; ~i; i = edge[i].nxt) { 
			int v = edge[i].to; 
			if (dy[v] == -1) { 
				dy[v] = dx[u] + 1; 
				if (My[v] == -1) { 
					dis = dy[v]; 
				} 
				else { 
					dx[My[v]] = dy[v] + 1; 
					Q.push(My[v]); 
				} 
			} 
		} 
	} 
	return dis != inf; 
} 

bool dfs(int u) { 
	for (int i = head[u]; ~i; i = edge[i].nxt) { 
		int v = edge[i].to; 
		if (!used[v] && dy[v] == dx[u] + 1) { 
			used[v] = 1; 
			if (My[v] != -1 && dy[v] == dis) { 
				continue; 
			} 
			if (My[v] == -1 || dfs(My[v])) { 
				My[v] = u; 
				Mx[u] = v; 
				return 1; 
			} 
		} 
	} 
	return 0; 
} 

int MaxMatch() { 
	int res = 0; 
	memset(Mx, -1, sizeof(Mx)); 
	memset(My, -1, sizeof(My)); 
	while (SearchP()) { 
		memset(used, 0, sizeof(used)); 
		for (int i = 1; i <= uN; ++i) { 
			if (Mx[i] == -1 && dfs(i)) { 
				++res; 
			} 
		} 
	} 
	return res; 
}

int mat[222][222];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		memset(head, -1, sizeof(head));
		tot = 0;
		memset(mat, 0, sizeof(mat));
		for (int i = 1; i <= k; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			mat[x][y] = -1;
		}
		uN = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (mat[i][j] != -1) {
					mat[i][j] = ++uN;
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (mat[i][j] != -1) {
					for (int l = 0; l < 8; ++l) {
						int x = i + dir[l][0];
						int y = j + dir[l][1];
						if (x < 1 || x > n || y < 1 || y > m) {
							continue;
						}
						if (mat[x][y] == -1) {
							continue;
						}
						addedge(mat[i][j], mat[x][y]);
					}
				}
			}
		}
		printf("Case %d: %d\n", icase++, uN - MaxMatch() / 2);
	}
	return 0;
}
