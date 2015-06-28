/*************************************************************************
    > File Name: LightOJ1070.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年06月28日 星期日 21时55分34秒
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
 
class MARTIX
{
    public:
        ULL mat[3][3];
        MARTIX();
        MARTIX operator * (const MARTIX &b)const;
        MARTIX operator + (const MARTIX &b)const;
        MARTIX& operator = (const MARTIX &b);
};
 
MARTIX :: MARTIX()
{
    memset (mat, 0, sizeof(mat));
}
 
MARTIX MARTIX :: operator * (const MARTIX &b)const
{
    MARTIX ret;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                ret.mat[i][j] += this -> mat[i][k] * b.mat[k][j];
            }
        }
    }
    return ret;
}
 
MARTIX MARTIX :: operator + (const MARTIX &b)const
{
    MARTIX ret;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            ret.mat[i][j] = this -> mat[i][j] + b.mat[i][j];
        }
    }
    return ret;
}
 
MARTIX& MARTIX :: operator = (const MARTIX &b)
{
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            this -> mat[i][j] = b.mat[i][j];
        }
    }
    return *this;
}
 
MARTIX fastpow(MARTIX A, int cnt) {
    MARTIX ret;
    ret.mat[0][0] = ret.mat[1][1] = 1;
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
        ULL p, q;
        int n;
        scanf("%llu%llu%d", &p, &q, &n);
        ULL ans;
        if (n == 1) {
            ans = p;
        }
        else if (n == 0) {
            ans = 2;
        }
        else if (n == 2) {
            ans = p * p - 2 * q;
        }
        else {
            MARTIX A;
            A.mat[0][0] = p;
            A.mat[0][1] = 1;
            A.mat[1][0] = -q;
            MARTIX ret = fastpow(A, n - 2);
            MARTIX B;
            B.mat[0][0] = p * p - 2 * q;
            B.mat[0][1] = B.mat[1][0] = p;
            B.mat[1][1] = 2;
            ret = B * ret;
            ans = ret.mat[0][0];
        }
        printf("Case %d: %llu\n", icase++, ans);
    }
    return 0;
}
