/*************************************************************************
    > File Name: LightOJ1078.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月07日 星期二 15时13分16秒
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

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, a;
		scanf("%d%d", &n, &a);
		int ans = 1;
		int mod = a % n;
		while (1) {
			if (mod == 0) {
				break;
			}
			++ans;
			mod =(mod * 10 + a) % n;
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
