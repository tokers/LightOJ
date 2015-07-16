/*************************************************************************
    > File Name: LightOJ1148.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月16日 星期四 10时06分23秒
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

vector <int> Arr;

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		Arr.clear();
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &m);
			Arr.push_back(m);
		}
		sort(Arr.begin(), Arr.end());
		int ans = Arr[0] + 1;
		int cnt = Arr[0];
		for (int i = 1; i < n; ++i) {
			if (Arr[i] == Arr[i - 1] && cnt > 0) {
				--cnt;
				continue;
			}
			if (cnt == 0) {
				ans += Arr[i] + 1;
				cnt = Arr[i];
			}
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
