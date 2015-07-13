/*************************************************************************
    > File Name: LightOJ1234.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月12日 星期日 14时00分53秒
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

double fun[1001000];

int main() {
	double sum = 0;
	int tot = 0;
	for (int i = 1; i <= 100000000; ++i) {
		sum += (1.0 / i);
		if (i % 100 == 1) {
			fun[++tot] = sum;
		}
	}
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int pos = 0;
		if (n % 100 == 0) {
			pos = n / 100;
		}
		else {
			pos = n / 100 + 1;
		}
		double ans = fun[pos];
		for (int i = (pos - 1) * 100 + 2; i <= n; ++i) {
			ans += 1.0 / i;
		}
		printf("Case %d: %.12f\n", icase++, ans);
	}
	return 0;
}
