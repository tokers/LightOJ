/*************************************************************************
    > File Name: LightOJ1301.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月31日 星期五 14时13分49秒
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

pair <int, bool> arr[100010];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int si, ti;
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", &si, &ti);
			arr[i].first = si;
			arr[i].second = 0;
			arr[i + n].first = ti;
			arr[i + n].second = 1;
		}
		sort(arr + 1, arr + 2 * n + 1);
		int ans = -1, cnt = 0;
		for (int i = 1; i <= 2 * n; ++i) {
			if (arr[i].second == 0) {
				++cnt;
			}
			else {
				--cnt;
			}
			ans = max(ans, cnt);
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
