/*************************************************************************
    > File Name: LightOJ1008.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年06月04日 星期四 18时50分14秒
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
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        LL s;
        scanf("%lld", &s);
        int x = sqrt(s * 1.0);
        if ((LL)x * x == s) {
            if (x & 1) {
                printf("Case %d: 1 %d\n", icase++, x);
            }
            else {
                printf("Case %d: %d 1\n", icase++, x);
            }
            continue;
        }
        int i, j;
        if (x & 1) {
            if ((LL)x * x + x + 1 >= s) {
                j = x + 1;
                i = s - (LL)x * x;
            }
            else {
                i = x + 1;
                j =  x + 1 - (s - (LL)x * x - x - 1);
            }
        }
        else {
            if ((LL)x * x + x + 1 >= s) {
                i = x + 1;
                j = x + 1 - ((LL)x * x + x + 1 - s);
            }
            else {
                j = x + 1;
                i = x + 1 - (s - (LL)x * x - x - 1);
            }
        }
        printf("Case %d: %d %d\n", icase++, i, j);
    }
    return 0;
}
