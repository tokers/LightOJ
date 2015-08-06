/*************************************************************************
    > File Name: LightOJ1187.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月05日 星期三 19时50分45秒
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

const int N = 100100;
int tree[N];
int n;

int lowbit(int x) {
	return x & (-x);
}

void add(int x) {
	for (int i = x; i <= n; i += lowbit(i)) {
		++tree[i];
	}
}

int sum(int x) {
	int ans = 0;
	for (int i = x; i; i -= lowbit(i)) {
		ans += tree[i];
	}
	return ans;
}

int arr[N];
bool vis[N];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &arr[i]);
		}
		memset(vis, 0, sizeof(vis));
		memset(tree, 0, sizeof(tree));
		for (int i = n; i >= 2; --i) {
			int l = 1, r = n - arr[i], mid, id;
			r -= (sum(n) - sum(r - 1));
			while (l <= r) {
				mid = (l + r) >> 1;
				int num = n - mid - sum(n) + sum(mid - 1);
				if (num >= arr[i]) {
					l = mid + 1;
					id = mid;
				}
				else {
					r = mid - 1;
				}
			}
			add(id);
			vis[id] = 1;
		}
		for (int i = 1; i <= n; ++i) {
			if (!vis[i]) {
				printf("Case %d: %d\n", icase++, i);
				break;
			}
		}
	}
	return 0;
}
