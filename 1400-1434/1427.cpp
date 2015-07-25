/*************************************************************************
    > File Name: LightOJ1427.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月25日 星期六 14时41分26秒
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

const int MAX_NODE = 250000;
const int CHILD_NUM = 26;
char str[1000100];
char s[555];
int cnt[555];

struct AC_Automation {
	int next[MAX_NODE][CHILD_NUM];
	int fail[MAX_NODE];
	vector <int> end[MAX_NODE];
	int root, L;

	int newnode() {
		for (int i = 0; i < CHILD_NUM; ++i) {
			next[L][i] = -1;
		}
		end[L++].clear();
		return L - 1;
	}

	void init() {
		L = 0;
		root = newnode();
	}

	void Build_Trie(char buf[], int id) {
		int now = root;
		int len = strlen(buf);
		for (int i = 0; i < len; ++i) {
			if (next[now][buf[i] - 'a'] == -1) {
				next[now][buf[i] - 'a'] = newnode();
			}
			now = next[now][buf[i] - 'a'];
		}
		end[now].push_back(id);
	}

	void Build_AC() {
		queue <int> qu;
		fail[root] = root;
		for (int i = 0; i < CHILD_NUM; ++i) {
			if (next[root][i] == -1) {
				next[root][i] = root;
			}
			else {
				fail[next[root][i]] = root;
				qu.push(next[root][i]);
			}
		}
		while (!qu.empty()) {
			int now = qu.front();
			qu.pop();
			for (int i = 0; i < CHILD_NUM; ++i) {
				if (next[now][i] == -1) {
					next[now][i] = next[fail[now]][i];
				}
				else {
					fail[next[now][i]] = next[fail[now]][i];
					qu.push(next[now][i]);
				}
			}
		}
	}
	
	void Match(char str[]) {
		int now = root;
		memset(cnt, 0, sizeof(cnt));
		int len = strlen(str);
		for (int i = 0; i < len; ++i) {
			now = next[now][str[i] - 'a'];
			int tmp = now;
			while (tmp != root) {
				int size = end[tmp].size();
				for (int j = 0; j < size; ++j) {
					++cnt[end[tmp][j]];
				}
				tmp = fail[tmp];
			}
		}
	}
}AC;

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		AC.init();
		scanf("%s", str);
		for (int i = 1; i <= n; ++i) {
			scanf("%s", s);
			AC.Build_Trie(s, i);
		}
		AC.Build_AC();
		AC.Match(str);
		printf("Case %d:\n", icase++);
		for (int i = 1; i <= n; ++i) {
			printf("%d\n", cnt[i]);
		}
	}
	return 0;
}
