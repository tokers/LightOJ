/*************************************************************************
    > File Name: LightOJ1090.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月05日 星期日 18时46分33秒
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

const int N = 1001000;
int sum[N][2];

int main() {
	memset(sum, 0, sizeof(sum));
	for (int i = 2; i <= 1000000; ++i) {
		int u = i;
		while (u % 2 == 0) {
			u /= 2;
			++sum[i][0];
		}
		while (u % 5 == 0) {
			u /= 5;
			++sum[i][1];
		}
	}
	for (int i = 2; i <= 1000000; ++i) {
		sum[i][1] += sum[i - 1][1];
		sum[i][0] += sum[i - 1][0];
	}
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, r, p, q;
		scanf("%d%d%d%d", &n, &r, &p, &q);
		int two = sum[n][0] - sum[n - r][0];
		int five = sum[n][1] - sum[n - r][1];
		two -= sum[r][0];
		five -= sum[r][1];
		two += (sum[p][0] - sum[p - 1][0]) * q;
		five += (sum[p][1] - sum[p - 1][1]) * q;
		printf("Case %d: %d\n", icase++, min(two, five));
	}
	return 0;
}
