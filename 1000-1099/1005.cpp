/*************************************************************************
    > File Name: LightOJ1005.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年06月03日 星期三 21时02分45秒
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
 
LL C[33][33];
 
int main() {
    C[0][0] = 1;
    for (int i = 1; i <= 30; ++i) {
        C[i][0] = C[i][i] = 1;
        C[i][1] = i;
        for (int j = 2; j < i; ++j) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        if (n < k) {
            printf("Case %d: 0\n", icase++);
            continue;
        }
        LL ans = C[n][k] * C[n][k];
        for (int i = 1; i <= k; ++i) {
            ans *= i;
        }
        printf("Case %d: %lld\n", icase++, ans);
    }
    return 0;
}
