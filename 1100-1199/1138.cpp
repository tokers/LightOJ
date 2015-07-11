/*************************************************************************
    > File Name: LightOJ1138.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月11日 星期六 12时50分36秒
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

int five[20];
LL beishu[20];

int main() {
	int t, icase = 1;
	beishu[0] = 1;
	for (int i = 1; i <= 19; ++i) {
		beishu[i] = beishu[i - 1] * 5;
	}
	scanf("%d", &t);
	while (t--) {
		int q;
		scanf("%d", &q);
		int l = 1, r = 1000000000, mid, ans = -1;
		while (l <= r) {
			mid = (l + r) >> 1;
			LL tmp = 0;
			memset(five, 0, sizeof(five));
			for (int i = 19; i >= 1; --i) {
				five[i] = mid / beishu[i];
				for (int j = i + 1; j < 20; ++j) {
					five[i] -= five[j];
				}
				tmp += five[i] * i;
			}
			if (tmp >= q) {
				r = mid - 1;
				if (tmp == q) {
					ans = mid;
				}
			}
			else {
				l = mid + 1;
			}
		}
		if (ans == -1) {
			printf("Case %d: impossible\n", icase++);
		}
		else {
			printf("Case %d: %d\n", icase++, ans);
		}
	}
	return 0;
}
