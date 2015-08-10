/*************************************************************************
    > File Name: LightOJ1339.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年08月10日 星期一 14时30分52秒
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
 
const int N = 100010;
int LOG[N];
int col[N]; // i th colors's length
int cnt;
int Arr[N];
int dp[N][20];
int L[N];
int R[N];
int P[N];
 
void initRMQ(int n) {
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = col[i];
    }
    for (int j = 1; j <= LOG[n]; ++j) {
        for (int i = 1; i <= n; ++i) {
            dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
}
 
int ST(int l, int r) {
    int k = LOG[r - l + 1];
    return max(dp[l][k], dp[r - (1 << k) + 1][k]);
}
 
int main() {
    LOG[0] = -1;
    for (int i = 1; i <= 100000; ++i) {
        LOG[i] = (i & (i - 1)) ? LOG[i - 1] : LOG[i - 1] + 1;
    }
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n, c, m;
        scanf("%d%d%d", &n, &c, &m);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &Arr[i]);
        }
        cnt = 1;
        int now = Arr[1], len = 1;
        Arr[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (Arr[i] == now) {
                Arr[i] = cnt;
                ++len;
            }
            else {
                col[cnt] = len;
                now = Arr[i];
                len = 1;
                Arr[i] = ++cnt;
            }
        }
        col[cnt] = len;
        initRMQ(cnt);
        for (int i = 1; i <= n; ++i) {
            P[i] = Arr[i];
            if (i == 1) {
                L[i] = 1;
            }
            else {
                if (Arr[i] == Arr[i - 1]) {
                    L[i] = L[i - 1];
                }
                else {
                    L[i] = i;
                }
            }
        }
        for (int i = n; i >= 1; --i) {
            if (i == n) {
                R[i] = n;
            }
            else {
                if (Arr[i] == Arr[i + 1]) {
                    R[i] = R[i + 1];
                }
                else {
                    R[i] = i;
                }
            }
        }
        int l, r;
        printf("Case %d:\n", icase++);
        while (m--) {
            scanf("%d%d", &l, &r);
            if (P[l] == P[r]) {
                printf("%d\n", r - l + 1);
            }
            else {
                int m1 = R[l] - l + 1;
                m1 = max(m1, r - L[r] + 1);
                if (P[l] + 1 <= P[r] - 1) {
                    m1 = max(m1, ST(P[l] + 1, P[r] - 1));
                }
                printf("%d\n", m1);
            }
        }
    }
    return 0;
}
