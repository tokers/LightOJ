/*************************************************************************
    > File Name: LightOJ1117.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月05日 星期三 15时13分47秒
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

int Arr[20];
int ans;
int N, m;

LL gcd(LL a, LL b) {
	return b ? gcd(b, a % b) : a;
}

LL lcm(LL a, LL b) {
	return a / gcd(a, b) * b;
}

void dfs(int now, LL L, int cnt) {
	if (cnt > 0) {
		int sgn = (cnt & 1) ? 1 : -1;
		ans += sgn * N / L;
	}
	for (int i = now; i < m; ++i) {
		LL x = lcm(L, Arr[i]);
		dfs(i + 1, x, cnt + 1);
	}
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &N, &m);
		ans = 0;
		int u;
		for (int i = 0; i < m; ++i) {
			scanf("%d", &Arr[i]);
		}
		dfs(0, 1, 0);
		printf("Case %d: %d\n", icase++, N - ans);
	}
	return 0;
}
