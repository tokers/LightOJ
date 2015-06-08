/*************************************************************************
    > File Name: LightOJ1015.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月08日 星期一 17时59分14秒
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

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		int sum = 0;
		int u;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &u);
			if (u > 0) {
				sum += u;
			}
		}
		printf("Case %d: %d\n", icase++, sum);
	}
	return 0;
}
