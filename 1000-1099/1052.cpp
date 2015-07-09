/*************************************************************************
    > File Name: LightOJ1052.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月08日 星期三 22时11分41秒
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

const int mod = 1000000007;

class MARTIX
{
    public:
        LL mat[3][3];
        MARTIX();
        MARTIX operator * (const MARTIX &b)const;
        MARTIX operator + (const MARTIX &b)const;
        MARTIX& operator = (const MARTIX &b);
}A, E, D;

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
                ret.mat[i][j] %= mod;
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
            ret.mat[i][j] %= mod;
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
		int n, x, m, y, k;
		scanf("%d%d%d%d%d", &n, &x, &m, &y, &k);
		MARTIX A;
		A.mat[0][0] = A.mat[0][1] = A.mat[1][0] = 1;
		int fx1, fx2, fy1, fy2;
		if (n == 1) {
			fx1 = 1;
			fx2 = 1;
		}
		else {
			MARTIX T = fastpow(A, n - 1);
			fx1 = T.mat[0][0];
			T = fastpow(A, n);
			fx2 = T.mat[0][0];
		} 
		if (m == 1) {
			fy1 = 1;
			fy2 = 1;
		}
		else {
			MARTIX T = fastpow(A, m - 1);
			fy1 = T.mat[0][0];
			T = fastpow(A, m);
			fy2 = T.mat[0][0];
		}
		if ((LL)fx1 * fy2 == (LL)fx2 * fy1) {
			printf("Case %d: Impossible\n", icase++);
		}
		else {
			int ykb = (LL)fx1 * fy2 - (LL)fx2 * fy1;
			LL ans1 = (LL)x * fy2 - (LL)y * fx2;
			if (ans1 % ykb || (ykb > 0 && ans1 < 0) || (ykb < 0 && ans1 > 0)) {
				printf("Case %d: Impossible\n", icase++);
				continue;
			}
			ans1 /= ykb;
			LL ans2 = (LL)fx1 * y - (LL)fy1 * x;
			if (ans2 % ykb || (ykb > 0 && ans2 < 0) || (ykb < 0 && ans2 > 0)) {
				printf("Case %d: Impossible\n", icase++);
				continue;
			}
			ans2 /= ykb;
			int fk1, fk2;
			if (k == 1) {
				fk1 = fk2 = 1;
			}
			else {
				MARTIX T = fastpow(A, k - 1);
				fk1 = T.mat[0][0];
				T = fastpow(A, k);
				fk2 = T.mat[0][0];
			}
			int ans = ((LL)fk1 * ans1 + (LL)fk2 * ans2) % mod;
			printf("Case %d: %d\n", icase++, ans);
		}
	}
	return 0;
}
