/*************************************************************************
    > File Name: LightOJ1075.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月09日 星期四 16时38分22秒
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

const int N = 1000;
map <string, int> mp1;
vector <int> Arr;
int ind[N];
int outd[N];

struct node {
	char str1[100];
	char str2[100];
}USE[400];

struct Edge {
	int nxt;
	int to;
	int id;
	bool flag;
}edge[N << 2];
int head[N], tot;

void addedge(int from, int to, int id) {
	edge[tot].to = to;
	edge[tot].nxt = head[from];
	edge[tot].flag = 0;
	edge[tot].id = id;
	head[from] = tot++;
}

char str1[100];
char str2[100];

void dfs(int u) {
	for (int i = head[u]; ~i; i = edge[i].nxt) {
		int v = edge[i].to;
		if (!edge[i].flag) {
			Arr.push_back(edge[i].id);
			edge[i].flag = 1;
			dfs(v);
		}
	}
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int S;
		scanf("%d", &S);
		int cnt = 0;
		mp1.clear();
		memset(head, -1, sizeof(head));
		tot = 0;
		memset(ind, 0, sizeof(ind));
		memset(outd, 0, sizeof(outd));
		for (int i = 1; i <= S - 1; ++i) {
			scanf("%s%s", str1, str2);
			strcpy(USE[i].str1, str1);
			strcpy(USE[i].str2, str2);
			if (mp1.find(str1) == mp1.end()) {
				mp1[str1] = ++cnt;
			}
			if (mp1.find(str2) == mp1.end()) {
				mp1[str2] = ++cnt;
			}
			int u = mp1[str1];
			int v = mp1[str2];
			++ind[v];
			++outd[u];
			addedge(u, v, i);
		}
		Arr.clear();
		int s = 1;
		for (int i = 1; i <= cnt; ++i) {
			if (ind[i] == outd[i] - 1) {
				s = i;
				break;
			}
		}
		dfs(s);
		printf("Case %d:\n", icase++);
		printf("%s\n%s\n", USE[Arr[0]].str1, USE[Arr[0]].str2);
		for (int i = 1; i <= S - 2; ++i) {
			printf("%s\n", USE[Arr[i]].str2);
		}
		printf("\n");
	}
	return 0;
}
