/*************************************************************************
    > File Name: b.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年04月29日 星期三 19时04分23秒
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
 
double dp[110];
int arr[110];
int n;
 
double dfs(int cur) {
    if (dp[cur] != -1.0) {
        return dp[cur];
    }
    double ans = 0;
    int cnt = 0;
    for (int i = 1; i <= 6; ++i) {
        if (cur + i <= n) {
            ++cnt;
        }
    }
    for (int i = 1; i <= 6;  ++i) {
        if (cur + i <= n) {
            ans += (1.0 / cnt) * dfs(cur + i);
        }
    }
    ans += arr[cur];
    dp[cur] = ans;
    return dp[cur];
}
 
int main() {
    int t;
    scanf("%d", &t);
    int icase = 1;
    while (t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &arr[i]);
            dp[i] = -1.0;
        }
        dp[n] = arr[n];
        printf("Case %d: %.12f\n", icase++, dfs(1));
    }
    return 0;
}
