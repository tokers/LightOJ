/*************************************************************************
    > File Name: LightOJ1407.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年09月03日 星期四 12时57分38秒
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

const int N = 2020;
struct Edge {
	int to;
	int nxt;
}edge[N << 3];
int head[N], tot; 
 
void addedge(int from, int to) { 
	edge[tot].to = to; 
	edge[tot].nxt = head[from]; 
	head[from] = tot++; 
} 

void init() { 
	memset(head, -1, sizeof(head)); 
	tot = 0; 
} 

int low[N], dfn[N], St[N], block[N]; 
int ord, Top, sccnum; 
bool instack[N]; 
int num[N]; 

void tarjan(int u) { 
	dfn[u] = low[u] = ++ord; 
	St[Top++] = u; 
	instack[u] = 1; 
	for (int i = head[u]; ~i; i = edge[i].nxt) { 
		int v = edge[i].to; 
		if (dfn[v] == -1) { 
			tarjan(v); 
			low[u] = min(low[u], low[v]); 
		} 
		else if (instack[v]) { 
			low[u] = min(low[u], dfn[v]); 
		} 
	} 
	if (low[u] == dfn[u]) { 
		int v; 
		++sccnum; 
		do { 
			v = St[--Top]; 
			instack[v] = 0; 
			block[v] = sccnum; 
			++num[sccnum]; 
		}while (v != u); 
	} 
} 

bool solveable(int n)  { // n是总数, 选择一半 
	memset(dfn, -1, sizeof(dfn)); 
	memset(instack, 0, sizeof(instack)); 
	memset(num, 0, sizeof(num)); 
	ord = sccnum = Top = 0; 
	for (int i = 0; i < n; ++i) { 
		if (dfn[i] == -1) { 
			tarjan(i); 
		} 
	} 
	for (int i = 0; i < n; i += 2) { 
		if (block[i] == block[i ^ 1]) { 
			return 0; 
		} 
	} 
	return 1; 
} 
 
//拓扑排序求任意解 
queue <int> qu; 
vector < vector <int> > dag; // 缩点后的逆向DAG 
int cf[N]; // 矛盾点所在分量 
int in[N]; 
int col[N]; 

void solve(int n) { 
	dag.assign(sccnum + 1, vector<int>()); 
	memset(in, 0, sizeof(in)); 
	memset(col, -1, sizeof(col)); // 1->选择, 0不选 
	for (int i = 0; i < n; ++i) { 
		for (int j = head[i]; ~j; j = edge[j].nxt) { 
			int u = block[i], v = block[edge[j].to]; 
			if (u != v) { 
				dag[v].push_back(u); 
				++in[u]; 
			} 
		} 
	} 
	for (int i = 0; i < n; i += 2) { 
		cf[block[i]] = block[i ^ 1]; 
		cf[block[i ^ 1]] = block[i]; 
	} 
	while (!qu.empty()) { 
		qu.pop(); 
	} 
	for (int i = 1; i <= sccnum; ++i) { 
		if (in[i] == 0) { 
			qu.push(i); 
		} 
	} 
	while (!qu.empty()) { 
		int u = qu.front(); 
		qu.pop(); 
		if (col[u] == -1) { 
			col[u] = 1; 
			col[cf[u]] = 0; 
		} 
		int sz = dag[u].size(); 
		for (int i = 0; i < sz; ++i) { 
			--in[dag[u][i]]; 
			if (in[dag[u][i]] == 0) { 
				qu.push(dag[u][i]); 
			} 
		} 
	} 
} 

pair < int, pair<int, int> > G[N];
pair < pair<int, int>, pair<int, int> > g[10];
vector <int> ans;

void go(int n, int m, int k) {
	int stat = 1;
	for (int i = 1; i <= k; ++i) {
		stat *= 3;
	}
	for (int i = 0; i < stat; ++i) {
		int s = i, u, v, un, vn;
		init();
		for (int j = 0; j < k; ++j) {
			if (s % 3 == 0) {
				u = g[j].first.second;
			}
			else if (s % 3 == 1) {
				u = g[j].second.first;
			}
			else {
				u = g[j].second.second;
			}
			s /= 3;
			u = (u - 1) * 2;
			un = u + 1;
			if (g[j].first.first == 1) {
				addedge(un, u);
			}
			else {
				addedge(u, un);
			}
		}
		for (int j = 1; j <= m; ++j) {
			u = G[j].second.first;
			v = G[j].second.second;
			u = (u - 1) * 2, v = (v - 1) * 2;
			un = u + 1, vn = v + 1;
			if (G[j].first == 1) {
				addedge(un, v);
				addedge(vn, u);
			}
			else if (G[j].first == 2) {
				addedge(un, vn);
				addedge(v, u);
			}
			else if (G[j].first == 3) {
				addedge(u, vn);
				addedge(v, un);
			}
			else {
				addedge(u, vn);
				addedge(v, un);
				addedge(un, v);
				addedge(vn, u);
			}
		}
		if (solveable(2 * n)) {
			solve(2 * n);
			ans.clear();
			for (int j = 0; j < 2 * n; ++j) {
				if (col[block[j]] == 1 && j % 2 == 0) {
					ans.push_back(j / 2 + 1);
				}
			}
			printf("Possible");
			int size = ans.size();
			printf(" %d", size);
			for (int j = 0; j < size; ++j) {
				printf(" %d", ans[j]);
			}
			printf(".\n");
			return;
		}
	}
	printf("Impossible.\n");
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d%d", &G[i].first, &G[i].second.first, &G[i].second.second);
		}
		for (int i = 0; i < k; ++i) {
			scanf("%d%d%d%d", &g[i].first.first, &g[i].first.second, &g[i].second.first, &g[i].second.second);
		}
		printf("Case %d: ", icase++);
		go(n, m, k);
	}
	return 0;
}
