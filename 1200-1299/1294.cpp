/*************************************************************************
    > File Name: LightOJ1294.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年07月16日 星期四 13时44分04秒
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
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        LL sum = (LL)n / 2 * m;
        printf("Case %d: %lld\n", icase++, sum);
    }
    return 0;
}
