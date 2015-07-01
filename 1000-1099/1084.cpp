/*************************************************************************
    > File Name: LightOJ1084.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月01日 星期三 14时42分45秒
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

const int N = 100010;
int dp[N];
int Arr[N];
int qu[N];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		int head = 0, tail = -1;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &Arr[i]);
		}
		memset(dp, inf, sizeof(dp));
		sort(Arr + 1, Arr + n + 1);
		dp[0] = 0;
		qu[++tail] = 0;
		for (int i = 1; i <= n; ++i) {
			while (tail >= head) {
				if (qu[head] == 0) {
					if (Arr[i] - k - Arr[1] - k > 0) {
						++head;
					}
					else {
						break;
					}
				}
				else {
					if (Arr[i] - Arr[qu[head] + 1] - 2 * k > 0) {
						++head;
					}
					else {
						break;
					}
				}
			}
			if (tail < head) {
				continue;
			}
			if (qu[head]) {
				if (i - qu[head] < 3) {
					continue;
				}
			}
			else {
				if (i < 3) {
					continue;
				}
			}
			dp[i] = dp[qu[head]] + 1;
			while (tail >= head && dp[i] < dp[qu[tail]]) {
				--tail;
			}
			qu[++tail] = i;
		}
		if (dp[n] == inf) {
			printf("Case %d: -1\n", icase++);
		}
		else {
			printf("Case %d: %d\n", icase++, dp[n]);
		}
	}
	return 0;
}
