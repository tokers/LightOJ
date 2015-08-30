/*************************************************************************
    > File Name: LightOJ1256.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月29日 星期六 17时56分33秒
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

const int N = 1010;
char str[N][25];
vector <PLL> edge[N];
stack <int> st;
int fa[N];
bool vis[N];

int Find(int x) {
	if (fa[x] == -1) {
		return x;
	}
	return fa[x] = Find(fa[x]);
}

void dfs(int u) {
	while (!edge[u].empty()) {
		PLL now = edge[u].back();
		int v = now.second;
		edge[u].pop_back();
		dfs(v);
		st.push(now.first);
	}
}

int in[N], out[N];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		memset(vis, 0, sizeof(vis));
		memset(fa, -1, sizeof(fa));
		for (int i = 1; i <= 26; ++i) {
			edge[i].clear();
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%s", str[i]);
			int len = strlen(str[i]);
			int x = str[i][0] - 'a' + 1;
			int y = str[i][len - 1] - 'a' + 1;
			edge[x].push_back(make_pair(i, y));
			int u = Find(x);
			int v = Find(y);
			if (u != v) {
				fa[u] = v;
			}
			vis[x] = vis[y] = 1;
			++in[y];
			++out[x];
		}
		printf("Case %d: ", icase++);
		int res = 0;
		for (int i = 1; i <= 26; ++i) {
			if (vis[i]) {
				if (fa[i] == -1) {
					++res;
				}
			}
		}
		if (res > 1) {
			printf("No\n");
			continue;
		}
		bool flag = 0;
		int a = 0, b = 0;
		int start;
		for (int i = 1; i <= 26; ++i) {
			if (vis[i]) {
				start = i;
				break;
			}
		}
		for (int i = 1; i <= 26; ++i) {
			if (vis[i]) {
				if (in[i] == out[i] - 1) {
					++a;
					start = i;
				}
				else if (in[i] == out[i] + 1) {
					++b;
				}
				else if (in[i] != out[i]) {
					flag = 1;
					break;
				}
			}
		}
		if (flag || !((a == 0 && b == 0) || (a == 1 && b == 1))) {
			printf("No\n");
			continue;
		}
		dfs(start);
		printf("Yes\n");
		while (!st.empty()) {
			int s = st.top();
			st.pop();
			printf("%s", str[s]);
			if (st.empty()) {
				printf("\n");
			}
			else {
				printf(" ");
			}
		}
	}
	return 0;
}
