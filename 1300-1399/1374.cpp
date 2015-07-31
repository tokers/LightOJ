/*************************************************************************
    > File Name: LightOJ1374.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年07月31日 星期五 22时05分36秒
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
 
int cnt[1000100];
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        bool flag = 1;
        memset(cnt, 0, sizeof(cnt));
        int u, n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &u);
            ++cnt[u];
        }
        int en = (n + 1) / 2, s = 1;
        while (s <= en) {
            if (s == en && n % 2) {
                if (cnt[en - 1] == 0) {
                    flag = 0;
                    break;
                }
            }
            if (cnt[s - 1] + cnt[n - s] >= 2) {
                ++s;
            }
            else {
                flag = 0;
                break;
            }
        }
        printf("Case %d: ", icase++);
        if (flag) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }
    return 0;
}
