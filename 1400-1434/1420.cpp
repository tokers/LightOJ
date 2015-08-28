/*************************************************************************
    > File Name: LightOJ1420.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年08月27日 星期四 22时35分55秒
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
int dp[105][105][105];
char a[105], b[105], c[105];
vector <int> leta[26], letb[26];
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%s%s%s", a, b, c);
        int na = strlen(a);
        int nb = strlen(b);
        int nc = strlen(c);
        for (int i = 0; i < 26; ++i) {
            leta[i].clear();
            letb[i].clear();
        }
        for (int i = 0; i < na; ++i) {
            leta[a[i] - 'a'].push_back(i + 1);
        }
        for (int i = 0; i < nb; ++i) {
            letb[b[i] - 'a'].push_back(i + 1);
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        int p, ll;
        for (int i = 0; i <= na; ++i) {
            for (int j = 0; j <= nb; ++j) {
                for (int k = 0; k < nc; ++k) {
                    if (!dp[i][j][k]) {
                        continue;
                    }
                    int size = leta[c[k] - 'a'].size();
                    if (i < na) {
                        p = upper_bound(leta[c[k] - 'a'].begin(), leta[c[k] - 'a'].end(), i) - leta[c[k] - 'a'].begin();
                    }
                    else {
                        p = size;
                    }
                    for (int l = p; l < size; ++l) {
                        ll = leta[c[k] - 'a'][l];
                        dp[ll][j][k + 1] += dp[i][j][k];
                        if (dp[ll][j][k + 1] >= mod) {
                            dp[ll][j][k + 1] -= mod;
                        }
                    }
                    size = letb[c[k] - 'a'].size();
                    if (j < nb) {
                        p = upper_bound(letb[c[k] - 'a'].begin(), letb[c[k] - 'a'].end(), j) - letb[c[k] - 'a'].begin();
                    }
                    else {
                        p = size;
                    }
                    for (int l = p; l < size; ++l) {
                        ll = letb[c[k] - 'a'][l];
                        dp[i][ll][k + 1] += dp[i][j][k];
                        if (dp[i][ll][k + 1] >= mod) {
                            dp[i][ll][k + 1] -= mod;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= na; ++i) {
            for (int j = 0; j <= nb; ++j) {
                ans += dp[i][j][nc];
                if (ans >= mod) {
                    ans -= mod;
                }
            }
        }
        printf("Case %d: %d\n", icase++, ans);
    }
    return 0;
}
