/*************************************************************************
> File Name: LightOJ1006.cpp
> Author: ALex
> Mail: zchao1995@gmail.com
> Created Time: 2015年06月03日 星期三 21时17分35秒
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

static const int mod = 10000007;

class MARTIX {
public:
    LL mat[6][6];
    MARTIX();
    MARTIX operator * (const MARTIX &ret)const;
    MARTIX& operator = (const MARTIX &ret);
};

MARTIX :: MARTIX() {
memset(mat, 0, sizeof(mat));
}

MARTIX MARTIX :: operator * (const MARTIX &ret) const {
MARTIX ans;
for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 6; ++j) {
        for (int k = 0; k < 6; ++k) {
            ans.mat[i][j] += this-> mat[i][k] * ret.mat[k][j];
            ans.mat[i][j] %= mod;
        }
    }
}
return ans;
}

MARTIX& MARTIX :: operator = (const MARTIX &ret) {
for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 6; ++j) {
        this -> mat[i][j] = ret.mat[i][j];
    }
}
return *this;
}

MARTIX fastpow(MARTIX A, int cnt) {
MARTIX ans;
for (int i = 0; i < 6; ++i) {
    ans.mat[i][i] = 1;
}
while (cnt) {
    if (cnt & 1) {
        ans = ans * A;
    }
    cnt >>= 1;
    A = A * A;
}
return ans;
}

LL f[10];

int main() {
int t, icase = 1;
MARTIX Base;
for (int i = 0; i < 6; ++i) {
    Base.mat[i][0] = 1;
}
for (int i = 1; i < 6; ++i) {
    Base.mat[i - 1][i] = 1;
}
scanf("%d", &t);
while (t--) {
    int n;
    for (int i = 0; i < 6; ++i) {
        scanf("%lld", &f[i]);
        f[i] %= mod;
    }
    scanf("%d", &n);
    if (n <= 5) {
        printf("Case %d: %lld\n", icase++, f[n]);
        continue;
    }
    MARTIX ret;
    for (int i = 0; i < 6; ++i) {
        ret.mat[0][i] = f[5 - i];
    }
    MARTIX B = fastpow(Base, n - 5);
    B = ret * B;
    printf("Case %d: %lld\n", icase++, B.mat[0][0]);
}
return 0;
}
