/*************************************************************************
    > File Name: LightOJ1396.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月31日 星期五 14时56分21秒
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

char str[100010];

void solve1() {
	int len = strlen(str);
	int mid = len / 2;
	bool flag = 0;
	int id;
	for (int i = mid + 1; i < len; ++i) {
		if (str[i] == str[len - i - 1]) {
			continue;
		}
		if (str[i] < str[len - i - 1]) {
			flag = 1;
			id = i;
			break;
		}
		break;
	}
	if (flag) {
		str[id] = str[len - id - 1];
		for (int i = id + 1; i < len; ++i) {
			str[i] = str[len - i - 1];
		}
	}
	else {
		if (str[mid] != '9') {
			++str[mid];
			for (int i = mid + 1; i < len; ++i) {
				str[i] = str[len - i - 1];
			}
		}
		else {
			for (int i = mid - 1; i >= 0; --i) {
				if (str[i] != '9') {
					++str[i];
					for (int j = i + 1; j <= mid; ++j) {
						str[j] = '0';
					}
					break;
				}
			}
			for (int i = mid + 1; i < len; ++i) {
				str[i] = str[len - i - 1];
			}
		}
	}
	printf("%s\n", str);
}

void solve2() {
	bool flag = 0;
	int id;
	int len = strlen(str);
	int mid = len / 2;
	for (int i = mid; i < len; ++i) {
		if (str[i] < str[len - i - 1]) {
			flag = 1;
			id = i;
			break;
		}
		if (str[i] > str[len - i - 1]) {
			break;
		}
	}
	if (flag) {
		str[id] = str[len - id - 1];
		for (int i = id + 1; i < len; ++i) {
			str[i] = str[len - i - 1];
		}
	}
	else {
		if (str[mid - 1] != '9') {
			++str[mid - 1];
			for (int i = mid; i < len; ++i) {
				str[i] = str[len - i - 1];
			}
		}
		else {
			for (int i = mid - 2; i >= 0; --i) {
				if (str[i] != '9') {
					++str[i];
					for (int j = i + 1; j < mid; ++j) {
						str[j] = '0';
					}
					break;
				}
			}
			for (int i = mid; i < len; ++i) {
				str[i] = str[len - i - 1];
			}
		}
	}
	printf("%s\n", str);
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", str);
		printf("Case %d: ", icase++);
		int len = strlen(str);
		bool flag = 1;
		for (int i = 0; i < len; ++i) {
			if (str[i] != '9') {
				flag = 0;
				break;
			}
		}
		if (flag) {
			printf("1");
			for (int i = 0; i < len - 1; ++i) {
				printf("0");
			}
			printf("1\n");
			continue;
		}
		if (len & 1) {
			solve1();
		}
		else {
			solve2();
		}
	}
	return 0;
}
