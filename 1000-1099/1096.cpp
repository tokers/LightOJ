/*************************************************************************
    > File Name: LightOJ1096.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月02日 星期四 18时37分04秒
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

const int mod = 10007;

class MATRIX {
	public:
		int mat[6][6];
		MATRIX();
		MATRIX operator * (const MATRIX &b) const;
		MATRIX& operator = (const MATRIX &b);
};

MATRIX :: MATRIX() {
	memset(mat, 0, sizeof(mat));
}

MATRIX MATRIX :: operator * (const MATRIX &b) const {
	MATRIX ret;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			for (int k = 0; k < 6; ++k) {
				ret.mat[i][j] += this -> mat[i][k] * b.mat[k][j];
				ret.mat[i][j] %= mod;
			}
		}
	}
	return ret;
}

MATRIX& MATRIX :: operator = (const MATRIX &b) {
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			this -> mat[i][j] = b.mat[i][j];
		}
	}
	return *this;
}

MATRIX fastpow(MATRIX A, int n) {
	MATRIX ret;
	for (int i = 0; i < 6; ++i) {
		ret.mat[i][i] = 1;
	}
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
		int n, a, b, c;
		scanf("%d%d%d%d", &n, &a, &b, &c);
		int f0 = 0, f1 = 0, f2 = 0, f3 = c, f4 = (a * c + c) % mod;
		int ans = 0;
		if (n <= 2) {
			ans = 0;
		}
		else if (n == 3) {
			ans = f3;
		}
		else if (n == 4) {
			ans = f4;
		}
		else {
			MATRIX A;
			A.mat[0][0] = A.mat[1][1] = a;
			A.mat[2][0] = A.mat[3][1] = b;
			A.mat[1][2] = A.mat[2][3] = A.mat[3][4] = A.mat[5][5] = 1;
			A.mat[5][0] = A.mat[5][1] = c;
			/** 
			for (int i = 0; i < 6; ++i) {
				for (int j = 0; j < 6; ++j) {
					printf("%d ", A.mat[i][j]);
				}
				printf("\n");
			 }
			*/
			MATRIX res = fastpow(A, n - 4);
			MATRIX tmp;
			tmp.mat[0][0] = f4;
			tmp.mat[0][1] = f3;
			tmp.mat[0][5] = 1;
			res = tmp * res;
			ans = res.mat[0][0];
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
