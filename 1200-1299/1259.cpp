/*************************************************************************
    > File Name: LightOJ1259.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月13日 星期一 13时30分59秒
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

const int S = 8; 
 
bool valid[10000100];
int prime[700000];
int tot;

void getprime() {
	int n = 10000000;
	for (int i = 2; i <= n; ++i) {
		valid[i] = 1;
	}
	valid[1] = 0;
	for (int i = 2; i <= n; ++i) {
		if (valid[i]) {
			if (n / i < i) {
				break;
			}
			for (int j = i * i; j <= n; j += i) {
				valid[j] = 0;
			}
		}
	}
	tot = 0;
	for (int i = 2; i <= n / 2; ++i) {
		if (valid[i]) {
			prime[++tot] = i;
		}
	}
}

int main() {
	getprime();
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int ans = 0;
		for (int i = 1; i <= tot; ++i) {
			if (prime[i] > n / 2) {
				break;
			}
			int m = n - prime[i];
			if (valid[m]) {
				++ans;
			}
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
