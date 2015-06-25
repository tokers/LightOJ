/*************************************************************************
    > File Name: LightOJ1044.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年06月08日 星期一 21时50分30秒
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
 
bool is_par[1010][1010];
int dp[1010];
char str[1010];
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", str);
        int len = strlen(str);
        memset(is_par, 0, sizeof(is_par));
        for (int i = 0; i < len; ++i) {
            is_par[i][i] = 1;
        }
        for (int i = len - 2; i >= 0; --i) {
            for (int j = i + 1; j < len; ++j) {
                if (str[i] == str[j]) {
                    if (j == i + 1) {
                        is_par[i][j] = 1;
                    }
                    else {
                        is_par[i][j] = is_par[i + 1][j - 1];
                    }
                }
            }
        }
        memset(dp, inf, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i <= len; ++i) {
            for (int j = 1; j <= i; ++j) {
                if (is_par[j - 1][i - 1]) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        printf("Case %d: %d\n", icase++, dp[len]);
    }
    return 0;
}
