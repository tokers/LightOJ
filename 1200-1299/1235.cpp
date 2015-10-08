/*************************************************************************
    > File Name: LightOJ1235.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年10月08日 星期四 14时45分48秒
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

set <LL> st;
int arr[20];
int mi[20];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	mi[0] = 1;
	for (int i = 1; i <= 9; ++i) {
		mi[i] = mi[i - 1] * 3;
	} 
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
		}
		st.clear();
		int un = n / 2;
		for (int i = 0; i < mi[un]; ++i) {
			LL val = 0;
			int sta = i;
			for (int j = 0; j < un; ++j) {
				val += (sta % 3) * arr[j];
				sta /= 3;
			}
			st.insert(val);
		}
		bool flag = 0;
		int vn = n - un;
		for (int i = 0; i < mi[vn]; ++i) {
			LL val = 0;
			int sta = i;
			for (int j = un; j < n; ++j) {
				val += (sta % 3) * arr[j];
				sta /= 3;
			}
			if (val <= k) {
				if (st.find(k - val) != st.end()) {
					flag = 1;
					break;
				}
			}
		}
		printf("Case %d: %s\n", icase++, flag ? "Yes" : "No");
	}
	return 0;
}
