/*************************************************************************
    > File Name: LightOJ1159.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年08月18日 星期二 22时27分53秒
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
 
int dp[55][55][55];
char a[55], b[55], c[55];
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        memset(dp, 0, sizeof(dp));
        scanf("%s%s%s", a, b, c);
        int lena = strlen(a);
        int lenb = strlen(b);
        int lenc = strlen(c);
        for (int i = 1; i <= lena; ++i) {
            for (int j = 1; j <= lenb; ++j) {
                for (int k = 1; k <= lenc; ++k) {
                    if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1] && b[j - 1] == c[k - 1]) {
                        dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                    }
                    else {
                        dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
                    }
                }
            }
        }
        printf("Case %d: %d\n", icase++, dp[lena][lenb][lenc]);
    }
    return 0;
}
