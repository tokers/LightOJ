/*************************************************************************
    > File Name: LightOJ1021.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年06月09日 星期二 19时45分53秒
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
 
LL dp[(1 << 16) + 10][25];
char str[20];
 
int trans(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    return c - 'A' + 10;
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int base, k;
        scanf("%d%d", &base, &k);
        scanf("%s", str);
        int len = strlen(str);
        for (int i = 0; i < (1 << len); ++i) {
            for (int j = 0; j < k; ++j) {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for (int i = 0; i < (1 << len); ++i) {
            for (int j = 0; j < len; ++j) {
                if (i & (1 << j)) {
                    continue;
                }
                for (int rest = 0; rest < k; ++rest) {
                    if (!dp[i][rest]) {
                        continue;
                    }
                    dp[i | (1 << j)][(rest * base + trans(str[j])) % k] += dp[i][rest];
                }
            }
        }
        printf("Case %d: %lld\n", icase++, dp[(1 << len) - 1][0]);
    }
    return 0;
}
