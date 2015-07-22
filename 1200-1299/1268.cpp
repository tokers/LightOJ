/*************************************************************************
    > File Name: LightOJ1268.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年07月22日 星期三 13时52分55秒
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
 
class MATRIX {
    public:
        int n;
        unsigned int mat[55][55];
        MATRIX(int size);
        MATRIX operator * (const MATRIX &b) const;
        MATRIX& operator = (const MATRIX &b);
};
 
MATRIX :: MATRIX(int size) {
    memset(mat, 0, sizeof(mat));
    n = size;
}
 
MATRIX MATRIX :: operator * (const MATRIX &b) const {
    MATRIX ret(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                ret.mat[i][j] += mat[i][k] * b.mat[k][j];
            }
        }
    }
    return ret;
}
 
MATRIX& MATRIX :: operator = (const MATRIX &b) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            this -> mat[i][j] = b.mat[i][j];
        }
    }
    return *this;
}
 
MATRIX fastpow(MATRIX b, int cnt) {
    MATRIX ret(b.n);
    for (int i = 0; i < ret.n; ++i) {
        ret.mat[i][i] = 1;
    }
    while (cnt) {
        if (cnt & 1) {
            ret = ret * b;
        }
        cnt >>= 1;
        b = b * b;
    }
    return ret;
}
 
string usechar;
string str;
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n;
        unsigned int ans = 0;
        cin >> n >> usechar >> str;
        int k = str.length();
        int size = usechar.length();
        if (n <= k) {
            ans = 1;
            for (int i = 1; i <= n; ++i) {
                ans *= size;
            }
            if (n == k) {
                --ans;
            }
        }
        else {
            MATRIX b(k);
            for (int i = 0; i < k; ++i) { // 前缀长度
                for (int j = 0; j < size; ++j) {
                    string tmp = str.substr(0, i) + usechar[j];
                    while (tmp != str.substr(0, tmp.length())) {
                        tmp = tmp.substr(1);
                    }
                    int l = tmp.length();
                    if (l != k) {
                        ++b.mat[i][l];
                    }
                }
            }
            MATRIX ret = fastpow(b, n);
            for (int i = 0; i < k; ++i) {
                ans += ret.mat[0][i];
            }
        }
        printf("Case %d: %u\n", icase++, ans);
    }
    return 0;
}
