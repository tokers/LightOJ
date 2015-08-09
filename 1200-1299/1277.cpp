/*************************************************************************
    > File Name: LightOJ1277.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年08月09日 星期日 14时50分11秒
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
int LIS[N];
int d[N];
int Arr[N];
vector <int> ord;

int Search(int val, int tot) {
	int l = 1, r = tot, mid, id;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (d[mid] <= val) {
			id = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return id;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, q, m;
		scanf("%d%d", &n, &q);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &Arr[i]);
		}
		int tot = 1;
		d[1] = Arr[n];
		LIS[n] = 1;
		for (int i = n - 1; i >= 1; --i) {
			if (d[tot] > Arr[i]) {
				d[++tot] = Arr[i];
				LIS[i] = tot;
			}
			else {
				int p = Search(Arr[i], tot);
				d[p] = Arr[i];
				LIS[i] = p;
			}
		}
		printf("Case %d:\n", icase++);
		while (q--) {
			scanf("%d", &m);
			ord.clear();
			int val = -inf;
			for (int i = 1; i <= n; ++i) {
				if (LIS[i] >= m && Arr[i] > val) {
					val = Arr[i];
					--m;
					ord.push_back(Arr[i]);
				}
				if (m == 0) {
					break;
				}
			}
			if (m > 0) {
				printf("Impossible\n");
				continue;
			}
			int size = ord.size();
			for (int i = 0; i < size; ++i) {
				printf("%d", ord[i]);
				if (i < size - 1) {
					printf(" ");
				}
				else {
					printf("\n");
				}
			}
		}
	}
	return 0;
}
