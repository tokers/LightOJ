/*************************************************************************
    > File Name: LightOJ1114.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月27日 星期一 21时40分13秒
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

const int N = 100010;
struct TRIE {
	int next[N][52];
	int end[N];
	int root, L;

	int newnode() {
		for (int i = 0; i < 52; ++i) {
			next[L][i] = -1;
		}
		end[L++] = 0;
		return L - 1;
	}

	void init() {
		L = 0;
		root = newnode();
	}

	void insert(char buf[]) {
		int len = strlen(buf);
		int now = root;
		for (int i = 0; i < len; ++i) {
			int id;
			if (islower(buf[i])) {
				id = buf[i] - 'a';
			}
			else {
				id = buf[i] - 'A' + 26;
			}
			if (next[now][id] == -1) {
				next[now][id] = newnode();
			}
			now = next[now][id];
		}
		++end[now];
	}

	int query(char buf[]) {
		int now = root;
		int len = strlen(buf);
		for (int i = 0; i < len; ++i) {
			int id;
			if (islower(buf[i])) {
				id = buf[i] - 'a';
			}
			else {
				id = buf[i] - 'A' + 26;
			}
			if (next[now][id] == -1) {
				return 0;
			}
			now = next[now][id];
		}
		return end[now];
	}
}trie;

char buf[110];
char str[100010];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d", &n);
		trie.init();
		int maxs = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%s", buf);
			int len = strlen(buf);
			if (len >= 4) {
				sort(buf + 1, buf + len - 1);
			}
			maxs = max(maxs, len);
			trie.insert(buf);
		}
		scanf("%d", &m);
		printf("Case %d:\n", icase++);
		getchar();
		while (m--) {
			bool flag = 1;
			int ans = 1;
			char c;
			int cnt = 0;
			bool x = 0;
			while ((c = getchar()) != '\n') {
				x = 1;
				if (!flag) {
					continue;
				}
				if (c == ' ') {
					if (cnt == 0) {
						continue;
					}
					if (cnt > maxs) {
						flag = 0;
						continue;
					}
					str[cnt] = '\0';
					if (cnt >= 4) {
						sort(str + 1, str + cnt - 1);
					}
					ans *= trie.query(str);
					cnt = 0;
				}
				else {
					str[cnt++] = c;
				}
			}
			if (!x) {
				printf("1\n");
				continue;
			}
			str[cnt] = '\0';
			if (cnt > maxs) {
				ans = 0;
			}
			else {
				if (cnt >= 4) {
					sort(str + 1, str + cnt - 1);
				}
				if (cnt >= 1) {
					ans *= trie.query(str);
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
