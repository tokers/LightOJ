/*************************************************************************
    > File Name: LightOJ1421.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月05日 星期三 12时58分15秒
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

const int N = 100100;
int Arr[N];
int d[N];
int L[N];
int R[N];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &Arr[i]);
		}
		L[1] = 1, R[n] = 1;
		int tot = 1;
		d[1] = Arr[1];
		for (int i = 2; i <= n; ++i) {
			if (d[tot] < Arr[i]) {
				d[++tot] = Arr[i];
				L[i] = tot;
			}
			else {
				int id = lower_bound(d + 1, d + tot + 1, Arr[i]) - d;
				d[id] = Arr[i];
				L[i] = id;
			}
		}
		d[1] = Arr[n];
		tot = 1;
		for (int i = n - 1; i >= 1; --i) {
			if (d[tot] < Arr[i]) {
				d[++tot] = Arr[i];
				R[i] = tot;
			}
			else {
				int id = lower_bound(d + 1, d + tot + 1, Arr[i]) - d;
				d[id] = Arr[i];
				R[i] = id;
			}
		}
		int ans = 1;
		for (int i = 1; i <= n; ++i) {
			ans = max(ans, min(L[i] - 1, R[i] - 1) * 2 + 1);
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
