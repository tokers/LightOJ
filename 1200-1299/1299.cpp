/*************************************************************************
    > File Name: LightOJ1299.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年09月28日 星期一 16时19分28秒
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
const int N = 1010;
int dp[N][N];
char str[N];
bool sta[N];
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", str);
        int n = strlen(str);
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        int m = 0;
        for (int i = 0; i < n; ++i) {
            if (str[i] != 'E') {
                sta[++m] = (str[i] == 'U'); // U -> 1, D -> 0
            }
        }
        for (int i = 1; i <= m; ++i) {
            if (sta[i] == 0) {
                    for (int j = i; j >= 0; --j) {
                        dp[i][j] += (LL)dp[i - 1][j] * j % mod; //第i个位置留给后面的D
                        if (dp[i][j] >= mod) {
                            dp[i][j] -= mod;
                        }
                        dp[i][j] += (LL)dp[i - 1][j + 1] * (j + 1) % mod * (j + 1) % mod; //第i个位置由前面的U填
                        if(dp[i][j] >= mod) {
                            dp[i][j] -= mod;
                        }
                    }
            }
            else {
                for (int j = 0; j <= i; ++j) {
                    if (j >= 1) {
                        dp[i][j] += dp[i - 1][j - 1];
                        if (dp[i][j] >= mod) {
                            dp[i][j] -= mod;
                        }
                    }
                    if (i - 1 >= j) {
                        dp[i][j] += (LL)dp[i - 1][j] * j % mod;
                        if (dp[i][j] >= mod) {
                            dp[i][j] -= mod;
                        }
                    }
                }
            }
        }
        printf("Case %d: %d\n", icase++, dp[m][0]);
    }
    return 0;
}
