/*************************************************************************
    > File Name: LightOJ1220.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月12日 星期日 12时09分17秒
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

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

vector <int> fac;

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		LL n;
		scanf("%lld", &n);
		fac.clear();
		int sgn = (n < 0 ? -1 : 1);
		n = abs(n);
		for (LL i = 2; i * i <= n; ++i) {
			if (n % i == 0) {
				int cnt = 0;
				while (n % i == 0) {
					n /= i;
					++cnt;
				}
				fac.push_back(cnt);
			}
		}
		if (n > 1) {
			fac.push_back(1);
		}
		int g = fac[0];
		int size =fac.size();
		for (int i = 1; i < size; ++i) {
			g = gcd(g, fac[i]);
		}
		if (sgn == -1 && g % 2 == 0) {
			int x = 1;
			for (int i = 2; i * i <= g; ++i) {
				if (g % i == 0) {
					if (i & 1) {
						x = max(x, i);
					}
					if ((g / i) & 1) {
						x = max(x, g / i);
					}
				}
			}
			g = x;
		}
		printf("Case %d: %d\n", icase++, g);
	}
	return 0;
}
