/*************************************************************************
    > File Name: LightOJ1035.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月12日 星期五 21时55分26秒
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

vector <PLL> Arr[110];
int use[110];

int main() {
	for (int i = 1; i <= 100; ++i) {
		Arr[i].clear();
	}
	for (int i = 2; i <= 100; ++i) {
		int u = i;
		for (int j = 2; j * j <= u; ++j) {
			if (u % j == 0) {
				int tmp1 = j, tmp2 = 0;
				while (u % j == 0) {
					u /= j;
					++tmp2;
				}
				Arr[i].push_back(make_pair(tmp1, tmp2));
			}
		}
		if (u > 1) {
			Arr[i].push_back(make_pair(u, 1));
		}
	}
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			use[i] = 0;
		}
		for (int i = 2; i <= n; ++i) {
			int size = Arr[i].size();
			for (int j = 0; j < size; ++j) {
				use[Arr[i][j].first] += Arr[i][j].second;
			}
		}
		printf("Case %d: %d = ", icase++, n);
		int cnt = 0;
		for (int i = 2; i <= n; ++i) {
			if (use[i]) {
				++cnt;
			}
		}
		for (int i = 2; i <= n; ++i) {
			if (use[i]) {
				printf("%d (%d)", i, use[i]);
				--cnt;
				if (cnt > 0) {
					printf(" * ");
				}
			}
		}
		printf("\n");
	}
	return 0;
}
