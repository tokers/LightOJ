#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int M;
class Matrix {
	public:
		int mat[6][6];
		Matrix();
		Matrix operator * (const Matrix &b) const;
		Matrix& operator = (const Matrix &b);
};

Matrix :: Matrix() {
	memset(mat, 0, sizeof(mat));
}

Matrix Matrix :: operator * (const Matrix &b) const {
	Matrix ret;
	for (int i = 0; i < 6; ++i){
		for (int j = 0; j < 6; ++j) {
			for (int k = 0; k < 6; ++k) {
				ret.mat[i][j] += this -> mat[i][k] * b.mat[k][j] % M;
				ret.mat[i][j] %= M;
			}
		}
	}
	return ret;
}

Matrix& Matrix :: operator = (const Matrix &b) {
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			this -> mat[i][j] = b.mat[i][j];
		}
	}
	return *this;
}

Matrix fastpow(Matrix A, int cnt) {
	Matrix ret;
	for (int i = 0; i < 6; ++i) {
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

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int a1, b1, c1, a2, b2, c2, f0, f1, f2, g0, g1, g2, q;
		scanf("%d%d%d", &a1, &b1, &c1);
		scanf("%d%d%d", &a2, &b2, &c2);
		scanf("%d%d%d", &f0,&f1, &f2);
		scanf("%d%d%d", &g0, &g1, &g2);
		scanf("%d%d", &M, &q);
		a1 %= M, b1 %= M, c1 %= M, a2 %= M, b2 %= M, c2 %= M;
		f0 %= M, f1 %= M, f2 %= M, g0 %= M, g1 %= M, g2 %= M;
		Matrix A;
		A.mat[0][0] = a1, A.mat[1][0] = b1, A.mat[5][0] = c1;
		A.mat[0][1] = 1;
		A.mat[1][2] = 1;
		A.mat[2][3] = c2, A.mat[3][3] = a2, A.mat[4][3] = b2;
		A.mat[3][4] = 1;
		A.mat[4][5] = 1;
		printf("Case %d:\n", icase++);
		while (q--) {
			int n;
			scanf("%d", &n);
			if (n == 0) {
				printf("%d %d\n", f0, g0);
			}
			else if (n == 1) {
				printf("%d %d\n", f1, g1);
			}
			else if (n == 2) {
				printf("%d %d\n", f2, g2);
			}
			else {
				Matrix ret;
				ret.mat[0][0] = f2, ret.mat[0][1] = f1, ret.mat[0][2] = f0;
				ret.mat[0][3] = g2, ret.mat[0][4] = g1, ret.mat[0][5] = g0;
				ret = ret * fastpow(A, n - 2);
				printf("%d %d\n", ret.mat[0][0], ret.mat[0][3]);
			}
		}
	}
	return 0;
}



