/*************************************************************************
    > File Name: LightOJ1425.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月01日 星期六 09时13分00秒
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

const int N = 100100;
int Arr[N];

bool check(int k, int n) {
	int cur = 0;
	for (int i = 1; i <= n; ++i) {
		if (Arr[i] - cur > k) {
			return 0;
		}
		if (Arr[i] - cur == k) {
			--k;
		}
		cur = Arr[i];
	}
	return 1;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &Arr[i]);
		}
		int ans = -1;
		int l = 1, r = 1000000000, mid;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (check(mid, n)) {
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
