/*************************************************************************
    > File Name: LightOJ1198.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月31日 星期五 12时59分19秒
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

int A[55];
int B[55];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &A[i]);
		}
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &B[i]);
		}
		sort(A + 1, A + n + 1);
		sort(B + 1, B + n + 1);
		int s1 = 1, e1 = n, s2 = 1, e2 = n;
		int ans = 0;
		while (1) {
			if (s1 > e1 || s2 > e2) {
				break;
			}
			if (A[e1] > B[e2]) {
				ans += 2;
				--e1;
				--e2;
				continue;
			}
			if (A[s1] > B[s2]) {
				ans += 2;
				++s1;
				++s2;
				continue;
			}
			if (A[s1] >= B[e2]) {
				if (A[s1] == B[e2]) {
					++ans;
				}
				else {
					ans += 2;
				}
				++s1;
				--e2;
			}
			else {
				++s1;
				--e2;
			}
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
