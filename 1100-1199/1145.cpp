/*************************************************************************
    > File Name: LightOJ1145.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月04日 星期二 10时49分27秒
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

const int mod = 100000007;
int sum[15010];
int tmp[15010];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, k, S;
		scanf("%d%d%d", &n, &k, &S);
		memset(sum, 0, sizeof(sum));
		memset(tmp, 0, sizeof(tmp));
		sum[0] = 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = i; j <= min(i * k, S); ++j) {
				int l = j - k - 1;
				if (l < 0) {
					l = 0;
				}
				int now = sum[j - 1];
				if (l > 0) {
					now -= sum[l];
				}
				now = (now + mod) % mod;
				tmp[j] = tmp[j - 1] + now;
				tmp[j] %= mod;
			}
			for (int j = 0; j <= min(i * k, S); ++j) {
				sum[j] = tmp[j];
				tmp[j] = 0;
			}
		}
		printf("Case %d: %d\n", icase++, sum[S]);
	}
	return 0;
}
