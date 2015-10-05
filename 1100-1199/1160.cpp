/*************************************************************************
    > File Name: LightOJ1160.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年10月05日 星期一 16时33分27秒
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

const int mod = 1e9 + 7;
int inv;

class Matrix {
	public:
		int mat[40][40];	
		Matrix();
		Matrix operator * (const Matrix &b)const;
		Matrix& operator = (const Matrix &b);
}AA;

Matrix :: Matrix() {
	memset(mat, 0, sizeof(mat));
}

Matrix Matrix :: operator * (const Matrix &b)const {
	Matrix ret;
	for (int i = 0; i < 35; ++i) {
		for (int j = 0; j < 35; ++j) {
			for (int k = 0; k < 35; ++k) {
				ret.mat[i][j] += (LL)this -> mat[i][k] * b.mat[k][j] % mod;
				if (ret.mat[i][j] >= mod) {
					ret.mat[i][j] -= mod;
				}
			}
		}
	}
	return ret;
}

Matrix& Matrix :: operator = (const Matrix &b) {
	for (int i = 0; i < 35; ++i) {
		for (int j = 0; j < 35; ++j) {
			this -> mat[i][j] = b.mat[i][j];
		}
	}
	return *this;
}

Matrix fastpow(Matrix A, int cnt) {
	Matrix ret;
	for (int i = 0; i < 35; ++i) {
		ret.mat[i][i] = 1;
	}
	while (cnt) {
		if (cnt & 1) {
			ret = ret * A;
		}
		cnt >>= 1;
		A = A * A;
	}
	return ret;
}

map <int, int> mp;
int dir[4];

int main() {
	mp.clear();
	int x = 0;
	for (int i = 1; i < 128; ++i) {
		int cnt = 0;
		for (int j = 0; j < 7; ++j) {
			if (i & (1 << j)) {
				++cnt;
			}
		}
		if (cnt == 4) {
			mp[i] = x++;
		}
	}
	for (int i = 1; i < 128; ++i) {
		int cnt = 0;
		for (int j = 0; j < 7; ++j) {
			if (i & (1 << j)) {
				++cnt;
			}
		}
		if (cnt != 4) {
			continue;
		}
		for (int j = 0; j < 16; ++j) {
			int sta = 0, now = 0;
			bool flag = 1;
			int x = j;
			dir[3] = x % 2; x /= 2;
			dir[2] = x % 2; x /= 2;
			dir[1] = x % 2; x /= 2;
			dir[0] = x;
			for (int k = 0; k < 7; ++k) {
				if (i & (1 << k)) {
					if (dir[now] && k - 1 < 0) {
						flag = 0;
						break;
					}
					if (dir[now] == 0 && k + 1 >= 7) {
						flag = 0;
						break;
					}
					if (dir[now] == 0 && (sta & (1 << (k + 1)))) {
						flag = 0;
						break;
					}
					if (dir[now] && (sta & (1 << (k - 1)))) {
						flag = 0;
					}
					if (dir[now]) {
						sta |= (1 << (k - 1));
					}
					else {
						sta |= (1 << (k + 1));
					}
					++now;
				}
			}
			if (flag) {
				AA.mat[mp[i]][mp[sta]] = 1;
			}
		}
	}
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int sta = 0, x, n;
		scanf("%d", &n);
		for (int i = 0; i < 7; ++i) {
			scanf("%d", &x);
			if (x) {
				sta |= (1 << (7 - i - 1));
			}
		}
		Matrix ret = fastpow(AA, n - 1);
		int ans = 0;
		for (int i = 0; i < 35; ++i) {
			ans += ret.mat[mp[sta]][i];
			ans %= mod;
		}
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}
