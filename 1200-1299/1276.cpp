/*************************************************************************
    > File Name: LightOJ1276.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年10月02日 星期五 19时56分23秒
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

vector <LL> luck;
vector <LL> vluck;
set <LL> st;

void dfs(LL val) {
	if (val) {
		luck.push_back(val);
	}
	if (val * 10 + 4 <= 1000000000000LL) {
		dfs(val * 10 + 4);
	}
	if (val * 10 + 7 <= 1000000000000LL) {
		dfs(val * 10 + 7);
	}
}

int main() {
	luck.clear();
	vluck.clear();
	dfs(0);
	sort(luck.begin(), luck.end());
	st.clear();
	int size = luck.size();
	for (int i = 0; i < size; ++i) {
		st.insert(luck[i]);
	}
	for (set <LL> :: iterator it = st.begin(); it != st.end(); ++it) {
		LL val = *it;
		for (int j = 0; j < size; ++j) {
			if (val * luck[j] > 1000000000000LL) {
				break;
			}
			st.insert(val * luck[j]);
		}
	}
	for (set <LL> :: iterator it = st.begin(); it != st.end(); ++it) {
		vluck.push_back(*it);
	}
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		LL l, r;
		scanf("%lld%lld", &l, &r);
		int size = vluck.size();
		int ans = 0;
		if (r >= 4) {
			int p = lower_bound(vluck.begin(), vluck.end(), r) - vluck.begin();
			if (p == size || vluck[p] > r) {
				--p;
			}
			ans = p + 1;
		}
		if (l - 1 >= 4) {
			int p = lower_bound(vluck.begin(), vluck.end(), l - 1) - vluck.begin();
			if (p == size || vluck[p] > l - 1) {
				--p;
			}
			ans -= (p + 1);
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
