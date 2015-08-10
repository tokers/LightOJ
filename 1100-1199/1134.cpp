/*************************************************************************
    > File Name: LightOJ1134.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月10日 星期一 20时57分45秒
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

int sum[100010];
int Arr[100010];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &Arr[i]);
		}
		LL ans = 0;
		memset(sum, 0, sizeof(sum));
		sum[0] = 1;
		int s = 0;
		for (int i = 1; i <= n; ++i) {
			s += Arr[i];
			s %= m;
			ans += sum[s];
			++sum[s];
		}
		printf("Case %d: %lld\n", icase++, ans);
	}
	return 0;
}
