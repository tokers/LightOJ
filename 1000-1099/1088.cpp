/*************************************************************************
    > File Name: LightOJ1088.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月07日 星期二 15时28分38秒
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

const int N = 100110;
int Arr[N];

int Find1(int n, int val) {
	if (Arr[1] >= val) {
		return 1;
	}
	int ans, l = 1, r = n, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (Arr[mid] >= val) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return ans;
}

int Find2(int n, int val) {
	if (val >= Arr[n]) {
		return n;
	}
	int l = 1, r = n, mid, ans;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (Arr[mid] <= val) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return ans;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &Arr[i]);
		}
		int l, r;
		printf("Case %d:\n", icase++);
		while (m--) {
			scanf("%d%d", &l, &r);
			if (r < Arr[1] || l > Arr[n]) {
				printf("0\n");
				continue;
			}
			l = Find1(n, l);
			r = Find2(n, r);
			printf("%d\n", r - l + 1);
		}
	}
	return 0;
}
