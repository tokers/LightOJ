/*************************************************************************
    > File Name: LightOJ1065.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月02日 星期四 19时48分04秒
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

int mod;

class MATRIX {
	public:
		int mat[2][2];
		MATRIX();
		MATRIX operator * (const MATRIX& b) const;
		MATRIX& operator = (const MATRIX& b);
};

MATRIX :: MATRIX() {
	memset(mat, 0, sizeof(mat));
}

MATRIX MATRIX :: operator * (const MATRIX& b) const {
	MATRIX ret;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				ret.mat[i][j] += this -> mat[i][k] * b.mat[k][j];
				ret.mat[i][j] %= mod;
			}
		}
	}
	return ret;
}

MATRIX& MATRIX :: operator = (const MATRIX& b) {
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			this -> mat[i][j] = b.mat[i][j];
		}
	}
	return *this;
}

MATRIX fastpow(MATRIX A, int n) {
	MATRIX ret;
	ret.mat[0][0] = ret.mat[1][1] = 1;
	while (n) {
		if (n & 1) {
			ret = ret * A;
		}
		A = A * A;
		n >>= 1;
	}
	return ret;
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int a, b, n, m;
		mod = 1;
		scanf("%d%d%d%d", &a, &b, &n, &m);
		for (int i = 1; i <= m; ++i) {
			mod *= 10;
		}
		MATRIX A; 
		A.mat[0][0] = A.mat[0][1] = A.mat[1][0] = 1;
		int ans;
		if (n == 0) {
			ans = a % mod;
		}
		else if (n == 1) {
			ans = b % mod;
		}
		else if (n == 2) {
			ans = (a + b) % mod;
		}
		else {
			MATRIX ret = fastpow(A, n - 2);
			MATRIX tmp;
			tmp.mat[0][0] = (a + b) % mod;
			tmp.mat[0][1] = tmp.mat[1][0] = b % mod;
			tmp.mat[1][1] = a % mod;
			ret = tmp * ret;
			ans = ret.mat[0][0];
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
