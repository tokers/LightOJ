/*************************************************************************
  > File Name: LightOJ1007.cpp
  > Author: ALex
  > Mail: zchao1995@gmail.com 
  > Created Time: 2015年06月04日 星期四 17时41分21秒
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

static const int N = 5000010;
int phi[N];
unsigned long long Arr[N];

void getphi() {
for (int i = 1; i <= 5000000; ++i) {
	Arr[i] = i;
}
for (int i = 2; i <= 5000000; ++i) {
	if (Arr[i] == i) {
		if (5000000 / i < i) {
			break;
		}
		for (int j = i * i; j <= 5000000; j += i) {
			Arr[j] = i;
		}
	}
}
phi[1] = 1;
for (int i = 2; i <= 5000000; ++i) {
	phi[i] = phi[i / Arr[i]];
	if ((i / Arr[i]) % Arr[i]) {
		phi[i] *= (Arr[i] - 1);
	}
	else {
		phi[i] *= Arr[i];
	}
}
}

int main() {
getphi();
int t, icase = 1;
Arr[0] = 0;
for (int i = 1; i <= 5000000; ++i) {
	Arr[i] = Arr[i - 1] + (unsigned long long)phi[i] * phi[i];
}
scanf("%d", &t);
while (t--) {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("Case %d: %llu\n", icase++, Arr[b] - Arr[a - 1]); 
}
return 0;
}
