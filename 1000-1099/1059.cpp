/*************************************************************************
    > File Name: LightOJ1059.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年07月07日 星期二 21时37分37秒
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
 
const int N = 10010;
const int M = 100010;
 
struct Edge {
    int u, v, w;
    bool operator < (const Edge &b) const {
        return w < b.w;
    }
}edge[M];
 
int fa[N];
 
int Find(int x) {
    if (fa[x] == -1) {
        return x;
    }
    return fa[x] = Find(fa[x]);
}
 
void Kruskal(int C, int n, int m) {
    for (int i = 1; i <= n; ++i) {
        fa[i] = -1;
    }
    int sum = 0;
    sort(edge + 1, edge + m + 1);
    for (int i = 1; i <= m; ++i) {
        int fu = Find(edge[i].u);
        int fv = Find(edge[i].v);
        if (fu != fv) {
            fa[fu] = fv;
            sum += edge[i].w;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (fa[i] == -1) {
            ++cnt;
            sum += C;
        }
    }
    printf("%d %d\n", sum, cnt);
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m, C, u, v, w;
        scanf("%d%d%d", &n, &m, &C);
        int cnt = 0;
        for (int i = 1; i <= m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            if (w < C) {
                edge[++cnt].u = u;
                edge[cnt].v = v;
                edge[cnt].w = w;
            }
        }
        printf("Case %d: ", icase++);
        Kruskal(C, n, cnt);
    }
    return 0;
}
