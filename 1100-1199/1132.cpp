/*************************************************************************
    > File Name: LightOJ1132.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015/10/23 16:26:46
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

int size;
class Matrix {
    public:
        unsigned int mat[55][55];
        Matrix();
        Matrix operator * (const Matrix &b) const;
        Matrix& operator = (const Matrix &b);
};

Matrix :: Matrix() {
    memset(mat, 0, sizeof(mat));
}

Matrix Matrix :: operator * (const Matrix &b) const {
    Matrix ret;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                ret.mat[i][j] += this -> mat[i][k] * b.mat[k][j];
            }
        }
    }
    return ret;
}

Matrix& Matrix :: operator = (const Matrix &b) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            this -> mat[i][j] = b.mat[i][j];
        }
    }
    return *this;
}

unsigned int C[55][55];

Matrix fastpow(Matrix A, LL cnt) {
    Matrix ret;
    for (int i = 0; i < size; ++i) {
        ret.mat[i][i] = 1;
    }
    while (cnt) {
        if (cnt & 1) {
            ret = ret * A;
        }
        A = A * A;
        cnt >>= 1;
    }
    return ret;
}

int main() {
    C[0][0] = 1;
    for (int i = 1; i <= 50; ++i) {
        C[i][0] = 1;
        C[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        LL n;
        scanf("%lld%d", &n, &size);
        int k = size;
        size += 2;
        Matrix A;
        for (int i = 0; i < size; ++i) {
            A.mat[i][i] = 1;
        }
        for (int i = 1; i < size; ++i) {
            A.mat[0][i] = C[k][k - i + 1];
        }
        for (int i = 1; i < size; ++i) {
            int now = k - i + 1;
            for (int j = i; j < size; ++j) {
                A.mat[i][j] = C[k - i + 1][now--];
            }
        }
        A = fastpow(A, n - 1);
        Matrix B;
        B.mat[0][0] = 1;
        for (int i = 1; i < size; ++i) {
            B.mat[i][0] = 1;
        }
        B = A * B;
        printf("Case %d: %u\n", icase++, B.mat[0][0]);
    }
    return 0;
}
