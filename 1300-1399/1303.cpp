/*************************************************************************
    > File Name: LightOJ1303.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年10月09日 星期五 20时09分45秒
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

queue <int> qu;
int seat[30];
int mask[30];
queue <int> q[2];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		memset(mask, 0, sizeof(mask));
		while (!qu.empty()) {
			qu.pop();
		}
		for (int i = 0; i < 2; ++i) {
			while (!q[i].empty()) {
				q[i].pop(); // 等待队列
			}
		}
		for (int i = 1; i <= m; ++i) {
			qu.push(i); // 座位队列
			seat[i] = -1;
		}
		int cnt = 0;
		bool flag = 0;
		for (int i = 1; i <= n; ++i) {
			q[flag].push(i);
		}
		int ans = 0;
		while (1) {
			bool x = 1;
			for (int i = 1; i <= n; ++i) {
				if (mask[i] != ((1 << m) - 1)) {
					x = 0;
					break;
				}
			}
			if (x && cnt == 0) {
				break;
			}
			ans += 5;
			int seatid = qu.front();
			qu.pop();
			int man = seat[seatid];
			int id = -1;
			if (man != -1) {
				--cnt;
			}
			while (!q[flag].empty()) {
				int p = q[flag].front();
				q[flag].pop();
				if (id == -1 && !(mask[p] & (1 << (seatid - 1)))) {
					id = p;
				}
				else {
					q[flag ^ 1].push(p);
				}
			}
			if (id != -1) {
				++cnt;
				seat[seatid] = id;
				mask[id] |= (1 << (seatid - 1));
			}
			else {
				seat[seatid] = -1;
			}
			qu.push(seatid);
			if (man != -1) {
				if (mask[man] != ((1 << m) - 1)) {
					q[flag ^ 1].push(man);
				}
			}
			flag ^= 1;
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
