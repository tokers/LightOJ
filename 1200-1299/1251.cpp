/*************************************************************************
    > File Name: LightOJ1251.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年09月02日 星期三 19时54分03秒
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

const int N = 20010;
struct Edge {
	int nxt;
	int to;
}edge[N << 1];
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

char A[20], B[20];
int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m, u, v;
		init();
		scanf("%d%d", &m, &n);
		for (int i = 1; i <= m; ++i) {
			scanf("%s%s", A, B);
			u = v = 0;
			int lena = strlen(A);
			for (int j = 1; j < lena; ++j) {
				u = u * 10 + A[j] - '0';
			}
			int lenb = strlen(B);
			for (int j = 1; j < lenb; ++j) {
				v = v * 10 + B[j] - '0';
			}
			u = (u - 1) * 2;
			int _u = u + 1;
			v = (v - 1) * 2;
			int _v = v + 1;
			if (A[0] == '+' && B[0] == '+') {
				addedge(_u, v);
				addedge(_v, u);
			}
			else if (A[0] == '+' && B[0] == '-') {
				addedge(_u, _v);
				addedge(v, u);
			}
			else if (A[0] == '-' && B[0] == '+') {
				addedge(u, v);
				addedge(_v, _u);
			}
			else {
				addedge(u, _v);
				addedge(v, _u);
			}
		}
		printf("Case %d: ", icase++);
		if (solveable(2 * n)) {
			printf("Yes\n");
			solve(2 * n);
			int cnt = 0;
			for (int i = 0; i < 2 * n; ++i) {
				if (col[block[i]] == 1) {
					if (i % 2 == 0) {
						++cnt;
					}
				}
			}
			printf("%d", cnt);
			for (int i = 0; i < 2 * n; ++i) {
				if (col[block[i]] == 1) {
					if (i % 2 == 0) {
						printf(" %d", i / 2 + 1);
					}
				}
			}
			printf("\n");
		}
		else {
			printf("No\n");
		}
	}
	return 0;
}
