/*************************************************************************
    > File Name: LightOJ1341.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月20日 星期六 15时21分49秒
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
bool valid[1000100];
int prime[100000];
int tot;

void getprime() {
	int n = 1000000;
	valid[1] = 0;
	for (int i = 2; i <= n; ++i) {
		valid[i] = 1;
	}
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
	for (int i = 2; i <= n; ++i) {
		if (valid[i]) {
			prime[++tot] = i;
		}
	}
}
 
vector < pair <LL, int> > Arr;
vector <LL> fact;

void bfs() {
	queue < pair <LL, int> > qu;
	LL now = 1;
	qu.push(make_pair(1, 0));
	for (int i = 1; i <= Arr[0].second; ++i) {
		now *= Arr[0].first;
		qu.push(make_pair(now, 0));
	}
	while (!qu.empty()) {
		pair <LL, int> u = qu.front();
		qu.pop();
		if (u.second == (int)Arr.size() - 1) {
			fact.push_back(u.first);
			continue;
		}
		LL now = u.first;
		int cnt = u.second;
		qu.push(make_pair(now, cnt + 1));
		for (int i = 1; i <= Arr[cnt+ 1].second; ++i) {
			now *= Arr[cnt + 1].first;
			qu.push(make_pair(now, cnt + 1));
		}
	}
}

int main() {
	int t, icase = 1;
	getprime();
	scanf("%d", &t);
	while (t--) {
		LL a, b;
		scanf("%lld%lld", &a, &b);
		if (a == 1) {
			printf("Case %d: 0\n", icase++);
			continue;
		}
		Arr.clear();
		fact.clear();
		LL tmp = a;
		for (int i = 1; (LL)prime[i] * prime[i] <= tmp && i <= tot; ++i) {
			if (tmp % prime[i] == 0) {
				int cnt = 0;
				while (tmp % prime[i] == 0) {
					tmp /= prime[i];
					++cnt;
				}
				Arr.push_back(make_pair(prime[i], cnt));
			}
		}
		if (tmp > 1) {
			Arr.push_back(make_pair(tmp, 1));
		}
		bfs();
		int size = fact.size();
		sort(fact.begin(), fact.end());
		int ans = 0;
		for (int i = 0; i < size; ++i) {
			if (fact[i] >= b && a / fact[i] >= b) {
				++ans;
			}
		}
		printf("Case %d: %d\n", icase++, ans / 2);
	}
	return 0;
}
