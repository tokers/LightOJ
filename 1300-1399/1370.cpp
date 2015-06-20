/*************************************************************************
    > File Name: LightOJ1370.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月20日 星期六 14时32分05秒
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

int phi[2000100];
int minS[2000100];
int minDiv[2000100];

void geteuler() {
	for (int i = 1; i <= 2000000; ++i) {
		minDiv[i] = i;
		minS[i] = inf;
	}
	for (int i = 2; i <= 2000000; ++i) {
		if (minDiv[i] == i) {
			if (2000000 / i < i) {
				break;
			}
			for (int j = (LL)i * i; j <= 2000000; j += i) {
				minDiv[j] = i;
			}
		}
	}
	int high = 1;
	phi[1] = 1;
	for (int i = 2; i <= 2000000; ++i) {
		phi[i] = phi[i / minDiv[i]];
		if ((i / minDiv[i]) % minDiv[i]) {
			phi[i] *= (minDiv[i] - 1);
		}
		else {
			phi[i] *= minDiv[i];
		}
		high = max(high, phi[i]);
	}
	for (int i = 2; i <= 2000000; ++i) {
		minS[phi[i]] = min(minS[phi[i]], i);
	}
	int use = minS[high];
	for (int i = high - 1; i >= 1; --i) {
		minS[i] = min(minS[i], use);
		use = min(use, minS[i]);
	}
}

int main() {
	geteuler();
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, now;
		LL ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &now);
			ans += minS[now];
		}
		printf("Case %d: %lld Xukha\n", icase++, ans);
	}
	return 0;
}

