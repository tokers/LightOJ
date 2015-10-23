/*************************************************************************
    > File Name: LightOJ1349.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015/10/23 14:11:28
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

const int N = 50010;
LL sumy[N];
LL sumx[N];
LL costx[N];
LL costy[N];

int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m, q;
        scanf("%d%d%d", &n, &m, &q);
        memset(sumx, 0, sizeof(sumx));
        memset(sumy, 0, sizeof(sumy));
        memset(costx, 0, sizeof(costx));
        memset(costy, 0, sizeof(costy));
        int x, y, w;
        LL all = 0;
        for (int i = 1; i <= q; ++i) {
            scanf("%d%d%d", &x, &y, &w);
            costx[x] += (LL)w * x;
            costy[y] += (LL)w * y;
            sumx[x] += w;
            sumy[y] += w;
            all += w;
        }
        for (int i = 1; i <= n; ++i) {
            costx[i] += costx[i - 1]; 
            sumx[i] += sumx[i - 1];
        }
        for (int i = 1; i <= m; ++i) {
            costy[i] += costy[i - 1];
            sumy[i] += sumy[i - 1];
        }
        int ansx, ansy;
        LL answ = INF;
        for (int i = 1; i <= n; ++i) {
            LL now = sumx[i - 1] * i - costx[i - 1];
            now += costx[n] - costx[i] - (sumx[n] - sumx[i]) * i;
            if (now < answ) {
                answ = now;
                ansx = i;
            }
        }
        answ = INF;
        for (int i = 1; i <= m; ++i) {
            LL now = sumy[i - 1] * i - costy[i - 1];
            now += costy[m] - costy[i] - (sumy[m] - sumy[i]) * i;
            if (now < answ) {
                answ = now;
                ansy = i;
            }
        }
        printf("Case %d: %d %d\n", icase++, ansx, ansy);
    }
    return 0;
}
