/*************************************************************************
    > File Name: LightOJ1022.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年06月10日 星期三 12时30分00秒
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
        double r;
        scanf("%lf", &r);
        printf("Case %d: %.2f\n", icase++, 4 * r * r - pi * r * r);
    }
    return 0;
}
