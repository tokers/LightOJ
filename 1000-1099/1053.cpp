/*************************************************************************
    > File Name: LightOJ1053.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月27日 星期六 11时35分50秒
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

int a[5];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &a[0], &a[1], &a[2]);
		sort(a, a + 3);
		int x = a[0], y = a[1], z = a[2];
		if (x + y <= z) {
			printf("Case %d: no\n", icase++);
			continue;
		}
		if (x * x + y * y != z * z) {
			printf("Case %d: no\n", icase++);
		}
		else {
			printf("Case %d: yes\n", icase++);
		}
	}
	return 0;
}
