/*************************************************************************
    > File Name: LightOJ1076.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月02日 星期四 18时05分54秒
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
int Arr[N];

bool judge(int cap, int m, int n) {
	int sum = 1;
	int now = Arr[1];
	if (cap < Arr[1]) {
		return 0;
	}
	for (int i = 2; i <= n; ++i) {
		if (cap < Arr[i]) {
			return 0;
		}
		if (now + Arr[i] <= cap) {
			now += Arr[i];
		}
		else {
			++sum;
			now = Arr[i];
		}
	}
	return sum <= m;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m, sum = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &Arr[i]);
			sum += Arr[i];
		}
		int l = 1, r = sum, mid, ans;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (judge(mid, m, n)) {
				ans = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
