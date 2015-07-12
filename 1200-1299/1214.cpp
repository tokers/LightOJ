/*************************************************************************
    > File Name: LightOJ1214.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月12日 星期日 11时44分34秒
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

char str[400];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int b;
		scanf("%s%d", str, &b);
		int len = strlen(str);
		int s = 0;
		if (str[0] == '-') {
			++s;
		}
		LL ret = 0;
		b = abs(b);
		for (int i = s; i < len; ++i) {
			ret = ret * 10 + str[i] - '0';
			ret %= b;
		}
		if (ret == 0) {
			printf("Case %d: divisible\n", icase++);
		}
		else {
			printf("Case %d: not divisible\n", icase++);
		}
	}
	return 0;
}
