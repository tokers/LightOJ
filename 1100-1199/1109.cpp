/*************************************************************************
    > File Name: LightOJ1109.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月15日 星期三 18时56分58秒
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

struct node {
	int x;
	int numx;
	bool operator < (const node &b) const {
		if (numx == b.numx) {
			return x > b.x;
		}
		return numx < b.numx;
	}
}Arr[1010];

int main() {
	for (int i = 1; i <= 1000; ++i) {
		Arr[i].x = i;
		Arr[i].numx = 0;
		for (int j = 1; j * j <= i; ++j) {
			if (i % j == 0) {
				++Arr[i].numx;
				if (i / j != j) {
					++Arr[i].numx;
				}
			}
		}
	}
	sort(Arr + 1, Arr + 1001);
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("Case %d: %d\n", icase++, Arr[n].x);
	}
	return 0;
}
