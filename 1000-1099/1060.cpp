/*************************************************************************
    > File Name: LightOJ1060.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月03日 星期五 18时10分19秒
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

vector <PLL> arr;
int num[30];
char str[30];
char ans[30];
LL C[30][30];

void init() {
	C[0][0] = 1;
	for (int i = 1; i <= 27; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i - 1; ++j) {
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
		C[i][i] = 1;
	}
}

int main() {
	init();
	int t, icase = 1, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%s%d", str, &n);
		memset(num, 0, sizeof(num));
		arr.clear();
		int len = strlen(str);
		for (int i = 0; i < len; ++i) {
			++num[str[i] - 'a'];
		}
		for (int i = 0; i < 26; ++i) {
			if (num[i]) {
				arr.push_back(make_pair(i, num[i]));
			}
		}
		int size = arr.size();
		bool flag;
		for (int i = 0; i < len; ++i) {
			flag = 0;
			for (int j = 0; j < size; ++j) {
				if (arr[j].second == 0) {
					continue;
				}
				int rest = len - i - 1;
				LL tot = 1;
				for (int k = 0; k < size; ++k) {
					if (k != j) {
						tot *= C[rest][arr[k].second];
						rest -= arr[k].second;
					}
					else {
						tot *= C[rest][arr[j].second - 1];
						rest -= (arr[j].second - 1);
					}
				}
				if (tot >= n) {
					ans[i] = arr[j].first + 'a';
					--arr[j].second;
					flag = 1;
					break;
				}
				else {
					n -= tot;
				}
			}
			if (!flag) {
				break;
			}
		}
		ans[len] = '\0';
		if (!flag) {
			strcpy(ans, "Impossible");
		}
		printf("Case %d: %s\n", icase++, ans);
	}
	return 0;
}
