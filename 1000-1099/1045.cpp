/*************************************************************************
    > File Name: LightOJ1045.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月26日 星期五 17时40分04秒
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

double sum[1000100];

int main() {
	sum[1] = 0;
	for (int i = 2; i <= 1000000; ++i) {
		sum[i] = sum[i - 1] + log(i * 1.0);
	}
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, b;
		scanf("%d%d", &n, &b);
		double ans = sum[n];
		if (n == 0) {
			printf("Case %d: 1\n", icase++);
			continue;
		}
		ans /= log(b * 1.0);
		printf("Case %d: %d\n", icase++, (int)ans + 1);
	}
	return 0;
}
