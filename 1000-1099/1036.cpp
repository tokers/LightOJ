/*************************************************************************
    > File Name: LightOJ1036.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年06月21日 星期日 18时05分18秒
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
 
int mat1[555][555];
int mat2[555][555];
int dp[555][555];
 
int dfs(int x, int y) {
    if (~dp[x][y]) {
        return dp[x][y];
    }
    if (x == 0 || y == 0) {
        return dp[x][y] = 0;
    }
    dp[x][y] = max(dp[x][y], dfs(x - 1, y) + mat1[x][y]);
    dp[x][y] = max(dp[x][y], dfs(x, y - 1) + mat2[x][y]);
    return dp[x][y];
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m, u;
        scanf("%d%d", &n, &m);
        memset(mat1, 0, sizeof(mat1));
        memset(mat2, 0, sizeof(mat2));
        memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%d", &u);
                mat1[i][j] = mat1[i][j - 1] + u;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%d", &u);
                mat2[i][j] = mat2[i - 1][j] + u;
            }
        }
        printf("Case %d: %d\n", icase++, dfs(n, m));
    }
    return 0;
}
