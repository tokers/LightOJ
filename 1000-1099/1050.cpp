/*************************************************************************
    > File Name: LightOJ1050.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年06月25日 星期四 20时40分38秒
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
 
double dp[555][555][2];
 
double dfs(int x, int y, bool flag) {
    if (flag == 1 && y == 0) {
        return dp[x][y][flag] = 0;
    }
    if (x == 0 && y == 1) {
        return dp[x][y][flag] = 1;
    }
    if (dp[x][y][flag] != -1.0) {
        return dp[x][y][flag];
    }
    if (flag) {
        dp[x][y][flag] = dfs(x, y - 1, flag ^ 1);
    }
    else {
        double ans = 0;
        if (x > 0) {
            ans += dfs(x - 1, y, 1) * (x * 1.0) / (x + y);
        }
        if (y > 0) {
            ans += dfs(x, y - 1, 1) * (y * 1.0) / (x + y);
        }
        return dp[x][y][flag] = ans;
    }
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    for (int i = 0; i <= 500; ++i) {
        for (int j = 0; j <= 500; ++j) {
            dp[i][j][0] = dp[i][j][1] = -1.0;
        }
    }
    while (t--) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (y == 0) {
            printf("Case %d: %.12f\n", icase++, 0.0);
        }
        else {
            printf("Case %d: %.12f\n", icase++, dfs(x, y, 0));
        }
    }
    return 0;
}
