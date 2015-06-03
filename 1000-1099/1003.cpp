/*************************************************************************
    > File Name: LightOJ1003.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月03日 星期三 10时19分43秒
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

static const int N = 10100;
struct node {
	int nxt;
	int to;
}edge[N + 10];
int head[N], tot;

void addedge(int from, int to) {
	edge[tot].to = to;
	edge[tot].nxt = head[from];
	head[from] = tot++;
}
map <string, int> mp;
char A[20], B[20];
int in_deg[N];

void toposort(int n) {
	queue <int> qu;
	int rest = n;
	for (int i = 1; i <= n; ++i) {
		if (!in_deg[i]) {
			qu.push(i);
		}
	}
	while (!qu.empty()) {
		int u = qu.front();
		qu.pop();
		--rest;
		for (int i = head[u]; ~i; i = edge[i].nxt) {
			int v = edge[i].to;
			--in_deg[v];
			if (!in_deg[v]) {
				qu.push(v);
			}
		}
	}
	if (rest) {
		printf("No\n");
	}
	else {
		printf("Yes\n");
	}
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		mp.clear();
		int m;
		scanf("%d", &m);
		memset(head, -1, sizeof(head));
		tot = 0;
		int n = 0;
		memset(in_deg, 0, sizeof(in_deg));
		for (int i = 1; i <= m; ++i) {
			scanf("%s%s", A, B);
			if (mp.find(A) == mp.end()) {
				mp[A] = ++n;
			}
			if (mp.find(B) == mp.end()) {
				mp[B] = ++n;
			}
			++in_deg[mp[B]];
			addedge(mp[A], mp[B]);
		 }
		printf("Case %d: ", icase++);
		toposort(n);
	}
	return 0;
}
