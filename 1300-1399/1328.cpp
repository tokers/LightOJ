/*************************************************************************
    > File Name: LightOJ1328.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年09月09日 星期三 18时07分56秒
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

const int mod = 1000007;
int A[100010];
LL sum[100010];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int k, c, n;
		scanf("%d%d%d%d", &k, &c, &n, &A[0]);
		for (int i = 1; i < n; ++i) {
			A[i] = ((LL)A[i - 1] * k % mod + c) % mod;
		}
		sort(A, A + n);
		sum[0] = A[0];
		for (int i = 1; i < n; ++i) {
			sum[i] = sum[i - 1] + A[i];
		}
		LL ans = 0;
		for (int i = 1; i < n; ++i) {
			LL val = (LL)i * A[i] - sum[i - 1];
			ans += val;
		}
		printf("Case %d: %lld\n", icase++, ans);
	}
	return 0;
}
