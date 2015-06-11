/*************************************************************************
    > File Name: LightOJ1027.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年05月17日 星期日 15时23分53秒
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
 
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
 
int main() {
    int t;
    int icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int all = 0;
        int cnt = 0;
        int u;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &u);
            all += abs(u);
            if (u > 0) {
                ++cnt;
            }
        }
        if (!cnt) {
            printf("Case %d: inf\n", icase++);
        }
        else {
            u = gcd(all, cnt);
            printf("Case %d: %d/%d\n", icase++, all/ u, cnt / u);
        }
    }
    return 0;
}
