/*************************************************************************
    > File Name: LightOJ1127.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年10月02日 星期五 19时13分11秒
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

vector <LL> F;
LL Arr[44];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		F.clear();
		int n;
		LL W;
		scanf("%d%lld", &n, &W);
		for (int i = 0; i < n; ++i) {
			scanf("%lld", &Arr[i]);
		}
		LL V = 0;
		int ans = 0;
		int un = n / 2;
		for (int i = 0; i < (1 << un); ++i) {
			V = 0;
			for (int j = 0; j < un; ++j) {
				if (i & (1 << j)) {
					V += Arr[j];
				}
			}
			if (V > W) {
				continue;
			}
			F.push_back(V);
		}
		sort(F.begin(), F.end());
		int vn = n - un;
		for (int i = 0; i < (1 << vn); ++i) {
			V = 0;
			for (int j = 0; j < vn; ++j) {
				if (i & (1 << j)) {
					V += Arr[un + j];
				}
			}
			if (V > W) {
				continue;
			}
			LL rest = W - V;
			int p = upper_bound(F.begin(), F.end(), rest) - F.begin();
			ans += p;
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
