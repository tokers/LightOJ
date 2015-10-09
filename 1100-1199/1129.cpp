/*************************************************************************
    > File Name: LightOJ1129.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年10月09日 星期五 16时43分47秒
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

struct Trie {
	int next[100010][10];
	int end[100010];
	int root, L;

	void init() {
		L = 0;
		root = newnode();
	}

	int newnode() {
		for (int i = 0; i < 10; ++i) {
			next[L][i] = -1;
		}
		end[L++] = 0;
		return L - 1;
	}

	void insert(char str[]) {
		int now = root;
		int len = strlen(str);
		for (int i = 0; i < len; ++i) {
			if (next[now][str[i] - '0'] == -1) {
				next[now][str[i] - '0'] = newnode();
			}
			now = next[now][str[i] - '0'];
		}
		++end[now];
	}

	bool ok(char str[]) {
		int len = strlen(str);
		int now = root;
		for (int i = 0; i < len; ++i) {
			now = next[now][str[i] - '0'];
			if (end[now] && i < len - 1) {
				return 0;
			}
		}
		return 1;
	}
}T;

char str[10010][15];
int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		T.init();
		for (int i = 0; i < n; ++i) {
			scanf("%s", str[i]);
			T.insert(str[i]);
		}
		bool flag = 1;
		for (int i = 0; i < n; ++i) {
			flag = T.ok(str[i]);
			if (!flag) {
				break;
			}
		}
		printf("Case %d: %s\n", icase++, flag ? "YES" : "NO");
	}
	return 0;
}
