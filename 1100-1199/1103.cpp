/*************************************************************************
    > File Name: LightOJ1103.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年08月19日 星期三 20时34分58秒
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
 
const int N = 200010;
int tree[N];
 
int lowbit(int x) {
    return x & (-x);
}
 
void add(int x, int n) {
    for (int i = x; i <= n; i += lowbit(i)) {
        ++tree[i];
    }
}
 
int sum(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)) {
        ans += tree[i];
    }
    return ans;
}
 
int Arr[N];
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m, id, col;
        scanf("%d%d", &n, &m);
        memset(tree, 0, sizeof(tree));
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &id, &col);
            Arr[id] = col;
        }
        for (int i = 1; i <= m; ++i) {
            scanf("%d%d", &id, &col);
            Arr[id] = col;
        }
        LL ans = 0;
        for (int i = 1; i <= n + m; ++i) {
            ans += i - 1 - sum(Arr[i] - 1);
            add(Arr[i], n + m);
        }
        printf("Case %d: %lld\n", icase++, ans);
    }
    return 0;
}
