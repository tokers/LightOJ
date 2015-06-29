/*************************************************************************
    > File Name: LightOJ1093.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月29日 星期一 21时49分03秒
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
int Arr[N];
PLL qu[N];
vector <int> MAX, MIN;

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, d, tail = -1, head = 0;
		scanf("%d%d", &n, &d);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &Arr[i]);
		}
		//get MAX
		for (int i = 1; i <= d; ++i) {
			while (tail >= head && qu[tail].first < Arr[i]) {
				--tail;
			}
			qu[++tail] = make_pair(Arr[i], i);
		}
		MAX.clear();
		MIN.clear();
		MAX.push_back(qu[head].first);
		for (int i = d + 1; i <= n; ++i) {
			while (tail >= head && qu[head].second < i - d + 1) {
				++head;
			}
			while (tail >= head && qu[tail].first < Arr[i]) {
				--tail;
			}
			qu[++tail] = make_pair(Arr[i], i);
			MAX.push_back(qu[head].first);
		}
		tail = -1, head = 0;
		for (int i = 1; i <= d; ++i) {
			while (tail >= head && qu[tail].first > Arr[i]) {
				--tail;
			}
			qu[++tail] = make_pair(Arr[i], i);
		}
		MIN.push_back(qu[head].first);
		for (int i = d + 1; i <= n; ++i) {
			while (tail >= head && qu[head].second < i - d + 1) {
				++head;
			}
			while (tail >= head && qu[tail].first > Arr[i]) {
				--tail;
			}
			qu[++tail] = make_pair(Arr[i], i);
			MIN.push_back(qu[head].first);
		}
		int ans = 0;
		for (int i = 0; i < n - d + 1; ++i) {
			ans = max(ans, MAX[i] - MIN[i]);
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
