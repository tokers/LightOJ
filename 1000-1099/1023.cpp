/*************************************************************************
    > File Name: LightOJ1023.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月10日 星期三 12时33分22秒
 ************************************************************************/

#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <set>
#include <vector>

using namespace std;

const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef pair <int, int> PLL;

vector <int> arr;

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		arr.clear();
		for (int i = 0; i < n; ++i) {
			arr.push_back(i);
		}
		int cnt = 0;
		printf("Case %d:\n", icase++);
		do {
			for (int i = 0; i < n; ++i) {
				printf("%c", arr[i] + 'A');
			}
			printf("\n");
			++cnt;
			if (cnt == k) {
				break;
			}
		}while (next_permutation(arr.begin(), arr.end()));
	}
	return 0;
}
