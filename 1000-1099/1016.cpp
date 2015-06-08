/*************************************************************************
    > File Name: LightOJ1016.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月08日 星期一 18时10分14秒
 ************************************************************************/

#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <set>
#include <vector>

using namespace std;

const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef pair <int, int> PLL;

static const int N = 50010;
set <int> st;
set <int> :: iterator it;

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, w;
		scanf("%d%d", &n, &w);
		st.clear();
		int x, y;
		for (int i = 1; i <= n; ++i) {
			scanf("%d%d", &x, &y);
			if (st.find(y) == st.end()) {
				st.insert(y);
			}
		}
		int ans = 0;
		int s = *st.begin();
		while (1) {
			int tar = s + w;
			if (st.find(tar) != st.end()) {
				it = st.find(tar);
				++ans;
				++it;
				if (it == st.end()) {
					break;
				}
				else {
					s = *it;
				}
			}
			else {
				st.insert(tar);
				it = st.find(tar);
				++ans;
				++it;
				if (it == st.end()) {
					break;
				}
				else {
					s = *it;
					st.erase(tar);
				}
			}
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
