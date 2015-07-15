/*************************************************************************
    > File Name: LightOJ1163.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月15日 星期三 19时29分53秒
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

vector <ULL> ans;

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		ULL v;
		scanf("%llu", &v);
		v *= 10;
		ans.clear();
		printf("Case %d: ", icase++);
		for (int i = 0; i < 10; ++i) {
			if ((v - i) % 9) {
				continue;
			}
			if ((v - i) / 9 % 10 == i) {
				ans.push_back((v - i) / 9);
			}
		}
		sort(ans.begin(), ans.end());
		int size = ans.size();
		printf("%llu", ans[0]);
		for (int i = 1; i < size; ++i) {
			printf(" %llu", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
