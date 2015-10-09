/*************************************************************************
    > File Name: LightOJ1224.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年10月09日 星期五 16时29分55秒
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
	int next[2500010][4];
	int end[2500010];
	int ll[2500010];
	int root, L;

	int newnode() {
		for (int i = 0; i < 4; ++i) {
			next[L][i] = -1;
		}
		end[L++] = 0;
		return L - 1;
	}

	void init() {
		L = 0;
		root = newnode();
	}

	int Id(char a) {
		if (a == 'A') {
			return 0;
		}
		if (a == 'G') {
			return 1;
		}
		if (a == 'T') {
			return 2;
		}
		return 3;
	}

	void insert(char str[]) {
		int now = root;
		int l = 0;
		int len = strlen(str);
		for (int i = 0; i < len; ++i) {
			if (next[now][Id(str[i])] == -1) {
				next[now][Id(str[i])] = newnode();
			}
			now = next[now][Id(str[i])];
			ll[now] = ++l;
			++end[now];
		}
	}
	
	LL solve() {
		LL ans = 0;
		for (int i = 1; i < L; ++i) {
			ans = max(ans, (LL)ll[i] * end[i]);
		}
		return ans;
	}
}T;

char str[55];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		T.init();
		for (int i = 0; i < n; ++i) {
			scanf("%s", str);
			T.insert(str);
		}
		printf("Case %d: %lld\n", icase++, T.solve());
	}
	return 0;
}

